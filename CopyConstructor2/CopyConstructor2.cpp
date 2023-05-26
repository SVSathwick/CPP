#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    int id;
    string name;
    Employee() {
        cout << "Default Constructor " << endl;
    }
    Employee(int id, const string& name) {
        this->id = id;
        this->name = name;
        cout << "Constructing " << this->id << " " << this->name << endl;
    }
    Employee(const Employee& emp) {
        this->id = emp.id;
        this->name = emp.name;
        cout << "Copying " << emp.name << endl;
    }
    Employee(const Employee* pEmp) {
        this->id = pEmp->id;
        this->name = pEmp->name;
    }
    Employee operator=(const Employee& rhs) {
        cout << "Assignment Operator: " << endl;
        this->id = rhs.id;
        this->name = rhs.name;
        return *this;
    }

    /*Employee(Employee&& rhs) {
        cout << "Move Constructor " << endl;
        this->id = rhs.id;
        this->name = rhs.name;
        rhs.id = -1;
        rhs.name = "\0";
    }*/

    Employee operator+(const Employee& rhs) {
        /*Employee result;
        result.id = this->id + rhs.id;
        result.name = this->name + " " + rhs.name;
        return result;*/
        return Employee(this->id + rhs.id, this->name + rhs.name);
    }

    /*friend Employee operator+(const Employee& emp1, const Employee& emp2) {
        return Employee(emp1.id+emp2.id, emp1.name+emp2.name);
    }*/
};

int main()
{
    std::cout << "Hello World!\n";

    //Testing deep copying
    {
        /*Employee sathwick(1, "Sathwick");
        cout << "sathwick " << sathwick.id << " " << sathwick.name << endl;

        Employee sathwick2(sathwick);
        cout << "sathwick2 " << sathwick2.id << " " << sathwick2.name << endl;

        sathwick.id = 10;
        sathwick.name = "Sivvala";
        cout << "sathwick " << sathwick.id << " " << sathwick.name << endl;
        cout << "sathwick2 " << sathwick2.id << " " << sathwick2.name << endl;

        Employee* pVenkata = new Employee(2, "Venkata");
        cout << "pVenkata " << pVenkata->id << " " << pVenkata->name << endl;

        Employee venkata(pVenkata);
        cout << "venkata " << venkata.id << " " << venkata.name << endl;

        Employee sathwick3(&sathwick);
        cout << "sathwick3 " << sathwick3.id << " " << sathwick.name << endl;*/
    }

    {
        Employee emp1(1, "Emp-1");
        Employee emp2(2, "Emp-2");
        Employee emp3 = emp1 + emp2;;
        //emp3 = emp1 + emp2;
        cout << "Emp3: id " << emp3.id << ", name " << emp3.name << endl;

        Employee emp4;
        emp4 = emp1 + emp2;
        cout << "Emp4: id " << emp4.id << ", name " << emp4.name << endl;
    }
    

    return 0;
}