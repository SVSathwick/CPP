#include <iostream>
#include<vector>
#include<iterator>
#include <list>

using namespace std;

class Employee {
public:
	int id;
	string name;
	double salary;
	Employee() {
		id = 10;
		name = "Sathwick";
		salary = 10000;
	}
};

int main()
{
	{
		cout << "VECTOR " << endl;
		//Declaring a Vector
		vector<int> v{ 1,2,3,4,5,6,7,8 };
		cout << "Before Insert ";
		for (auto it = v.begin(); it != v.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		//Declaring Iterator
		vector<int>::iterator i;
		//Function
		v.insert(v.begin() + 1, 10);
		cout << "After Insert ";
		for (i = v.begin(); i != v.end(); i++) {
			cout << *i << " ";
		}
		cout << endl;

		//normal iterator
		{
			vector<int>::iterator it = v.begin();
			for (; it != v.end(); ++it) {
				*it = *it * 2;
			}
			for (auto it : v) {
				cout << it << " ";
			}
			cout << endl;
		}

		//const iterator
		{
			vector<int>::const_iterator cIt = v.begin();
			for (; cIt != v.end(); ++cIt) {
				//*cIt = *cIt * 2; //compiler error
				cout << *cIt << " ";
			}
			cout << endl;
		}

		//reverse iterator
		{
			vector<int>::reverse_iterator cIt = v.rbegin();
			for (; cIt != v.rend(); ++cIt) {
				*cIt = *cIt * 2;
				//cout << *cIt << " ";
			}
			for (auto it : v) {
				cout << it << " ";
			}
			cout << endl;
		}
	}

	{
		cout << "LIST " << endl;
		//Declaring a Vector
		list<int> l{ 1,2,3,4,5,6,7,8 };
		cout << "Before Insert ";
		for (auto it = l.begin(); it != l.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		//Declaring Iterator
		list<int>::iterator it = l.begin();
		++it;
		//Function
		l.insert(it, 10);
		cout << "After Insert ";
		for (auto i = l.begin(); i != l.end(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}

	{
		vector<Employee> emps;
		emps.push_back(Employee());
		emps.push_back(Employee());
		emps.push_back(Employee());
		emps.push_back(Employee());
		emps.push_back(Employee());
		
		for (auto it : emps) {
			cout << it.id << endl;
		}

		vector<Employee*> pEmps;
		pEmps.push_back(new Employee());
		pEmps.push_back(new Employee());
		pEmps.push_back(new Employee());
		pEmps.push_back(new Employee());
		pEmps.push_back(new Employee());
		cout << "using auto it : pEmps" << endl;
		for (auto it : pEmps) {
			cout << it->name << endl;
		}
		
		cout << "using auto it : pEmps.begin()" << endl;
		for (auto it = pEmps.begin(); it != pEmps.end(); ++it) {
			cout << (*it)->id << " " << (*it)->name << endl;
		}
	}

	
	return 0;
}