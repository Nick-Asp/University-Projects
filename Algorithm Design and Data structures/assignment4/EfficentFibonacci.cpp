#include "EfficentFibonacci.h"

EfficentFibonacci::EfficentFibonacci(){
	//All the previous values are stored in this array that is initally filled with -1's
	//I chose 50 as any n values larger than this caused issues with my program, overflow etc.

	for (int i = 0; i < 50; ++i)
	{
			alreadyCalculatedValues[i] = -1;
	}	

}

EfficentFibonacci::~EfficentFibonacci(){}

int EfficentFibonacci::giveFibonacci(int n){

	//Similar to the fibonacci file, if n is 0 or 1, it returns 0 or 1 and stores 1 and 0 for later.
	if ( n == 0 || n == 1)
	{
		alreadyCalculatedValues[n] = n;
		return n;
	}

	else
	{	
		//These conditionals check if the value in the array is -1, if it isn't then it gets the value and stores it in
		//the array at n.

		if (alreadyCalculatedValues[n-1] == -1)
		{
			alreadyCalculatedValues[n-1] = giveFibonacci(n-1);
		}

		if (alreadyCalculatedValues[n-2] == -1)
		{
			alreadyCalculatedValues[n-2] = giveFibonacci(n-2);
		}
	}
		//Returned is then the values located in the array, instead of having to caluclate all of the again.
		return alreadyCalculatedValues[n-1] + alreadyCalculatedValues[n-2];
}

//This method is more effiecent than the origianl, but having to fill the array 50 times reduced the speed of it.