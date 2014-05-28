#include "BubbleSort.h"
#include <iostream>

using namespace std;

BubbleSort::BubbleSort(std::vector<int> v) : Sort(v) {}

void BubbleSort::sort(){

	bool swaps = true;
	
	int temp;

	//This sorting alogrithim arranges from smallest to largest.
	
	while(swaps){

		//Function exits if no swaps have occured, indiciating that
		//The list has been sorted.

		swaps = false;

		for (unsigned int i = 0; i < (data.size() - 1); ++i)
		{
			//Compares the nth and the nth+1 element and swaps if
			//The nth element is greater than the nth + 1 element.
			if (data.at(i) > data.at(i+1))
			{
				temp = data.at(i);

				data.at(i) = data.at(i+1);

				data.at(i+1) = temp;

				swaps = true;
			}
		}
	}
}