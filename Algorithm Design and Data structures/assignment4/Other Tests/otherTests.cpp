#include <iostream>
#include <string>
#include "Palindrome.h"

using namespace std;


int main(int argc, char const *argv[])
{
	Palindrome pali;

	string hello;

	cin >> hello;

	cout << "Output: " << pali.reverseString(hello,0) << endl;

	//cout << "Palindrome? : " << pali.isPalindrome(hello) << endl;

	return 0;
}
