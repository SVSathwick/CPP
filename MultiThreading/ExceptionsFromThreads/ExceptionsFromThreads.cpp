#include <iostream>
#include <vector>
#include <exception>
#include <thread>
#include <mutex>
#include <list>
#include <memory>
#include <string>
#include <sstream>

using namespace std;

std::vector<std::exception_ptr> g_exceptions;
std::mutex g_mutex;

void func1()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    throw std::runtime_error("exception in func1, thread id: " + ss.str());
}
void func2()
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    throw std::runtime_error("exception in func2, thread id: " + ss.str());
}

void thread_func1(std::vector<std::exception_ptr>& exceptionsOut)
{
    try
    {
        func1();
    }
    catch (...)
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        //g_exceptions.push_back(std::current_exception());
        exceptionsOut.push_back(std::current_exception());
    }
}
void thread_func2(std::vector<std::exception_ptr>& exceptionsOut)
{
    try
    {
        func2();
    }
    catch (...)
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        //g_exceptions.push_back(std::current_exception());
        exceptionsOut.push_back(std::current_exception());
    }
}

int main()
{
    g_exceptions.clear();
    std::vector<std::exception_ptr> t1_exceptions;
    std::thread t1(thread_func1, std::ref(t1_exceptions));

    std::vector<std::exception_ptr> t2_exceptions;
    std::thread t2(thread_func2, std::ref(t2_exceptions));
    t1.join();
    t2.join();

    /*for (const auto& e : g_exceptions) {
        try {
            if (e != nullptr) {
                std::rethrow_exception(e);
            }
        }
        catch(const std::exception& ex){
            std::cout << ex.what() << '\n' << endl;
        }
    }*/
    for (const auto& e : t1_exceptions) {
        try {
            if (e != nullptr) {
                std::rethrow_exception(e);
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << '\n' << endl;
        }
    }
    for (const auto& e : t2_exceptions) {
        try {
            if (e != nullptr) {
                std::rethrow_exception(e);
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << '\n' << endl;
        }
    }
}