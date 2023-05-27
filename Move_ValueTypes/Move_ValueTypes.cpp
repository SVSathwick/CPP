#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// C++
class Bagel {
public:
    Bagel(std::set<std::string> ts) : toppings_(std::move(ts)) {}
    void printDetails()
    {   
        cout << "Printing Details of " << this << endl;
        for (const auto& it : toppings_)
        {
            cout << "\tTopping: " << it.c_str() << endl;
        }
    }
private:
    std::set<std::string> toppings_;
};

void printBagelDetails(Bagel bagel)
{
    bagel.printDetails();
}

int main()
{
    // Note how the bagels do
    // not share toppings:
    auto t = std::set<std::string>{};
    t.insert("salt");
    auto a = Bagel{ t };
    a.printDetails();
    // 'a' is not affected
    // when adding pepper
    t.insert("pepper");
    // 'a' will have salt
    // 'b' will have salt & pepper 
    auto b = Bagel{ t };
    b.printDetails();
    // No bagel is affected
    t.insert("oregano");

    printBagelDetails(a);
    printBagelDetails(std::move(b));

    return 0;
}