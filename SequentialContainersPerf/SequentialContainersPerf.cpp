#include <thread>
#include <mutex>
#include <memory>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <deque>
#include <list>
#include <fstream>

using namespace std;

class Employee
{
private:
    size_t id_;
    string name_;
    string dept_;
    int salary_;
    string street1_;
    string street2_;
    string city_;
    string state_;
    string country_;
    int zipCode_;
    string mobile_;
    string homePhone_;
    string emailId_;
    int age_;
    string insuranceId1_;
    string insuranceId2_;
    string employer_;
    string designation_;

public:
    Employee(size_t id, const string& name) : id_(id), name_(name)
    {
        dept_ = "Research and Developmet";
        salary_ = 100000;
        street1_ = "Demo Street1";
        street2_ = "Demo Street2";
        city_ = "Atlanta";
        state_ = "GA";
        country_ = "USA";
        zipCode_ = 30339;
        mobile_ = "5684711122";
        homePhone_ = "4565587568";
        emailId_ = "noreply@example.com";
        age_ = 36;
        insuranceId1_ = "123456789";
        insuranceId2_ = "333666999";
        employer_ = "Carestream Dental Inc";
        designation_ = "Software Engineer";
    }
    void Print() { cout << "id: " << id_ << ", name: " << name_ << endl; }
};

void insertIntoVector(int loops, size_t size)
{
    
    auto start = chrono::high_resolution_clock::now();
    for (int k = 0; k < loops; k++)
    {
        vector<unique_ptr<Employee>> employees;
        for (size_t i = 0; i < size; ++i)
        {
            employees.emplace_back(unique_ptr<Employee>(new Employee(i, "Sathwick")));
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Using Vector - Elapsed time for insertion: " << elapsed.count() << "s\n";
    
}

void insertIntoVectorRes(int loops, size_t size)
{
    auto start = chrono::high_resolution_clock::now();
    for (int k = 0; k < loops; k++)
    {
        vector<unique_ptr<Employee>> employees;
        employees.reserve(size);
        for (size_t i = 0; i < size; ++i)
        {
            employees.emplace_back(unique_ptr<Employee>(new Employee(i, "Sathwick")));
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Using Vector(using reserve) - Elapsed time for insertion: " << elapsed.count() << "s\n";
}

void insertIntoList(int loops, size_t size)
{
    auto start = chrono::high_resolution_clock::now();
    for (int k = 0; k < loops; k++)
    {
        list<unique_ptr<Employee>> employees;
        for (size_t i = 0; i < size; ++i)
        {
            employees.emplace_back(unique_ptr<Employee>(new Employee(i, "Sathwick")));
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Using list - Elapsed time for insertion: " << elapsed.count() << "s\n";
}

void insertIntoDeque(int loops, size_t size)
{
    auto start = chrono::high_resolution_clock::now();
    for (int k = 0; k < loops; k++)
    {
        deque<unique_ptr<Employee>> employees;
        for (size_t i = 0; i < size; ++i)
        {
            employees.emplace_back(unique_ptr<Employee>(new Employee(i, "Sathwick")));
        }
    }
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Using deque - Elapsed time for insertion: " << elapsed.count() << "s\n";
}

int main()
{
    int loops = 10;
    size_t size = 5000000;

    insertIntoDeque(loops, size);
    insertIntoList(loops, size);
    insertIntoVectorRes(loops, size);
    insertIntoVector(loops, size);

    getchar();
    return 0;
}