#ifndef QUICKSORT
#define QUICKSORT

#include "Sort.h"

class QuickSort : public Sort
{
public:
	QuickSort(std::vector<int> v);
	void sort(int start, int end);
};

#endif