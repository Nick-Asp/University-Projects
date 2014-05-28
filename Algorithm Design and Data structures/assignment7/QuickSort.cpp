#include "QuickSort.h"
#include <iostream>


using namespace std;

QuickSort::QuickSort(std::vector<int> v) : Sort(v) {
}

void QuickSort::sort(int start, int end){

	//This sorting alogrithm aranges form smallest to highest.

	int left = start, right = end;
	int pivot;
	int temp;
	
	pivot = data.at((left+right)/2);

	while(left <= right){

		//Firstly traverses through the list ordering the values
		//Lower than pivot to the left of pivot and values
		//Greater than pivot to the right of pivot in the list.

		while(data.at(left) < pivot){

			left++;
		}

		while(data.at(right) > pivot){

			right--;
		}

		if (left <= right)
		{
			temp = data.at(left);
			data.at(left) = data.at(right);
			data.at(right) = temp;
			left++;
			right--;
		}

		//Recursive calls, splitting the list into smaller parts.

		if (start < right)
		{
			sort(start,right);
		}

		if (left < end)
		{
			sort(left,end);
		}
	}
}