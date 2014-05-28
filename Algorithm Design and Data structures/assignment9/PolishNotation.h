#include "Stack.h"
#include <string>

class PolishNotation
{
public:
	PolishNotation();
	~PolishNotation();
	int performOperation(std::string input);
	

private: 
	Stack *operands;
	int operatorDetermine(char op, int numberOne, int numberTwo);
};