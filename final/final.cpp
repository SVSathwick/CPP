//When applied to a member function, the identifier final appears immediately after the declarator in the syntax of a member function declaration
//or a member function definition inside a class definition.
//When applied to a class, the identifier final appears at the beginning of the class definition, immediately after the name of the class.

#include <iostream>
#include <stdio.h>

struct Base
{
    virtual void foo()
    {
        printf("Base::foo\n");
    }
};

struct A : Base
{
    void foo() final
    {
        std::cout << "A::final\n";
    } // Base::foo is overridden and A::foo is the final override
    //void bar() final; // Error: bar cannot be final as it is non-virtual
};

struct B final : A // struct B is final
{
    //void foo() override; // Error: foo cannot be overridden as it is final in A
};

//struct C : B // Error: B is final
//{
//};

int main()
{
    std::cout << "Hello World!\n";

    return 0;
}