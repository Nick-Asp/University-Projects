#ifndef PALINDROME
#define PALINDROME

#include <iostream>
#include <string>

class Palindrome
{

public:

	Palindrome();

	~Palindrome();

	std::string reverseString(std::string);

	std::string reverseStringActual(std::string input,int);

	void charSwitcher(char &characterOne, char &characterTwo);

	bool isPalindrome(std::string);


};

#endif