#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "moodleOfficialCheck.h"
#include "pracMarkerClass.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//Opening the files
	ifstream moodle;
	ifstream official;
	ifstream pracMarks;

	pracMarks.open("pracmarker.csv");

	moodle.open("moodlelist.csv");
	
	official.open("officiallist.csv");

	moodleOfficialCheck newChecker;

	pracMarkerClass newMarker(pracMarks);

	newChecker.takeInput(moodle,official);
	newChecker.outputDifferences();

	cout << " " << newMarker.outputAverage();

	official.close();

	moodle.close();

	return 0;
}
