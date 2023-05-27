#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Employee {
private:
    int _id;
    string _name;
public:
    Employee(int id, const string& name) :_id(id), _name(name) {
        cout << "Constructing " << _name << endl;
    }
    /*Employee(const Employee& rhs) {
        this->_id = rhs._id;
        this->_name = rhs._name + "-Copy";

        cout << "Copy constructor for " << this->_name << endl;
    }*/
    Employee(const Employee& rhs) = delete;
    //Employee& operator=(const Employee& rhs) = delete;
    ~Employee(){
        cout << "Destructing " << _name << endl;
    }
    string getName() { return _name; }
};

class Department {
private:
    string _name;
    Employee* _pManager;
public:
    Department(const string& name, Employee* pEmp) :_name(name), _pManager(pEmp) {
        cout << "Constructing Dept: " << _name << ", Manager: " << _pManager->getName().c_str() << endl;
    }
    ~Department() {
        //here Department doesn't need to delete _pManager since it is not constructed by Department class
        cout << "Destructing Dept " << _name.c_str() << endl;
    }
};

class Office {
private:
    string _name;
    Employee* _pEmployee;
public:
    Office(const string& name) :_name(name), _pEmployee(nullptr) {
        cout << "Constructing Office: " << _name << endl;
    }
    void addEmployee(int id, const string& name) {
        _pEmployee = new Employee(id, name);
    }
    ~Office() {
        cout << "Destructing Office: " << _name << endl;
        if (_pEmployee != nullptr) {
            delete _pEmployee;
            _pEmployee = nullptr;
        }
    }
};

void printEmpDetails(Employee* pEmpIn) {
    if (pEmpIn  != nullptr) {
        cout << pEmpIn->getName().c_str() << endl;
        //delete pEmpIn;
        pEmpIn = nullptr; //setting this to null doesn't make the pEmpIn passed by the caller to NULL, its just a temporary value type created for holding the pointer
    }
}

//similar to factory method
Employee* getEmployeeInstance() {
    return new Employee(2, "Employee Raw Ptr");
}

shared_ptr<Employee> getEmployeeInstanceSP() {
    shared_ptr<Employee> spEmp(new Employee(3, "Employee shared Ptr"));
    return spEmp;
}

unique_ptr<Employee> getEmployeeInstanceUP() {
    unique_ptr<Employee> upEmp(new Employee(3, "Employee unique Ptr"));
    return move(upEmp);
}

void printEmpDetails(shared_ptr<Employee> spEmp) {
    cout << "refcount: " << spEmp.use_count() << endl;
    cout << spEmp->getName().c_str() << endl;
}

int main()
{
    //{
    //    Employee* pEmp = new Employee(1, "Sathwick");
    //    //printEmpDetails(pEmp);
    //    if (pEmp != nullptr) {
    //        delete pEmp;
    //        pEmp = nullptr;
    //    }
    //        
    //}

    //testing ownership behavior if the instance is created and returned by a factory method
    //{
    //    Employee* pEmp = getEmployeeInstance();
    //    //client owns it now and it should delete the instance
    //    if (pEmp != nullptr) { 
    //        delete pEmp; //memory leak if we miss this
    //    }
    //}

    //Returning shared_ptr objects from factory method solves the memory leaks issue
    /*{
        auto spEmp = getEmployeeInstanceSP();
        cout << spEmp->getName().c_str() << endl;
    }*/

    //Returning unique_ptr objects from factory method also solves the memory leaks issue
    /*{
        auto spEmp = getEmployeeInstanceUP();
        cout << spEmp->getName().c_str() << endl;
    }*/

    /*{
        unique_ptr<Employee> upEmp(new Employee(1, "Sathwick"));
    }*/

    /*{
        unique_ptr<Employee> upEmp;
        upEmp = make_unique<Employee>(Employee(1, "Sathwick"));
    }*/
    
    /*{
        shared_ptr<Employee> spEmp(new Employee(1, "sathwick"));
        cout << "refcount: " << spEmp.use_count() << endl;
        printEmpDetails(spEmp);
        cout << "refcount: " << spEmp.use_count() << endl;
    }*/

    //{
    //    vector<unique_ptr<Employee>> emps;
    //    //copy constructor gets called here while pushing the object to the vector and original object gets destryed
    //    emps.push_back(make_unique<Employee>(Employee(1, "sathwick")));
    //    emps.push_back(make_unique<Employee>(Employee(2, "sunitha")));

    //    cout << "test log" << endl;
    //}

    //{
    //    vector<unique_ptr<Employee>> emps;
    //    unique_ptr<Employee> upEmp1(new Employee(1, "sathwick"));
    //    unique_ptr<Employee> upEmp2(new Employee(2, "sunitha"));
    //    //No copy constructor involved here and move does the job for us - recommended
    //    emps.push_back(move(upEmp1));
    //    emps.push_back(move(upEmp2));

    //    cout << "test log" << endl;
    //}

    {
        vector<unique_ptr<Employee>> emps;
        //unique_ptr<Employee> upEmp = nullptr;
        Employee* emp = new Employee(1, "Sathwick");
        {
            //vector<unique_ptr<Employee>> emps;
            unique_ptr<Employee> upEmp(emp); //valid
            //upEmp = make_unique<Employee>(emp); //invalid
            cout << "upEmp " << upEmp->getName().c_str() << endl;
            cout << "emp " << emp->getName().c_str() << endl;
            //No copy constructor involved here and move does the job for us - recommended
            emps.push_back(move(upEmp));
        }

        //try to access emp
        //Memory is not released yet - because the emps vector is declared outside the above block
        //if emps vector is declared inside the block, memory for emp would have been released
        //and will result in a crash when tried to print name
        if(emp != nullptr) 
            cout << "emp " << emp->getName().c_str() << endl;
        
        cout << "test log" << endl;
    }

    /*{
        vector<unique_ptr<Employee>> emps;
        unique_ptr<Employee> upEmp1(new Employee(1, "sathwick"));        
        emps.push_back(move(upEmp1));
        emps.push_back(move(upEmp1));

        cout << "test log" << endl;
    }*/

    //{
    //    vector<unique_ptr<Employee>> emps;
    //    unique_ptr<Employee> upEmp1(new Employee(1, "sathwick"));
    //    emps.push_back(move(upEmp1)); //upEmp1 lost the ownership now

    //    if(upEmp1.get() != nullptr)
    //        cout << upEmp1->getName().c_str() << endl;

    //    for (const auto& it : emps) {
    //        cout << it->getName().c_str() << endl;
    //    }

    //    cout << "test log" << endl;
    //}

    /*{
        vector<shared_ptr<Employee>> emps;
        shared_ptr<Employee> spEmp1(new Employee(1, "sathwick"));
        shared_ptr<Employee> spEmp2(new Employee(2, "sunitha"));
        emps.push_back(spEmp1);
        emps.push_back(spEmp2);

        for (const auto& it : emps) {
            cout << it->getName().c_str() << endl;
        }
        cout << "test log" << endl;
    }*/

    /*{   
        using SPEmployee = shared_ptr<Employee>;
        vector<SPEmployee> emps;
        SPEmployee spEmp1(new Employee(1, "sathwick"));
        SPEmployee spEmp2(new Employee(2, "sunitha"));
        emps.push_back(spEmp1);
        emps.push_back(spEmp2);

        for (const auto& it : emps) {
            cout << it->getName().c_str() << endl;
        }
        cout << "test log" << endl;
    }*/
    
    //{
    //    Employee* pEmp = new Employee(1, "sathwick"); 
    //    Department dept("R&D", pEmp);
    //    if (pEmp != nullptr) {
    //        delete pEmp; //memory leak if we miss this code, dept doesn't own this. Client has to manage this
    //        pEmp = nullptr;
    //    }   
    //}

    //{
    //    Office off("HCS");
    //    off.addEmployee(1, "Sathwick"); //Employee object gets created inside this method and destructed when off object gets destructed
    //}
    return 0;
}
