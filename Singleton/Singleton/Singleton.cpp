// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include <iostream>
#include <future>
#include <mutex>

constexpr auto tenMill = 10000000;
std::mutex myMutex;

class MySingleton
{
public:
    static MySingleton* getInstance() {      
        
        if (instance == nullptr) {
            std::lock_guard<std::mutex> myLock(myMutex);
            if (instance == nullptr) {
                instance = new MySingleton();
            }
        }

        return instance;
    }
private:
    MySingleton() = default;
    ~MySingleton() = default;
    MySingleton(const MySingleton& rhs) = delete;
    MySingleton& operator=(const MySingleton& rhs) = delete;
    static MySingleton* instance;
};
MySingleton* MySingleton::instance = nullptr;

std::chrono::duration<double> getTime() {

    auto begin = std::chrono::system_clock::now();
    for (size_t i = 0; i <= tenMill; ++i) {
        MySingleton::getInstance();
    }
    return std::chrono::system_clock::now() - begin;

};

int main()
{
    auto fut1 = std::async(std::launch::async, getTime);
    auto fut2 = std::async(std::launch::async, getTime);
    auto fut3 = std::async(std::launch::async, getTime);
    auto fut4 = std::async(std::launch::async, getTime);

    auto total = fut1.get() + fut2.get() + fut3.get() + fut4.get();

    std::cout << total.count() << std::endl;
}