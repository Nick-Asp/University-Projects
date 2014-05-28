#include "moodleOfficialCheck.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

moodleOfficialCheck::moodleOfficialCheck(){}

void moodleOfficialCheck::takeInput(ifstream& moodle,ifstream& official){

	//Loading input into string array's.

		string line;

		while (getline(moodle,line)){

			moodleEntrys.push_back(line);
		}

		while (getline(official,line)){

			officialEntrys.push_back(line);
		}

	line.erase();

	//Loading all input ID numbers into integer arrays

	int counter = 0;

	//Official list ID's
	//Official ID's start from the beginning of the file and so the loop stops when it finds it's first ','

	for (unsigned int i = 1; i < officialEntrys.size(); ++i)
	{
		while(officialEntrys.at(i).at(counter) != ','){

			line.push_back(officialEntrys.at(i).at(counter));

			counter++;
		}

		istringstream(line) >> counter;

		officialIdNos.push_back(counter);

		counter = 0;

		line.erase();

	}

	//Moodle list ID's
	//Moodle id's are found in the file and so we search for ",a" as this starts the ID.

	line.erase();

	counter = 0;

	unsigned int found;

	for (unsigned int i = 1; i < moodleEntrys.size(); ++i)
	{
		found = moodleEntrys.at(i).find(",a") + 2;

		while(moodleEntrys.at(i).at(found + counter) != ','){

			line.push_back(moodleEntrys.at(i).at(found + counter));

			counter++;
		}

		istringstream(line) >> counter;

		moodleIdNos.push_back(counter);

		counter = 0;

		found = 0;

		line.erase();

	}

	//Uses ID checker to get all the differences in the lists.

	notOfficiallyRegistered = idChecker(moodleIdNos.size(),officialIdNos.size(),moodleIdNos,officialIdNos);
	
	notOnMoodle = idChecker(officialIdNos.size(),moodleIdNos.size(),officialIdNos,moodleIdNos);

	//Sorting into ascending order
	sort(notOfficiallyRegistered.begin(),notOfficiallyRegistered.end());
	sort(notOnMoodle.begin(),notOnMoodle.end());
}

void moodleOfficialCheck::outputDifferences(){

	//Formats and outputs the data collected.
		for (unsigned int i = 0; i < notOnMoodle.size(); ++i)
	{

		cout << 'a' << notOnMoodle.at(i);

		if (i != notOnMoodle.size() - 1)
		{
			cout << ',';
		}

		else{
			cout << ' ';
		}
	}

		for (unsigned int i = 0; i < notOfficiallyRegistered.size(); ++i)
	{

		cout << 'a' << notOfficiallyRegistered.at(i);

		if (i != notOfficiallyRegistered.size() - 1)
		{
			cout << ',';
		}
	}
}

std::vector<int> moodleOfficialCheck::idChecker(int length1, int length2, vector<int> comparitor1Array, vector<int> comparitor2Array){

	//Compares values in vector1 and vector2 and returns all values in vector 2 that aren't in vector 1
	vector<int> returnVector;

	bool inArray = false;

	for (int j = 0; j < length1; ++j)
		{
			for (unsigned int i = 0; i < length2; ++i)
			{
				if (comparitor1Array[j] == comparitor2Array[i])
				{
					inArray = true;
					
					break;
				}
			}

			if (!inArray)
			{

					returnVector.push_back(comparitor1Array[j]);
			}

			else
			{
				inArray = false;
			}
		} 

		return returnVector;
}
