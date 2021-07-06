
/**********Item 42: Consider emplacement instead of insertion.**********/




#include <iostream>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n = 3000000;
    for(int i=0; i<5; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<string> words;
        for (int i = 0; i < n; ++i) {
            words.push_back("Hello World");
            
        }

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(push_back): " << elapsed.count() << " s\n";

        //Elapsed time(push_back) : 21.1901 s
        //Elapsed time(push_back) : 21.9834 s
        //Elapsed time(push_back) : 20.4371 s
        //Elapsed time(push_back) : 21.0789 s
        //Elapsed time(push_back) : 21.6639 s
    }

    for (int i = 0; i < 5; ++i)
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<string> words;
        for (int i = 0; i < n; ++i) {
            words.emplace_back("Hello World");

        }

        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(emplace_back): " << elapsed.count() << " s\n";

        //Elapsed time(emplace_back) : 16.6638 s
        //Elapsed time(emplace_back) : 16.4791 s
        //Elapsed time(emplace_back) : 17.7084 s
        //Elapsed time(emplace_back) : 16.4768 s
        //Elapsed time(emplace_back) : 16.1155 s
    }
}