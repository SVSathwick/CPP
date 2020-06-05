// VTables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Base
{
public:
	virtual void func()
	{
		cout << "Base func" << endl;
	}
	virtual void func1()
	{
		cout << "Base func1" << endl;
	}
	
};

class D1 : public Base
{
public:
	void func1()
	{
		cout << "D1 func1" << endl;
	}
	virtual void func2()
	{
		cout << "D1 func2" << endl;
	}
};

class D2 : public Base
{
public:
	void func1()
	{
		cout << "D2 func1" << endl;
	}
	virtual void func2()
	{
		cout << "D2 func2" << endl;
	}
};

int main()
{
    std::cout << "Hello World!\n";

	Base oBase1;
	Base* pBase = new Base();

	D1 oD1;
	D1* pD1 = new D1();

	D2 oD2;
	D2* pD2 = new D2();

	cout << "END" << endl;
}