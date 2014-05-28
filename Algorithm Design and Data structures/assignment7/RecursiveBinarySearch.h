#ifndef RECURSIVEBINARYSEARCH
#define RECURSIVEBINARYSEARCH

#include <vector>

class RecursiveBinarySearch
{
public:
	RecursiveBinarySearch();
	bool search(std::vector<int> v,int left, int right, int searchTerm);
};

#endif