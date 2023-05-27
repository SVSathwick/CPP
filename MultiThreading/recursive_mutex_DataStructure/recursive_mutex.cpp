#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

class DataStructure
{
    std::recursive_mutex rm;
    std::mutex m;
    int data;
public:
    DataStructure(int const d = 0) : data(d) {}
    void update(int const d)
    {
        cout << "update " << this_thread::get_id() << endl;
        std::lock_guard<std::recursive_mutex> lock(rm);
        //std::lock_guard<std::mutex> lock(m); //this lock fails because this was already locked by update_with_return
        data = d;
        cout << "update - lock acquired " << this_thread::get_id() << endl;
    }
    int update_with_return(int const d)
    {
        cout << "update_with_return " << this_thread::get_id() << endl;
        std::lock_guard<std::recursive_mutex> lock(rm);
        //std::lock_guard<std::mutex> lock(m);
        cout << "update_with_return - lock acquired " << this_thread::get_id() << endl;
        auto temp = data;
        update(d);
        return temp;
    }
    int getData() 
    {
        return data;
    }
};

void fooRecMutex()
{
    DataStructure dataObj(500);
    dataObj.update_with_return(1000);
    cout << "data after update from thread " << dataObj.getData() << endl;
}

class DataStructureEx
{
    std::mutex m;
    int data;

    void internal_update(int const d) { data = d; }

public:
    DataStructureEx(int const d = 0) : data(d) {}

    void update(int const d)
    {
        cout << "update - before lock acquired " << this_thread::get_id() << endl;
        std::lock_guard<std::mutex> lock(m);
        cout << "update - lock acquired " << this_thread::get_id() << endl;
        internal_update(d);
    }

    int update_with_return(int const d)
    {
        cout << "update_with_return - before lock acquired " << this_thread::get_id() << endl;
        std::lock_guard<std::mutex> lock(m);
        cout << "update_with_return - lock acquired " << this_thread::get_id() << endl;
        auto temp = data;
        internal_update(d);
        return temp;
    }
    int getData() { return data; }
};

void fooNonRecMutex()
{   
    DataStructureEx dataObj(500);
    dataObj.update_with_return(1000);
    cout << "data after update from thread " << dataObj.getData() << endl;
}

int main()
{
    {
        std::thread t(fooRecMutex);
        t.join();
    }

    cout << endl;
    {
        std::thread t(fooNonRecMutex);
        t.join();
    }

    return 0;
}
