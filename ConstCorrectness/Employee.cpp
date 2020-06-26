#include "Employee.h"
#include <iostream>

using namespace std;

Employee::Employee(int id, const std::string& name, const std::string& designation):		
	m_id(id),
	m_name(name),
	m_designation(designation)
{
	cout << "Constructor for '" << m_name << "' called" << endl;
}

Employee::~Employee()
{
	cout << "Destructor for '" << m_name << "' called" << endl;
}

void Employee::printName()
{
	cout << "Name: " << m_name.c_str() << endl;	
}

void Employee::printDesignation() const
{
	cout << "Designation: " << m_designation.c_str() << endl;
}

void Employee::printDetails() const
{
	//printName(); // we can't call non const method from const method
	printDesignation();
}

void Employee::printDetails()
{
	printName();
	printDesignation(); //we can call const method from a non-const method but we can't do the opposite
}