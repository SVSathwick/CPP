#include <iostream>
#include <utility>
#include <string>

using namespace std;

void reverseAString(char* str, int length) {
    char temp;
    for (int i = 0; i < length/2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void reverseAString(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0; i < length / 2; i++) {
        std::swap(str[i], str[length - i - 1]);
    }
}

int main()
{
    char name[9] = "HI HELLO";
    reverseAString(name, 8);
    std::cout << name << endl;

    char name2[9] = "Sathwick";
    reverseAString(name2);
    std::cout << name2 << endl;

    return 0;
}