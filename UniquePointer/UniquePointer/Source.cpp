#include <iostream>
#include <stdio.h>
#include <memory>
#include <vector>

using namespace std;

class Employee
{
public:
	Employee(const Employee& rhs) = delete;
	Employee& operator=(const Employee& rhs) = delete;
	Employee(const std::string& firstName, const std::string& lastName) :
		m_FirstName(firstName), 
		m_LastName(lastName) 
	{
		std::cout << "Constructed " << m_FirstName.c_str() << " " << m_LastName.c_str() << endl;
	}
	~Employee()
	{
		std::cout << "Destructing " << m_FirstName.c_str() << " " << m_LastName.c_str() << endl;
	}

	void PrintDetails()
	{
		std::cout << "Full Name: " << m_FirstName.c_str() << " " << m_LastName.c_str() << endl;
	}

private:
	std::string m_FirstName;
	std::string m_LastName;
};

void PrintEmployeeDetails(Employee* pEmployee)
{
	if (pEmployee)
	{
		pEmployee->PrintDetails();
	}
}

void PrintEmployeeDetails(std::unique_ptr<Employee> pEmployee)
{
	if (pEmployee.get() != nullptr) 
	{
		pEmployee->PrintDetails();
	}
}

int main()
{
	{
		std::unique_ptr<Employee> pEmployee = std::make_unique<Employee>("Sathwick", "Sivvala");
		std::unique_ptr<Employee> pEmployee2 = std::make_unique<Employee>("Sunitha", "Duppada");

		pEmployee->PrintDetails();
		pEmployee2->PrintDetails();

		std::vector<std::unique_ptr<Employee>> employees;
		employees.push_back(std::move(pEmployee));
		employees.push_back(std::move(pEmployee2));
		for (const auto& it : employees)
		{
			it->PrintDetails();
		}
	}

	{
		std::vector<std::unique_ptr<Employee>> employees;
		employees.push_back(std::make_unique<Employee>("Suresh", "Duppdada"));
		employees.push_back(std::make_unique <Employee>("Jagadish", "Duppada"));

		for (const auto& it : employees)
		{
			it->PrintDetails();
		}
	}

	{
		auto pEmployee = std::make_unique<Employee>("Anshuman", "Sivvala");
		pEmployee->PrintDetails();

		auto pEmployee2 = std::move(pEmployee);
		pEmployee2->PrintDetails();

		if (pEmployee.get() == nullptr && pEmployee2.get() != nullptr)
		{
			pEmployee2->PrintDetails();
		}
	}

	{
		auto pEmp = std::make_unique<Employee>("Sathwick", "Sivvala");

		Employee* pEmp1 = pEmp.get();

		Employee* pEmp2 = nullptr;
		pEmp2 = pEmp.get();

		pEmp->PrintDetails();
		pEmp1->PrintDetails();
		pEmp2->PrintDetails();
	}

	//Calling methods which needs a raw pointer
	{
		auto pEmp = std::make_unique<Employee>("Sathwick", "Sivvala");
		PrintEmployeeDetails(pEmp.get());
	}

	//Calling a method which accepts unique_ptr
	{
		auto pEmp = std::make_unique<Employee>("Sathwick", "Sivvala");		
		PrintEmployeeDetails(std::move(pEmp));
		if (pEmp.get() != nullptr)
		{
			pEmp->PrintDetails();
		}
	}

	return 0;
}