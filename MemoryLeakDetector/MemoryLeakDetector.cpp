// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <string>

using namespace std;

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

struct Pod {
    int x;
};

struct Employee
{
    int id_;
    string name_;
    Employee(int id, const string& name)
    {
        id_ = id;
        name_ = name;
    }
};

int main() {
    //Pod* pPod = DBG_NEW Pod;
    //pPod = DBG_NEW Pod; // Oops, leaked the original pPod!
    //delete pPod;

    Pod* pPod = new Pod;
    delete pPod;

    Employee* pEmployee = DBG_NEW Employee(1, "Hi");
    //delete pEmployee;
    cout << "Check Memory Leaks" << endl;
    _CrtDumpMemoryLeaks();

    return 0;
}