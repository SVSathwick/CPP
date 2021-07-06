#include <iostream>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

class SomeLargeData
{
public:
    SomeLargeData(int id_) : id(id_)
    {
        for (int i = 0; i < 100; i++)
        {
            arr[i] = i;
        }
        deptId = 100;
        salary = 1000;
        somethingBIGINT = 10088983;
        name = "Sathwick";
    }

    int id;
    int arr[100];
    int deptId;
    int salary;
    long somethingBIGINT;
    string name;

    void print()
    {
        cout << "id: " << id << endl;
    }
    ~SomeLargeData() {
        //cout << "Destructor" << endl;
    }
};

bool compare_by_value(const SomeLargeData& a, const SomeLargeData& b)
{
    return a.id < b.id;
}

bool compare_by_ptr(const SomeLargeData* a, const SomeLargeData* b)
{
    return a->id < b->id;
}

bool compare_by_uniqptr(const unique_ptr<SomeLargeData>& a, const unique_ptr<SomeLargeData>& b) {
    return a->id < b->id;
}

bool compare_by_Sharedptr(const shared_ptr<SomeLargeData>& a, const shared_ptr<SomeLargeData>& b) {
    return a->id < b->id;
}

int main()
{
    int n = 3000000;    
    for (int i = 0; i < 5; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<unique_ptr<SomeLargeData>> vec_byuniqptr;
        for (int i = 0; i < n; ++i)
        {
            int id = rand() % 500000;
            unique_ptr<SomeLargeData> pSomeLargeData(new SomeLargeData(id));
            //vec_byuniqptr.push_back(std::move(pSomeLargeData));
            //vec_byuniqptr.push_back(unique_ptr<SomeLargeData>(new SomeLargeData(id)));
            vec_byuniqptr.emplace_back(std::move(pSomeLargeData));
        }
        //sort(vec_byuniqptr.begin(), vec_byuniqptr.end(), compare_by_uniqptr);

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(Stored in a vector and sorted): " << elapsed.count() << " s\n";
    }


    for (int i = 0; i < 5; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();

        list<unique_ptr<SomeLargeData>> list_byuniqptr;
        for (int i = 0; i < n; ++i)
        {
            int id = rand() % 500000;
            unique_ptr<SomeLargeData> pSomeLargeData(new SomeLargeData(id));
            //vec_byuniqptr.push_back(std::move(pSomeLargeData));
            //vec_byuniqptr.push_back(unique_ptr<SomeLargeData>(new SomeLargeData(id)));
            list_byuniqptr.emplace_back(std::move(pSomeLargeData));
        }
        //sort(list_byuniqptr.begin(), list_byuniqptr.end(), compare_by_uniqptr);

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(Stored in a list and sorted): " << elapsed.count() << " s\n";
    }

    return 0;
}