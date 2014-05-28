#include "RecursiveBinarySearch.h"
#include <iostream>

using namespace std;
	
RecursiveBinarySearch::RecursiveBinarySearch(){}

bool RecursiveBinarySearch::search(std::vector<int> v, int left, int right, int searchTerm){

	int mid = ((left+right)/2);

	if (left > right)
	{
		return false;
	}

	//Recursive calls, using the new smaller list.

	else if ((v.at(mid) > searchTerm))
	{
		return search(v,left, mid - 1,searchTerm);
	}

	else if((v.at(mid) < searchTerm)){

		return search(v,mid + 1,right,searchTerm);
	}

	else{
		
		return true;
	}
}