#include <iostream>

class X {
    private:
        static constexpr int c1 = 42; // preferred
        static const int c2 = 7;
        enum { c3 = 19 };
        std::array<char,c1> v1;
        std::array<char,c2> v2;
        std::array<char,c3> v3;
    // ...
};

int main()
{

    return 0;
}

