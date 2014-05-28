#ifndef MOODLEOFFICIALCHECK
#define MOODLEOFFICIALCHECK

#include <fstream>
#include <string>
#include <vector>

class moodleOfficialCheck
{

public:
	moodleOfficialCheck();

	void outputDifferences();
	void takeInput(std::ifstream &moodle,std::ifstream &official);
	std::vector<int> idChecker(int length1, int length2, std::vector<int> comparitor1Array, std::vector<int> comparitor2Array);

private:

		std::vector<std::string> moodleEntrys;
		std::vector<std::string> officialEntrys;
		std::vector<int> notOnMoodle;
		std::vector<int> notOfficiallyRegistered;
		std::vector<int> moodleIdNos;
		std::vector<int> officialIdNos;

};

#endif