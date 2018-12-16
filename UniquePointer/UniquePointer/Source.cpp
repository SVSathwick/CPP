#include <iostream>
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

	return 0;
}