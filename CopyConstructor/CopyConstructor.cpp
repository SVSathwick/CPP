
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Contact
{
public:
	char* name;
	int age;
public:
	Contact(const char* inName, int inAge)
	{
		name = new char[strlen(inName) + 1];
		strcpy_s(name, strlen(inName) + 1, inName);
		age = inAge;
		printf("Constructor called for %s, add: %p\n", name, this);
	}
	~Contact() { 
		printf("Destructor called for %s, add: %p \n", name, this);
		delete[] name; 
	}

	Contact(const Contact& rhs)
	{
		name = new char[strlen(rhs.name) + 1];
		strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
		age = rhs.age;

		printf("Copy Constructor called for %s, add: %p\n", name, this);
	}

	//return  type should be of ref because the return statement will end up 
	//in calling copy constructor -  unnecessary
	Contact& operator=(const Contact& rhs) {
		char* tempName = new char[strlen(rhs.name) + 1];
		delete[] name;
		name = tempName;
		strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
		age = rhs.age;

		printf("Assignment Operator called for %s\n", name);
		return *this;
	}

	/*Contact operator=(const Contact& rhs) {
		char* tempName = new char[strlen(rhs.name) + 1];
		delete[] name;
		name = tempName;
		strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
		age = rhs.age;

		printf("Assignment Operator called for %s, add: %p\n", name, this);
		return *this;
	}*/
};

vector<Contact> sortByAge(vector<Contact>& contacts) {

	std::sort(contacts.begin(), contacts.end(), 
		[](const Contact& cont1, const Contact& cont2)
		{
			return (cont1.age < cont2.age);
		}
	);
	return contacts;
}

int main()
{
	/*{
		Contact c1("Sathwick", 34);
		Contact c2("Sunitha", 30);
		Contact c3("Anshuman", 2);

		c1 = c2 = c3;

		char name[10] = { "SathwickS" };
		Contact sathwick(name, 34);
		Contact sathwickCpy(sathwick);
		Contact sathwickCpy2 = sathwick;
	}*/
	
	/*{
		vector<Contact> contacts;
		Contact sathwick("Sathwick", 37);
		Contact sunitha("Sunitha", 33);
		Contact anshuman("Anshuman", 5);
		Contact chaitra("Chaitra", 1);
		contacts.push_back(sathwick);
		contacts.push_back(anshuman);
		contacts.push_back(sunitha);
		contacts.push_back(chaitra);
	
		auto sortedContacts = sortByAge(contacts);
		for (const auto& it : sortedContacts) {
			printf("name: %s, age: %d\n", it.name, it.age);
		}
	}*/

	//Tesing copy assignment operator
	{
		Contact sathwick("sathwick", 37);
		Contact venkata("Venkata", 38);
		venkata = sathwick;

		cout << "STOP HERE" << endl;
	}
	

	return 0;
}
