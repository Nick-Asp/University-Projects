#include "Stack.h"
#include "IntNode.h"
#include "PolishNotation.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	string input;
	getline(cin,input);

	//Checks for valid Input
	//Input is valid if the no of operators is one less than the number of operands.

	int noOfOperators = 0;
	int noOfOperands = 0;

	//Counting number of operators and operands.

	for (int unsigned i = 0; i < input.size(); ++i)
	{
		if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '/' || input.at(i) == '*'){

			noOfOperators++;
		}
		
		else if (input.at(i) < 58 && input.at(i) > 47 ){

			if(i != (input.size() - 1) && input.at(i+1) < 58 && input.at(i+1) > 47){
				
				i++;
			}

			noOfOperands++;
		}
	}

	if ((noOfOperands - noOfOperators) != 1 || noOfOperands == 0 || noOfOperators == 0)
	{
		cout << "Error" << endl;
		return 0;
	}

	//Peforms all of the calculations using the PolishNotation class.

	PolishNotation myPole;

	cout << myPole.performOperation(input);

	return 0;
}
