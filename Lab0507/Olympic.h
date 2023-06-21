// #pragma once

#ifndef OLYMPIC_H
#define OLYMPIC_H

#include <iostream>
#include <fstream>
using namespace std;

class Olympic {
private:
	int numOfParticipants;
	ifstream explorer;
	const char* theDataFile;
	struct Participant {
		int id;
		int score;
		char grade;
		double deviation;
	};
	Participant* participants;
	double resultAverage;
	double standardDeviation;

	void readData();
	void setBasicFields();
	void setGrade();
	void setAverage();
	void setDeviation();
	void printAllResult() const;

public:
	Olympic(int numOfParticipants, const char* theDataFile);
	~Olympic();
};

#endif