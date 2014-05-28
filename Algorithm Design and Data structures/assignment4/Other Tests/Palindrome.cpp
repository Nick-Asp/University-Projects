#include <iostream>
#include <string>
#include "Palindrome.h"

Palindrome::Palindrome(){

	posI = 0;
}

Palindrome::~Palindrome(){}

bool Palindrome::isPalindrome(std::string input){

	std::string reversedString = reverseString(input,0);

	if (reversedString.compare(input) == 0)
	{
		return 1;
	}

	return 0;

}

std::string Palindrome::reverseString(std::string input,int pos){

	if (input.length() % 2 == 0)
	{
		if (pos < ((input.length())/2))
		{	

			charSwitcher(input.at(pos),input.at((input.length() - 1) - pos));

			pos++;

			return reverseString(input,pos);

		}
	}	

	else {

		if (pos < ((input.length()-1)/2))
		{

			charSwitcher(input.at(pos),input.at((input.length() - 1) - pos));

			pos++;

			return reverseString(input,pos);

		}
	}

	//std::cout << "Input is being returned and is " << input << std::endl;
	
	return input;

}

void Palindrome::charSwitcher(char &characterOne, char &characterTwo){

	char intermid = characterOne;

	characterOne = characterTwo;

	characterTwo = intermid;
}

/*
int main(int argc, char const *argv[])
{
	Palindrome pali;

	std::string hello = "elle";

	std::cout << hello << endl;

	std::cout << "Output: " << pali.reverseString(hello) << endl;

	std::cout << "Palindrome? : " << pali.isPalindrome(hello) << endl;

	return 0;
}
*/

