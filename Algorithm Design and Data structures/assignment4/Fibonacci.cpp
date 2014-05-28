#include "Fibonacci.h"
#include <iostream>


Fibonacci::Fibonacci(){}

Fibonacci::~Fibonacci(){}

int Fibonacci::giveFibonacci(int n){

	//If n is 0 or 1 it just returns n.
	if ( n == 1 || n == 0)
	{
		return n;
	}

	else
	{
		//returns the sum of the two fibonacci numbers.
		return giveFibonacci(n-1) + giveFibonacci(n-2);
	}

}


