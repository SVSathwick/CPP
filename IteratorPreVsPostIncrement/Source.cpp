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

class Employee
{
private:
    int id_;
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
    Employee(int id, const string& name) : id_(id), name_(name)
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

int main()
{    
    size_t nOuter = 30000000;
    size_t nInner = 4294967295;

    {
        auto start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < nOuter; ++i)
        {
            vector<Employee*> employees;

            employees.emplace_back(new Employee(1, "Sathwick"));
            employees.emplace_back(new Employee(2, "Sunitha"));
            employees.emplace_back(new Employee(3, "Anshuman"));

            for (size_t ii = 0; ii < nInner; ++ii)
            {
                for (auto it = employees.begin(); it != employees.end(); it++)
                {
                    //(*it)->Print();
                }
            }
            for (auto it : employees)
            {
                delete it;
            }
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(Using it++): " << elapsed.count() << " s\n";
    }
    
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < nOuter; ++i)
        {
            vector<Employee*> employees;

            employees.emplace_back(new Employee(1, "Sathwick"));
            employees.emplace_back(new Employee(2, "Sunitha"));
            employees.emplace_back(new Employee(3, "Anshuman"));

            for (size_t ii = 0; ii < nInner; ++ii)
            {
                for (auto it = employees.begin(); it != employees.end(); ++it)
                {
                    //(*it)->Print();
                }
            }
            for (auto it : employees)
            {
                delete it;
            }
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time(Using ++it): " << elapsed.count() << " s\n";
    }
    
    return 0;
}