#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class Customer
{
public:
	Customer(const int& id, const string& name):_id(id), _name(name)
	{
		cout << "Constrctor for " << _name.c_str() << endl;
	}
	~Customer()
	{
		cout << "Destructor for " << _name.c_str() << endl;
	}
public:
	int _id;
	string _name;
};

int main() 
{	
	vector<unique_ptr<Customer>> customers;
	customers.reserve(10);
	customers.push_back(make_unique<Customer>(1, "Sathwick"));
	customers.push_back(make_unique<Customer>(2, "Sunitha"));
	customers.push_back(make_unique<Customer>(3, "Anshuman"));
	customers.push_back(make_unique<Customer>(4, "Chaitra"));
	customers.push_back(make_unique<Customer>(5, "Alex"));
	customers.push_back(make_unique<Customer>(6, "Glen"));
	customers.push_back(make_unique<Customer>(7, "Steve"));
	customers.push_back(make_unique<Customer>(8, "Nina"));
	customers.push_back(make_unique<Customer>(9, "Pam"));
	customers.push_back(make_unique<Customer>(10, "Shabiki"));

	//using for to loop all items
	/*{
		cout << "Printing all customers details: " << endl;
		for (const auto& it : customers)
		{
			cout << "Customer Id: " << it->_id << ", name: " << it->_name.c_str() << endl;
		}

		cout << "Printing all customers details in reverse order: " << endl;
		for (auto it = customers.rbegin(); it != customers.rend(); ++it)
		{
			cout << "Customer Id: " << (*it)->_id << ", name: " << (*it)->_name.c_str() << endl;
		}
	}

	//range based for
	{
		cout << "Range based for " << endl;
		cout << "Printing first 5 customers details: " << endl;		
		for (auto it = customers.begin(); it != customers.begin() + 5; ++it)
		{
			cout << "Customer Id: " << (*it)->_id << ", name: " << (*it)->_name.c_str() << endl;
		}

		cout << "Printing 6-end customers details: " << endl;
		for (auto it = customers.begin()+5; it != customers.end(); ++it)
		{
			cout << "Customer Id: " << (*it)->_id << ", name: " << (*it)->_name.c_str() << endl;
		}

		cout << "Printing last 5 customers details in reverse order: " << endl;
		for (auto it = customers.rbegin(); it != customers.rbegin() + 5; ++it)
		{
			cout << "Customer Id: " << (*it)->_id << ", name: " << (*it)->_name.c_str() << endl;
		}

		cout << "Printing first 5 customers details in reverse order: " << endl;
		for (auto it = customers.rbegin() + 5; it != customers.rend(); ++it)
		{
			cout << "Customer Id: " << (*it)->_id << ", name: " << (*it)->_name.c_str() << endl;
		}
	}*/

	//using for_each
	{
		cout << "Printing all customers details using for_each: " << endl;
		for_each(customers.begin(), customers.end(), [](const auto& customer) {
				cout << "Customer Id: " << customer->_id << ", name: " << customer->_name.c_str() << endl;
			});
	}

	cout << "Printing first 5 customers details using for_each: " << endl;
	for_each(customers.begin(), customers.begin() + 5, [](const auto& customer) {
		cout << "Customer Id: " << customer->_id << ", name: " << customer->_name.c_str() << endl;
		});

	return 0;
}