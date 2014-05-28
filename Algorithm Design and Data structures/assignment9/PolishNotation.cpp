#include "PolishNotation.h"
#include <string>

using namespace std;

PolishNotation::PolishNotation(){

	operands = new Stack();
}

PolishNotation::~PolishNotation(){

	delete operands;
}

int PolishNotation::performOperation(string input){

//This alogrithim starts from the back of the input and loads the operands as it moves along the input.
	
for (int i = input.size() - 1; i > -1; --i){

	if (input.at(i) < 58 && input.at(i) > 47 )
		{
			if(input.at(i-1) < 58 && input.at(i-1) > 47){
				
				//This conditional takes the string input and converts a two digit number into it's integer form.
				operands->push(input.at(i) - '0' + (input.at(i-1) - '0')*10);
				i--;
			}
			
			else{

				operands->push(input.at(i) - '0');
			}
		}

	else if(input.at(i) == '+' || input.at(i) == '-' || input.at(i) == '/' || input.at(i) == '*'){

		char op = input.at(i);

		int operandOne = operands->pop();

		int operandTwo = operands->pop();

		int result = operatorDetermine(op,operandOne,operandTwo);

		operands->push(result);

	}
}

	//Returns the top of the stack, the answer.

	return operands->pop();
}

//This function is used to perform the operation given a character operator.
int PolishNotation::operatorDetermine(char op, int numberOne, int numberTwo){

	switch (op) {

	case '*':

		return numberOne * numberTwo;
		break;

	case '/':

		return numberOne / numberTwo;
		break;

	case '+':

		return numberOne + numberTwo;
		break;

	case '-':

		return numberOne - numberTwo;
		break;
	}

	return 0;
}