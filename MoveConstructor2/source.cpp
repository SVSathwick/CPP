/**********Item 42: Consider emplacement instead of insertion.**********/
#include <iostream>
#include <cstdlib>
#include <memory>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class MyClass {
public:
    MyClass(int x, const string& name) : x_(x), name_(name) {
        cout << "Constructing " << name_ << endl;
    }

    ~MyClass() {
        cout << "Destroying " << name_ << endl;
    }

    // Copy Constructor
    MyClass(const MyClass& rhs) {        
        x_ = rhs.x_;
        name_ = rhs.name_;
        cout << "Copy Constructor for " << name_ << endl;
    }

    // Move Constructor
    MyClass(MyClass&& rhs) noexcept {        
        x_ = move(rhs.x_);
        name_ = move(rhs.name_);
        cout << "Move Constructor for " << name_ << endl;
    }

private:
    int x_ = 0;
    string name_;
};

int main()
{
    //push_back
    {
        std::vector<MyClass> v;
        //push_back calls Move Constructor here
        //if Move Constructor is not defined, Copy Constructor gets called - performance penalty
        v.push_back(MyClass(1, "Sathwick"));
    }

    //emplace_back
    {
        //emplace_back calls Move Constructor here
        //if Move Constructor is not defined, Copy Constructor gets called - performance penalty
        std::vector<MyClass> v;
        v.emplace_back(MyClass(1, "Sathwick"));
    }

    {
        MyClass obj1(1, "Venkata");
        MyClass obj2(obj1);        
    }

    {
        MyClass obj1(1, "Sivvala");
        //std::move calls Move Constructor here
        //if Move Constructor is not defined, Copy Constructor gets called - performance penalty
        MyClass obj2 = std::move(obj1);
    }

    return 0;
}