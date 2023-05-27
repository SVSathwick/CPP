#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <memory>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    std::cout << std::thread::hardware_concurrency() << endl;
}