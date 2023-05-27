#include <iostream>

using namespace std;

template<typename T>
T increment(T x) {
    return x + 1;
}

template <typename T>
T sum(T from, T to, T step) {
    T res = from;
    while ((from += step) < to) { 
        res += from; 
    }
    return res;
}

int main()
{
    std::cout << "Hello World!\n";
    int i = 0;
    cout << "i: " << i << ", increment(i): " << increment(i) << endl;

    double d = 1.1;
    cout << "d: " << i << ", increment(d): " << increment(d) << endl;

    int start = 0, end = 20, step = 2;
    cout << "0 to 20 with step 2: " << sum(start, end, step) << endl;

    double dStart = 0, dEnd = 10, dStep = 0.5;
    cout << "0 to 20 with step 2: " << sum(dStart, dEnd, dStep) << endl;

    cout << "END";
}