#include <iostream>
#include <string>
#include "Palindrome.h"

Palindrome::Palindrome(){

}

Palindrome::~Palindrome(){}

bool Palindrome::isPalindrome(std::string input){

	std::string reversedString = reverseStringActual(input,0);

	//Just compares using the compare function from the string class

	if (reversedString.compare(input) == 0)
	{
		return 1;
	}

	return 0;

}
//The outer function, used to hide how reverseStringAcutal works
std::string Palindrome::reverseString(std::string input){

	return reverseStringActual(input,0);
}

std::string Palindrome::reverseStringActual(std::string input,int pos){
	
	//This alogrthim swiches the characters until it gets to the middle of the string or the length of the string/2
	//Each character is switched with its corresponding character on the other side of the string
	//Until the entire string has beed reversed.

	//If the length of the string is an even number than the following occurs
	if (input.length() % 2 == 0)
	{
		//This is different as for odd number lengths, the middle character doesn't need
		//to be switched with anything, while for even lengths there is no middle character.

		if (pos < ((input.length())/2))
		{	
			//The charSwitcher functions switches the characters in the array
			
			charSwitcher(input.at(pos),input.at((input.length() - 1) - pos));
			
			//Position is than incrameted and the recursion occurs.
			
			pos++;

			return reverseStringActual(input,pos);

		}
	}

	//If the length of the string is an odd number.
	
	else {

		if (pos < ((input.length()-1)/2))
		{

			//The charSwitcher functions switches the characters in the array
			
			charSwitcher(input.at(pos),input.at((input.length() - 1) - pos));
			
			//Position is than incrameted and the recursion occurs.
			
			pos++;
			
			return reverseStringActual(input,pos);

		}
	}
	
	return input;

}

//Simple character switcher using an intermid character.
//Called in by reference to make acutal changes to the characters.
void Palindrome::charSwitcher(char &characterOne, char &characterTwo){

	char intermid = characterOne;

	characterOne = characterTwo;

	characterTwo = intermid;
}



