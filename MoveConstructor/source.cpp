#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

class MemoryBlock
{
public:

    // Simple constructor that initializes the resource.
    explicit MemoryBlock(size_t length)
        : _length(length)
        , _data(new int[length])
    {
        std::cout << "Constructor. length = "
            << _length << "." << std::endl;
    }

    // Destructor.
    ~MemoryBlock()
    {
        std::cout << "Destructor. length = "
            << _length << ".";

        if (_data != nullptr)
        {
            std::cout << " Deleting resource.";
            // Delete the resource.
            delete[] _data;
        }

        std::cout << std::endl;
    }

    // Copy constructor.
    MemoryBlock(const MemoryBlock& other)
        : _length(other._length)
        , _data(new int[other._length])
    {
        std::cout << "In Copy Constructor length = "
            << other._length << std::endl;

        std::copy(other._data, other._data + _length, _data);
    }

    // Copy assignment operator.
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        std::cout << "In Assignment Operator length = "
            << other._length << std::endl;

        if (this != &other)
        {
            // Free the existing resource.
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }

     // Move constructor.
     MemoryBlock(MemoryBlock&& other) noexcept
     : _data(nullptr)
     , _length(0)
     {
         std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                     << other._length << ". Moving resource." << std::endl;

         // Copy the data pointer and its length from the
         // source object.
         _data = other._data;
         _length = other._length;

         // Release the data pointer from the source object so that
         // the destructor does not free the memory multiple times.
         other._data = nullptr;
         other._length = 0;
     }

     // Move assignment operator.
     MemoryBlock& operator=(MemoryBlock&& other) noexcept
     {
         std::cout << "In operator=(MemoryBlock&&). length = "
                     << other._length << "." << std::endl;

         if (this != &other)
         {
             // Free the existing resource.
             delete[] _data;

             // Copy the data pointer and its length from the
             // source object.
             _data = other._data;
             _length = other._length;

             // Release the data pointer from the source object so that
             // the destructor does not free the memory multiple times.
             other._data = nullptr;
             other._length = 0;
         }
         return *this;
     }

    // Retrieves the length of the data resource.
    size_t Length() const
    {
        return _length;
    }

private:
    size_t _length; // The length of the resource.
    int* _data; // The resource.
};

int main()
{
    vector<MemoryBlock> v;

    // Create a vector object and add a few elements to it.
    {
        cout << "\nPART-1\n" << endl;        
        //by default Move Constructor called if it is overriden, otherwise Copy Constructor gets called
        v.push_back(MemoryBlock(25));  
        v.push_back(MemoryBlock(75));
        MemoryBlock mb25(25);
        MemoryBlock mb75(75);
        v.push_back(mb25);
        v.push_back(mb75);

        MemoryBlock mb1(1);
        MemoryBlock mb2(mb1);
    }

    {
        cout << "\nPART-2\n" << endl;
        vector<MemoryBlock> v;
        //Even if we explicitly call std::move, runtime calls Copy Constructor
		//Copy Constructor gets called if there is no Move Constructor defined for the class
        v.push_back(std::move(MemoryBlock(10)));
        v.push_back(std::move(MemoryBlock(20)));
    }

    {
        cout << "\nPART-3\n" << endl;
        //vector<MemoryBlock> v;
        //Insert a new element into the second position of the vector.
        v.insert(v.begin() + 1, MemoryBlock(50));
        MemoryBlock mb1(100);
        MemoryBlock mb2 = std::move(mb1);
        MemoryBlock mb3(300);

        //Ideally Move Assignment operator gets called, 
        //Copy assignment gets called if Move Assignment is not defined
        mb3 = std::move(mb2); 

        cout << "\nPART-4\n";
        /*Move Constructor is not required for pointer types. 
        When we call std::move, the lhs pointer will point to the address of the rhs pointer. 
        Same as assignment. Both will point to the same address location
        So Move Constructor and Move assignment are important in case of objects created in stack
        This is similar to Copy Constructor and Copy Assignment operator    */
        MemoryBlock* pMb1 = new MemoryBlock(200);
        MemoryBlock* pMb2 = std::move(pMb1);
        MemoryBlock* pMb3 = new MemoryBlock(300);
        pMb3 = std::move(pMb2);
        delete pMb3;

        cout << "\nPART-5\n";
        unique_ptr<MemoryBlock> upMb1(new MemoryBlock(500));
        //unique_ptr<MemoryBlock> upMb2 = upMb1; //we can't do this because Copy Assignment was deleted by the compiler -- Best Practice
        unique_ptr<MemoryBlock> upMb2 = std::move(upMb1); //Now the upMb2 holds the address and upMb1 holds nothing
    }
    

    return 0;
}