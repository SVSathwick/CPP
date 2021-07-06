#include <iostream>
#include <string>
#include <memory>

class Employee
{
public:
	Employee(int id, const std::string& name)
	{
		//int size = strlen(name);
		m_Name = name;
		m_Id = id;
		m_Age = new int(35);
	}
	~Employee()
	{
		std::cout << "Destructor called";
		delete m_Age;
	}
private:
	int m_Id;
	std::string m_Name;
	int* m_Age;
};

int main()
{	
	{
		std::unique_ptr<Employee> emp1(new Employee(1, "Sathwick"));
		std::unique_ptr<Employee> emp2(new Employee(2, "Sunitha"), []()
			{ std::cout << "Customer deleter"; });
	}	

	return 0;
}