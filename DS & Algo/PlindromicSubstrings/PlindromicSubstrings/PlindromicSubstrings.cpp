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

std::string printPalindromes(const std::string& str) {

	std::string longestSubStr = "";
	for (int i = 0; i < str.size(); i++) {
		for (int j = i+1; j <= str.size(); j++) {

			std::string subStr(str.substr(i, j-i));

			if (palindrome(subStr)) {
				std::cout << subStr << " is a palindrome" << std::endl;
				if (subStr.size() > longestSubStr.size()) {
					longestSubStr = subStr;
				}
			}	
		}
	}

	return longestSubStr;
}

int countSubstrings(const std::string& str) {
	int nPalindromicSubStrings = 0;
	for (int i = 0; i < str.size(); i++) {
		for (int j = i + 1; j <= str.size(); j++) {			
			
			bool bPalindrome = true;
			for (int ii = i; ii < (j - i) / 2; ii++) {
				if (str[ii] != str[j - i - 1 - ii])
					bPalindrome = false;
			}
			if (bPalindrome) {
				std::string subStr(str.substr(i, j - 1));
				std::cout << subStr << " is a palindrome" << std::endl;
				nPalindromicSubStrings++;
			}
				
		}
	}
	return nPalindromicSubStrings;
}

int main()
{
	/*std::string str1{"hello"};
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

	std::string str3{"abaab"};
	/*std::string longestSubStr = printPalindromes(str3);
	std::cout << "Longest sub string: " << longestSubStr << std::endl;*/
	int n = countSubstrings(str3);
	printf("Total palindromic substrings: %d", n);
}