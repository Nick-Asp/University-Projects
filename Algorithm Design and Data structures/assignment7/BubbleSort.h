#ifndef BUBBLESORT
#define BUBBLESORT

#include "Sort.h"


class BubbleSort : public Sort
{
public:
	BubbleSort(std::vector<int> v);
	void sort();

};

#endif