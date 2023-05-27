#include <thread>
#include <mutex>
#include <memory>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <chrono>

using namespace std;

int g_i = 0;
std::mutex g_i_mutex;  // protects g_i

void printThreadId()
{
    std::cout << std::this_thread::get_id() << endl;
}

void safeIncrement()
{
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;

    std::cout << "g_i: " << g_i << "; in thread #" << std::this_thread::get_id() << '\n';
    std::cout << "g_i: " << g_i << "; in thread #";
    printThreadId();

    // g_i_mutex is automatically released when lock goes out of scope
}


int main()
{
    std::cout << "g_i: " << g_i << "; in main()\n";

    std::thread t1(safeIncrement);
    std::thread t2(safeIncrement);

    t1.join();
    t2.join();

    std::cout << "g_i: " << g_i << "; in main()\n";

    unique_ptr<int> upInt(new int(10));
    cout << *upInt << endl;
	
}