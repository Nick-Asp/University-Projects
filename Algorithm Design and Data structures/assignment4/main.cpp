#include "Palindrome.h"
#include "Fibonacci.h"
#include "EfficentFibonacci.h"
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	//Creating the intial classes

	Palindrome pali;

	EfficentFibonacci effFibo;

	//Input strings

	string stringToReverse;

	string otherInput;

	//Getting input from the user

	cin >> stringToReverse;

	cin >> otherInput;
	
	//Checking if the user has inputed anything into the first section of the program.
	//If they haven't Error is outputed

	if (stringToReverse.empty())
	{
		cout << "ERROR" << endl;
	}

	else{

		//Outputing the reversed string
		cout << pali.reverseString(stringToReverse);

		//Conditionals converting the 1 and 0 output of isPalindrome to yes or no
		if (pali.isPalindrome(stringToReverse)){
			cout << " " << "yes";
		}

		else if(!pali.isPalindrome(stringToReverse)){

			cout << " " << "no";
		}
	}

	if (otherInput.empty()){
		
		cout << " ERROR";
	}

	else {

		int fiboNo = 0;
		//Checking if the character is between 0 - 9 using the ascii codes.
		//This conditional applies to 2 character numbers.
		if (otherInput.at(0) > 47 && otherInput.at(0) < 58 && otherInput.at(1) > 47 && otherInput.at(1) < 58)
		{	
			//The first character is converted into an integer and then mutiplied by 10
			//The second character is converted into an integer and added onto the end
			fiboNo = (otherInput.at(0) - 48)*10 + (otherInput.at(1) - 48);
			
		}
		//This conditional applies to one character numbers
		else if (otherInput.at(0) > 47 && otherInput.at(0) < 58){

			//The one character is simply converted into an integer.
			fiboNo = otherInput.at(0) - 48;
			
			}
		//Error is outputed if the character isn't a number.
		else{

			cout << " ERROR" << endl;
		}

		//Outputs the fibonacci number
		cout << ' ' << effFibo.giveFibonacci(fiboNo);
	}
	
	return 0;
}