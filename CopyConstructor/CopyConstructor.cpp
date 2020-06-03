
#include <iostream>
#include <string>

using namespace std;

class Contact
{
	char* name;
	int age;
public:
	Contact(const char* inName, int inAge)
	{
		name = new char[strlen(inName) + 1];
		strcpy_s(name, strlen(inName) + 1, inName);
		age = inAge;
	}
	~Contact() { delete[] name; }

	Contact(const Contact& rhs)
	{
		name = new char[strlen(rhs.name) + 1];
		strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
		age = rhs.age;
	}

	Contact& operator=(const Contact& rhs) {
		char* tempName = new char[strlen(rhs.name) + 1];
		delete[] name;
		name = tempName;
		strcpy_s(name, strlen(rhs.name) + 1, rhs.name);
		age = rhs.age;
		return *this;
	}
};

int main()
{
	Contact c1("Sathwick", 34);
	Contact c2("Sunitha", 30);
	Contact c3("Anshuman", 2);

	c1 = c2 = c3;

	char name[10] = { "SathwickS" };
	Contact sathwick(name, 34);
	Contact sathwickCpy(sathwick);
	Contact sathwickCpy2 = sathwick;

	return 0;
}
