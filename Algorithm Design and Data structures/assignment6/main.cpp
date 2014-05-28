#include "BinaryNode.h"
#include "Individual.h"
#include "BitFlip.h"
#include "Rearrange.h"
#include <string>
#include <iostream>

using namespace std;

bool inputCheck(string input);

int main(int argc, char const *argv[])
{

	string input;

	cin >> input;

	int k;

	if (inputCheck(input))
	{
		BitFlip myFlipper(input);

		cin >> k;

		myFlipper.execute(k);

		cout << myFlipper.getString() << " ";
	}

	if (inputCheck(input)){

		cin >> input;

		Rearrange myRearranger(input);

		cin >> k;

		myRearranger.execute(k);

		cout << myRearranger.getString();
	}


	return 0;
}

//Checks if the input consists only of 1's or 0's, nothing else.
bool inputCheck(string input){

for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (input.at(i) != '0' && input.at(i) != '1')
		{
			cout << "ERROR";

			return false;
		}
	}

	return true;
}