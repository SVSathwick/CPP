#include <memory>
#include <string>

class Employee{
    public:
        Employee(const std::string& name, int id);
        ~Employee();

        std::string getName();
        int getID();
        
        void setName(const std::string& name);
    private:

}