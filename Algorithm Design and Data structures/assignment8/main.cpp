#include <iostream>
#include <sstream>
#include "IntList.h"
#include "IntNode.h"

using namespace std;

int main(int argc, char const *argv[])
{
	IntList myIntList;

	string input;

	getline(cin,input);

	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (input.at(i) == 'A')
		{
			i++;

			unsigned int j = 0;

			while((i+j) != (input.size()) && input.at(i+j) >= 48 && input.at(i+j) <= 57){
			
				j++;
			
			}

			stringstream integerStream(input.substr(i,j));

			int temp;

			integerStream >> temp;

			myIntList.addInt(temp);
		}

		else if(input.at(i) == 'R'){

			myIntList.removeHead();
		}
	}

	myIntList.printList();

	int* middleValues = myIntList.findMiddleNode();

	if (middleValues[1] == -1)
	{
		cout << " " << middleValues[0];
	}

	else{

		cout << " " << middleValues[0] << " " << middleValues[1];
	}

	delete middleValues;
	
	return 0;
}