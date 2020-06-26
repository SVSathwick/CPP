#pragma once

#include <string>
	

class Employee
{
private:
	int m_id;
	std::string m_name;
	std::string m_designation;
public:
	Employee(int id, const std::string& name, const std::string& designation);
	~Employee();
	void printName();
	void printDesignation() const;
	void printDetails() const;
	void printDetails();
	void setName(const std::string& name) { m_name = name; }
};
