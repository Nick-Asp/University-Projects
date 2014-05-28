#ifndef SORT
#define SORT

#include <vector>

class Sort
{
public:
	Sort(std::vector<int> v);
	virtual void sort();
	std::vector<int> getData();

protected:
	std::vector<int> data;
};

#endif