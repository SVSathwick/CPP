#include <iostream>

class Holder {
public:
    Holder(int size) 
    {
        m_Data = new int[size];
        m_Size = size;

        for (int i = size - 1; i >= 0; i--)
        {
            m_Data[i] = i;
        }
    }
    ~Holder() 
    {
        delete[] m_Data;
    }

    Holder(const Holder& other) 
    {
        this->m_Size = other.m_Size;
        this->m_Data = new int[m_Size];
        std::copy(other.m_Data, other.m_Data + m_Size, m_Data);
    }
    Holder& operator=(const Holder& other) 
    {
        if (this->m_Data != other.m_Data) 
        {
            this->m_Size = other.m_Size;
            this->m_Data = new int[m_Size];
            std::copy(other.m_Data, other.m_Data + m_Size, m_Data);
        }
        return *this;
    }

    Holder(Holder&& other) 
    {
        this->m_Data = other.m_Data;
        this->m_Size = other.m_Size;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    Holder& operator=(Holder&& other)
    {
        if (this == &other) return *this;
        delete[] m_Data;

        this->m_Data = other.m_Data;
        this->m_Size = other.m_Size;

        other.m_Size = 0;
        other.m_Data = nullptr;

        return *this;
    }
private:
    int* m_Data;
    int m_Size;
};

int main()
{
    std::cout << "Hello World!\n";

    Holder h1(3);
    Holder h2 = h1;
    Holder h3(h1);

    Holder h4(4);
    h4 = h1;

    Holder h5(5);
    Holder h6(std::move(h5));

    Holder h7(7);
    Holder h8(8);
    h8 = std::move(h7);

    return 0;
}