//#include <iostream>
//#include <memory>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Person
//{
//public:
//	Person(const string& name) :m_Name(name)
//	{
//		cout << "Constructor for " << m_Name << endl;
//	}
//	~Person()
//	{
//		cout << "Destructor for " << m_Name << endl;
//	}
//	void printDetails()
//	{
//		cout << "Name: " << m_Name << endl;
//	}
//
//private:
//	string m_Name;
//};
//
//int main()
//{
//	std::cout << "Hello World!\n";
//
//	//Reset method can be used to reset a smart pointer 
//	//so that we will release the memory once we are done using it
//	//{
//	//	unique_ptr<Person> upPerson(new Person("Sathwick"));
//	//	upPerson->printDetails();
//	//	//upPerson.release();
//	//	upPerson.reset();
//	//	//upPerson->printDetails();
//
//	//	shared_ptr<Person> spPerson(new Person("Sunitha"));
//	//	spPerson->printDetails();
//	//	spPerson.reset();
//	//}
//
//	vector<unique_ptr<Person>> people;
//	/*unique_ptr<Person> upPerson1(new Person("Person1"));
//	unique_ptr<Person> upPerson2(new Person("Person2"));
//	people.push_back(std::move(upPerson1));
//	people.push_back(std::move(upPerson2));
//	for (const auto& it : people)
//	{
//		it->printDetails();
//	}*/
//
//	vector<string> names;
//	names.push_back("Sathwick");
//	names.push_back("Guru");
//	names.push_back("Manju");
//	names.push_back("Pakanati");
//	names.push_back("Subhra");
//	names.push_back("Saumya");
//
//	for (const auto& it : names)
//	{
//		unique_ptr<Person> upPerson(new Person(it));
//		people.push_back(std::move(upPerson));
//	}
//
//	for (const auto& it : people)
//	{
//		it->printDetails();
//	}
//
//
//	cout << "END" << endl;
//}