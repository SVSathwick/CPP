#include <iostream>
#include <string>
#include "Employee.h"
#include <memory>

using namespace std;

void printPassByConstRef(const std::string& str)
{
	cout << str.c_str() << endl;
	//str = "Pass By Const Ref"; //compilation error
}
void printPassByRef(std::string& str)
{
	cout << str.c_str() << endl;
	str = "Pass By Ref";
}

void printPassByConstPtr(const std::string* pStr)
{
	cout << pStr->c_str() << endl;
	//*pStr = "Pass By Ptr"; //Compilation error
}

void printPassByPtr(std::string* pStr)
{
	cout << pStr->c_str() << endl;
	*pStr = "Pass By Ptr";
}

void printPassByVal(std::string str)
{
	cout << str.c_str() << endl;
}

void passByPtr(std::string* pStr)
{
	std::string* pStrLocal = new string("Venkata");
	cout << "Address of pStrLocal " << pStrLocal << ", Content: " << pStrLocal->c_str() << endl;
	pStr = pStrLocal; // This assignment is local here, once pStr leaves this method it points back to 
					  // the address to which it was pointing earlier
	*pStr = "Anshuman"; 
	cout << "Address of pStr " << pStr << ", Content: " << pStr->c_str() << endl;
	cout << "Address of pStrLocal " << pStrLocal << ", Content: " << pStrLocal->c_str() << endl;
}

void passByPtr1(std::string* pStr)
{
	std::string* pStrLocal = new string("Venkata");
	cout << "Address of pStrLocal " << pStrLocal << ", Content: " << pStrLocal->c_str() << endl;
	pStrLocal = pStr;
	*pStr = "Sivvala"; //Now the the contents of pStr will be applied to the address it is pointing
	cout << "Address of pStr " << pStr << ", Content: " << pStr->c_str() << endl;
	cout << "Address of pStrLocal " << pStrLocal << ", Content: " << pStrLocal->c_str() << endl;
}

int main()
{
	/*std::string name("Sathwick");
	printPassByVal(name);
	printPassByConstRef(name);
	printPassByRef(name);
	printPassByConstPtr(&name); 
	printPassByPtr(&name);
	cout << "Final result: " << name.c_str() << endl;*/

	//std::string* pStr = new std::string("Sathwick");
	//cout << "Address of pStr " << pStr << ", Content: " << pStr->c_str() << endl;
	///*passByPtr(pStr);
	//cout << "Address of pStr " << pStr << ", Content: " << pStr->c_str() << endl;*/
	//passByPtr1(pStr);
	//cout << "Address of pStr " << pStr << ", Content: " << pStr->c_str() << endl;

	//const X* p means “p points to an X that is const”: the X object can’t be changed via p.
	/*{
		unique_ptr<Employee> pEmp(new Employee(1, "Sathwick", "Software Architect"));

		pEmp->printName();
		pEmp->printDesignation();
		pEmp->printDetails(); //this calls non-const printDetails because pEmp is a non-const object

		const Employee* pEmp1 = pEmp.get();
		//pEmp1->printName(); //printName is a non-const method, so we can't call this from a const object
		pEmp1->printDesignation();
		pEmp1->printDetails(); //this calls const printDetails because pEmp is a const object

		//Employee* pEmp2 = pEmp1; //this is a compiler error because you can't assign const variable to a non-const variable
		Employee* pEmp2 = const_cast<Employee*>(pEmp1); //const_cast solves the above problem
		pEmp2->printDetails(); //calls non-const printDetails
		pEmp2->setName("Venkata Sathwick");
		delete pEmp2;
		pEmp2 = nullptr;
		pEmp1 = nullptr;

		const Employee* pEmp3 = new Employee(2, "Sunitha", "Analyst");
		//pEmp3->setName("Sunitha Duppada"); //this doesn't work since pEmp3 is a pointer to const Employee object. 
											 //We can't change anything after creating the object.

		pEmp3->printDetails();

		Employee* pEmp4 = const_cast<Employee*>(pEmp3);
		pEmp4->setName("Sunitha Duppada"); //const_cast again, which is bad
		pEmp4->printDetails();
		delete pEmp3;
		pEmp3 = nullptr;
		pEmp4 = nullptr;
	}*/
	
	//X* const p means “p is a const pointer to an X that is non-const”: 
	//you can’t change the pointer p itself, but you can change the X object via p
	/*{
		Employee* const pEmp = new Employee(1, "Sathwick", "Software Architect");
		//pEmp = NULL; //even we can't set it to NULL;
		pEmp->printDetails();
		pEmp->setName("Venkata Sathwick");
		pEmp->printDetails();
		delete pEmp;
	}*/

	//const X* const p means “p is a const pointer to an X that is const”: 
	//you can’t change the pointer p itself, nor can you change the X object via p.
	/*{
		const Employee* const pEmp = new Employee(1, "Sathwick", "Software Architect");
		//pEmp->setName("Venkata Sathwick"); //this is not allowed since the instance is a const object, so we can't change its contents
		pEmp->printDetails();
		//pEmp = nullptr; //This is also not allowed since pEmp is a const pointer
		delete pEmp;
		//pEmp = nullptr; //not allowed even after deleting the memory. 
						  //So a macro like SU_SAFE_DELETE will not work for this since we can't set the pointer to NULL
	}*/


	return 0;
}