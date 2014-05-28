#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "pracMarkerClass.h"

using namespace std;

pracMarkerClass::pracMarkerClass(std::ifstream &pracMarks){

	string line;

	//Loading the prac marker entry's array

		while (getline(pracMarks,line)){

			pracMarkerEntrys.push_back(line);
		}

		//Filling the 2D int vector with 0's for ease in average calculations later on.
		//This is as the progam donesn't find any scores, just ',' than there are already
		//0's loaded in the vector.
		for (unsigned int i = 0; i < pracMarkerEntrys.size(); ++i)
		{
			std::vector<int> tempInt;

			for (int j = 0; j < 4 ; ++j)
			{
				tempInt.push_back(0);
			}

			scores.push_back(tempInt);
		}

		int testInt, counter = 0;

		bool alreadyThere = false;

		//Loading the ID no's into the first column of the 2D vector 
		for (unsigned int i = 1; i < pracMarkerEntrys.size(); ++i)
		{
			unsigned int idNoLength,count;

			idNoLength = 0;

			count = 0;

			//Getting the length of the id no.s for use later in the program.

			while(pracMarkerEntrys.at(i).at(count) != ',' || count -1 == pracMarkerEntrys.at(i).size()){

				idNoLength++;
				count ++;
			}

			for (unsigned int k = i; k < pracMarkerEntrys.size(); ++k)
			{
				if (i == k){}
				
				else
				{
					//Starts at the character after the , after the Id number.
					for(unsigned int p = 0; p < idNoLength+1; p++)
					{
						line.push_back(pracMarkerEntrys.at(i).at(p));

					}
						//Line if filled with the ID no. string and a string stream is used to convert it into an integer.
						istringstream(line) >> testInt;

						line.erase();

						for (unsigned int y = 0; y < pracMarkerEntrys.size(); ++y)
						{
							if (scores[y][0] == testInt)
							{
									alreadyThere = true;

							}
						}

						if (!alreadyThere)
						{
							scores.at(counter).at(0) = testInt;

							counter++;
						}

						else{

							alreadyThere = false;
						}
					}
				}
			}

	//Loading the scores
	for (unsigned int i = 1; i < pracMarkerEntrys.size(); ++i)
	{

		unsigned int idNoLength,count;

			idNoLength = 0;

			count = 0;

			while(pracMarkerEntrys.at(i).at(count) != ',' || count -1 == pracMarkerEntrys.at(i).size()){

				idNoLength++;
				count ++;
			}

		for(unsigned int p = 0; p < idNoLength+1; p++)
		{
		
			line.push_back(pracMarkerEntrys.at(i).at(p));
		
		}
		
		istringstream(line) >> testInt;

		line.erase();

		for (unsigned int k = 0; k < pracMarkerEntrys.size(); ++k)
		{
			if (scores.at(k).at(0) == testInt)
			{	
				unsigned int counter = 1;
				//If the function finds a score and the score is greater than the orignal score than the original score is increased to this new score.
				//This is as the score only increases of stays the same.
				for (unsigned int n = idNoLength+1; n < (pracMarkerEntrys.at(i).size()); ++n)
				{	
					if (pracMarkerEntrys.at(i).at(n) == ','){

						counter++;
					}

					else if(counter < 4){
					
						scores.at(k).at(counter) = pracMarkerEntrys.at(i).at(n) - '0';
						
					}
				}
			}
		}
	}
}

//Calculates and outupts the average
float pracMarkerClass::outputAverage(){

int no = 0;

float average = 0;

	for (unsigned int i = 0; i < pracMarkerEntrys.size(); ++i)
	{
		for (int j = 1; j < 4 ; ++j)
		{
			average += scores.at(i).at(j);
		}

		if (scores.at(i).at(0) > 0)
		{
			no++;	
		}
	}

	average = average/no;

	return average;
}