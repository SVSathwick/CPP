#include <iostream>
#include <string>

bool palindrome(const std::string& str){
	if (str.size() < 2)
		return false;

	int count = str.size();
	for (int i = 0; i < count / 2; i++) {
		if (str[i] != str[count - 1 - i])
			return false;
	}
	return true;
}

void printPalindromes(const std::string& str) {

	for (int i = 0; i < str.size(); i++) {
		for (int j = i+1; j < str.size(); j++) {

			std::string subStr(str.substr(i, j));

			if (palindrome(subStr))
				std::cout << subStr << " is a palindrome" << std::endl;
		}
	}
}

int main()
{
	/*std::string str1{"Hello"};
	if (palindrome(str1)) {
		std::cout << str1 << " is a palindrome" << std::endl;
	}
	else {
		std::cout << str1 << " is NOT a palindrome" << std::endl;
	}

	std::string str2{"aba"};
	if (palindrome(str2)) {
		std::cout << str2 << " is a palindrome" << std::endl;
	}
	else {
		std::cout << str2 << " is NOT a palindrome" << std::endl;
	}*/

	std::string str1{"abba"};
	printPalindromes(str1);
}