#ifndef EFFICENTFIBONACCI
#define EFFICENTFIBONACCI

class EfficentFibonacci
{
public:
	
	EfficentFibonacci();
	
	~EfficentFibonacci();
	
	int giveFibonacci(int);

private:

	int alreadyCalculatedValues[50];
};

#endif