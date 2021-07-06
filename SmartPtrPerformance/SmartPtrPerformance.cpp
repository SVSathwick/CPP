#include <iostream>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class SomeLargeData 
{
public:
    SomeLargeData(int id, string name) : id(id), name(name)
    {
    }

    int id;
    string name;

    void print()
    {
        cout << "id: " << id << endl;
    }
    ~SomeLargeData(){
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
    //for(int i=0; i<5; ++i)
    //{   
    //    auto start = std::chrono::high_resolution_clock::now();

    //    vector<SomeLargeData> vec_byval;
    //    for (int i = 0; i < n; ++i) {
    //        int id = rand() % 500000;
    //        SomeLargeData somelargeData(id);
    //        vec_byval.push_back(somelargeData);
    //        //vec_byval.push_back(SomeLargeData(id));
    //    }

    //    sort(vec_byval.begin(), vec_byval.end(), compare_by_value);
    //    auto finish = std::chrono::high_resolution_clock::now();
    //    std::chrono::duration<double> elapsed = finish - start;
    //    std::cout << "Elapsed time(Stored as value): " << elapsed.count() << " s\n";

    //    /*Elapsed time(Stored as value) : 4.96255 s
    //    Elapsed time(Stored as value) : 5.39704 s
    //    Elapsed time(Stored as value) : 5.01578 s
    //    Elapsed time(Stored as value) : 5.34223 s
    //    Elapsed time(Stored as value) : 5.2187 s*/
    //}

    //for (int i = 0; i < 5; ++i)
    //{
    //    auto start = std::chrono::high_resolution_clock::now();

    //    vector<SomeLargeData*> vec_byptr;        
    //    for (int i = 0; i < n; ++i) {
    //        int id = rand() % 500000;
    //        SomeLargeData* pSomeLargeData = new SomeLargeData(id);
    //        vec_byptr.push_back(pSomeLargeData);
    //        //vec_byptr.push_back(new SomeLargeData(id));
    //    }

    //    sort(vec_byptr.begin(), vec_byptr.end(), compare_by_ptr);
    //    for (auto it : vec_byptr) {
    //        delete it;
    //    }

    //    auto finish = std::chrono::high_resolution_clock::now();
    //    std::chrono::duration<double> elapsed = finish - start;
    //    std::cout << "Elapsed time(Stored as ptr): " << elapsed.count() << " s\n";
    //    

    //   /*Elapsed time : 4.43199 s
    //    Elapsed time : 4.20114 s
    //    Elapsed time : 3.95741 s
    //    Elapsed time : 3.98154 s
    //    Elapsed time : 5.23639 s*/
    //}

    for (int i = 0; i < 5; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<unique_ptr<SomeLargeData>> vec_byuniqptr;
        for (int i = 0; i < n; ++i) 
        {
            //int id = rand() % 500000;
            unique_ptr<SomeLargeData> pSomeLargeData(new SomeLargeData(i, "Sathwick"));
            //vec_byuniqptr.push_back(std::move(pSomeLargeData));
            //vec_byuniqptr.push_back(unique_ptr<SomeLargeData>(new SomeLargeData(id)));
            vec_byuniqptr.emplace_back(std::move(pSomeLargeData));            
        }

        //This code is just for checking usage of unique_ptr from a container
        /*cout << "Before" << endl;
        for (auto& it : vec_byuniqptr)
        {
            it->print();
        }*/

        //sort(vec_byuniqptr.begin(), vec_byuniqptr.end(), compare_by_uniqptr);

        //This code is just for checking usage of unique_ptr from a container
        /*cout << "\nAfter" << endl;
        for (const auto& it : vec_byuniqptr)
        {
            it->print();
        }*/

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(Stored as unique_ptr): " << elapsed.count() << " s\n";

        //Elapsed time : 9.108 s
        //Elapsed time : 8.1227 s
        //Elapsed time : 8.69799 s
        //Elapsed time : 8.331 s
        //Elapsed time : 8.99747 s
    }

    
	//for (int i = 0; i < 5; ++i)
	//{
	//	auto start = std::chrono::high_resolution_clock::now();
	//	vector<shared_ptr<SomeLargeData>> vec_bySharedptr;

	//	for (int i = 0; i < n; ++i) {
	//		int id = rand() % 500000;
	//		shared_ptr<SomeLargeData> pLargeDate(new SomeLargeData(i));
	//		//vec_bySharedptr.push_back(pLargeDate);
 //           //vec_bySharedptr.push_back(shared_ptr<SomeLargeData>(new SomeLargeData(id)));
 //           vec_bySharedptr.emplace_back(pLargeDate);
	//	}
 //    
	//	sort(vec_bySharedptr.begin(), vec_bySharedptr.end(), compare_by_Sharedptr);
 //    
	//	auto finish = std::chrono::high_resolution_clock::now();
	//	std::chrono::duration<double> elapsed = finish - start;
	//	std::cout << "Elapsed time(Stored as shared_ptr): " << elapsed.count() << " s\n";

	//	//Elapsed time : 12.312 s
	//	//Elapsed time : 11.9436 s
	//	//Elapsed time : 12.2714 s
	//	//Elapsed time : 11.7958 s
	//	//Elapsed time : 11.5406 s
	//}

    return 0;
}