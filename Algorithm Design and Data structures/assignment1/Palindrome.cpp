#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

//Reverse string Function

char *reverseString(char *myString){
	//C-String to be returned at the end of the function.
	char *reversedString;

	reversedString = new char[strlen(myString)+1];

	for (int i = 0; i < (strlen(myString)); ++i)
	{
		reversedString[i] = myString[strlen(myString) - i - 1];
	}

	return reversedString;

}

//Changes any uppercase letters in the string into lowercase letters.
void lowerCase(char *inputString){

	for (int i = 0; i < strlen(inputString); ++i)
	{
		if ((65 <= inputString[i] && inputString[i]  <= 90 && inputString[i] != '1' && inputString[i] != '0'))
		{
			//Logic comes fromt ASCII codes of the letters used.
			inputString[i] = inputString[i] + 32;
		}
	}

}
//Removes non letters, replacing them with spaces.
char *removeNonLetters(char *inputString){

	int charactersRemoved = 0;

	for (int i = 0; i < strlen(inputString); i++){
		
		if(!isalpha(inputString[i])){

			charactersRemoved++;
			
		}
	}

	char *outputString;

	outputString = new char[strlen(inputString)-charactersRemoved];
	
	int minusCounter = 0;	
	
	for(int i = 0; i < strlen(inputString); i++){

		if(isalpha(inputString[i]) || inputString[i] == '1' || inputString[i] == '0'){		
		
		outputString[minusCounter] = inputString[i];
		
		minusCounter++;

		}
	}
	return outputString;
		
}

//Palindrome checker function.
bool isPalindrome(char *myString){

	char *reversedString;
 	
 	reversedString = reverseString(myString);
	
	char* nonLettersReversed = removeNonLetters(reversedString);
	char* nonLetters = removeNonLetters(myString);
	
	lowerCase(nonLettersReversed);
	
	lowerCase(nonLetters);
	
	for (int i = 0; i < strlen(myString); ++i)
	{
		//Checks if the letters in the aren't the same and exits the function if they aren't.
		if (nonLettersReversed[i] != nonLetters[i]){

			return false;
		}
	}
	
	delete reversedString;	
	delete nonLettersReversed;
	delete nonLetters;	
	
	return true;
	

}
/*
bool isPalindromeMan(char *myString){

	char *reversedString;
 	
 	reversedString = reverseString(myString);
	
	for (int i = 0; i < strlen(myString); ++i)
	{
		//Checks if the letters in the aren't the same and exits the function if they aren't.
		if (reversedString[i] != myString[i]){

			return false;
		}
	}
	
	delete reversedString;
	return true;

}	
*/



//Creates new string, twice the length of the original string containing the mancherster code of the original string.
char *manchesterEncode(char *inputString){

	char *encoded;

	encoded = new char[strlen(inputString) * 2];

	for (int i = 0; i < strlen(inputString); ++i)
	{
		if (inputString[i] == '1')
		{
			encoded[i*2] = '1';
			encoded[i*2 + 1] = '0';
		}

		else if (inputString[i] == '0')
		{
			encoded[i*2] = '0';
			encoded[i*2 + 1] = '1';
		}

		else
		{
			//Returns an error if the string inputed isn't a sequence of 1's and 0's.
			return "Error";
		}
	}

	return encoded;

}
//Creates a new string, that contains the orginal decoded sequence of 1's and 0's
char *manchesterDecode(char *inputString){

	char *decoded;

	decoded = new char[strlen(inputString + 1];
	
	int decodeCounter = 0;
	
	for (int i = 0; i < strlen(inputString); i = i + 2)
	{
		if (inputString[i] == '1')
		{
			decoded[decodeCounter] = '1';

			decodeCounter++;
		}

		else if (inputString[i] == '0')
		{
			decoded[decodeCounter] = '0';

			decodeCounter++;
		}

	}

	return decoded;

}

bool isManchester(char *inputString){

	for (int i = 0; i < strlen(inputString); ++i)
	{
		if (inputString[i] == 49 || inputString[i] == 48)
		{
			return 1;
		}
	}

	return 0;

}

//Driver code
int main(int argc, char const *argv[])
{
	char *myString;

	myString = new char[50];

	cout << "Please enter a string to be reversed: ";

	cin.getline(myString,50);

	char* reversedString;

	reversedString = reverseString(myString);

	cout << reversedString << endl;
		
	cout << "Is the entered string a palindrome?: " << isPalindrome(myString) << endl;

	cout << "Would you like to convert your entered string into manchester code?\nIf yes enter 1, If no enter any key" << endl;
	
	char indicator;
	
	cin >> indicator;
	
	if(indicator == '1' && isManchester(myString)){
	
		cout << "Converting into manchester code" << endl;
	
		char *manchesterEncodedString;
		manchesterEncodedString = manchesterEncode(myString);

		cout << "String in manchester code: " << manchesterEncodedString << endl;

		cout << "Is the manchester code a palindrome?: " << isPalindrome(manchesterEncodedString) << endl;
	
		char* manchesterDecodedString;
		manchesterDecodedString = manchesterDecode(manchesterEncodedString);
	
		cout << "String decoded from manchester code: " << manchesterDecodedString << endl;
		
		delete manchesterEncodedString;
		delete manchesterDecodedString;
	}

	else if(!isManchester(myString)){

		cout << "Entered string is not binary" << endl;

	}
	
	//Freeing any allocated memory, in order of allocation.
	
	delete myString;
	delete reversedString;
	

	return 0;
}
