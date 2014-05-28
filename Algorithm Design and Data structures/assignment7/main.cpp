#include <iostream>
#include <vector>
#include <string>
#include "Sort.h"
#include "BubbleSort.h"
#include "RecursiveBinarySearch.h"
#include "QuickSort.h"
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	string input;

	getline(cin,input);

	std::vector<int> v;

	//Using a string stream to get the input and pushing it back into a vector.
	//I use this method as the length of the input isn't constant so my program
	//Needs to be able to interpret input of different lengths.

	stringstream stream(input);

	while(1) {


		//Breaks the loop if the stream ends.

		if (stream.eof())
		{
			break;
		}

		//Loads number with the value from the string stream
		//And pushes it back.

		int number;

		stream >> number;

		v.push_back(number);
		
	}

	//The rest of main is just creating and calling the different classes functions.

	QuickSort myQuickSorter(v);

	myQuickSorter.sort(0,myQuickSorter.getData().size() - 1);

	RecursiveBinarySearch searcher;

	bool result = searcher.search(myQuickSorter.getData(),0,myQuickSorter.getData().size() - 1,0);

	if (result == true)
	{
		cout << "true ";
	}

	else{

		cout << "false ";
	}

	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << myQuickSorter.getData().at(i) << " ";
	}

	return 0;
}