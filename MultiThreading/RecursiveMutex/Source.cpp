#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

mutex g_mutex;
recursive_mutex g_rMutex;

void funcRecMutex(int size)
{
    //lock_guard<mutex> lock(g_mutex); //This will result in a crash because recursive call will fail because its already locked
    lock_guard<recursive_mutex> lock(g_rMutex);
    cout << size << " ";
    if (size > 0)
    {
        size--;
        funcRecMutex(size);        
    }
}

class TestRecMutex
{
private:
    mutex mutex_;
    recursive_mutex recMutex_;
public:
    void foo() 
    {
        //lock_guard<mutex> lock(mutex_); //this will result in crash because goo will try to acquire lock but couldn't because lock has been already acquired in foo;
        lock_guard<recursive_mutex> lock(recMutex_);
        cout << "foo" << endl;
        goo();
    }

    void goo()
    {
        //lock_guard<mutex> lock(mutex_);
        lock_guard<recursive_mutex> lock(recMutex_);
        cout << "goo" << endl;
    }
};

int main()
{
    /*for (int i = 10; i < 15; i++)
    {
        Rec* pRec = new Rec(1);
        thread thread1(&Rec::update, pRec, i);
        thread1.join();

        Rec* pRec2 = new Rec(2);
        thread thread2(&Rec::update_with_return, pRec, i*2);
        thread2.join();
    }*/
    
    //funcRecMutex(10);

    TestRecMutex testRecMutex;
    thread thread1(&TestRecMutex::foo, &testRecMutex);    
    thread1.join();
    thread thread2(&TestRecMutex::goo, &testRecMutex);
    thread2.join();

    
}