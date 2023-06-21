#include "Olympic.h"
#include <cmath>
#include <iomanip>

void Olympic::readData() {
	for (int i = 0; i < numOfParticipants; i++) {
		explorer >> participants[i].id;
		explorer >> participants[i].score;
	}
}
void Olympic::setBasicFields() {}
void Olympic::setGrade() {
	char evaluations[] = { 'F', 'F','F','F','F','F','D','C','B','A','A'};
	for (int i = 0; i < numOfParticipants; i++) {
		int index = participants[i].score / 10;
		participants[i].grade = evaluations[index];
	}
}
void Olympic::setAverage() {
	int sum = 0;
	for (int i = 0; i < numOfParticipants; i++)
		sum += participants[i].score;

	resultAverage = static_cast<double>(sum) / numOfParticipants;

}
void Olympic::setDeviation() {
	
	standardDeviation = 0.0;
	for (int i = 0; i < numOfParticipants; i++) {
		participants[i].deviation = participants[i].score - resultAverage;
		standardDeviation += pow(participants[i].deviation, 2);
	}
	standardDeviation = sqrt(standardDeviation) / numOfParticipants;
}
void Olympic::printAllResult() const {
	cout << endl;
	cout << "ID    ���� ���   ����" << endl;
	cout << "---- ---- ---- -------" << endl;

	for (int i = 0; i < numOfParticipants; i++) {
		cout << setw(4) << noshowpoint << noshowpos;
		cout << right << participants[i].id;
		cout << setw(14) << noshowpoint << noshowpos;
		cout << right << participants[i].score;
		cout << setw(10) << right << participants[i].grade;
		cout << fixed << setw(20) << right << setprecision(2);
		cout << showpoint << showpos;
		cout << participants[i].deviation << endl;
	}

	cout << "��� ����:  " << fixed << setw(4);
	cout << setprecision(2) << resultAverage << endl;
	cout << "ǥ�� ����: " << standardDeviation << endl;
}




Olympic::Olympic(int numOfP, const char* File)
	: numOfParticipants(numOfP), theDataFile(File)
{
	participants = new Participant[numOfP];
	explorer.open(theDataFile);
	readData();
	setBasicFields();
	setGrade();
	setAverage();
	setDeviation();
	printAllResult();
}
Olympic::~Olympic() {
	delete[] participants;
	explorer.close();
}