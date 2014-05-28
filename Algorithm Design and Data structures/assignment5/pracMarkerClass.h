#ifndef PRACMARKERCLASS
#define PRACMARKERCLASS

#include <fstream>
#include <string>
#include <vector>

class pracMarkerClass
{

public:
	
	pracMarkerClass(std::ifstream &pracMarks);
	float outputAverage();

private:

	std::vector<std::vector<int> > scores;
	std::vector<std::string> pracMarkerEntrys;

};

#endif