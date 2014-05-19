#ifndef CHECKS_H
#define CHECKS_H


class Checks
{
public:

	vector<int> determineValues;
	vector<char> determineSuits;
	vector<int> test;

	int ispair(vector<int> determineValues);
	int flush(vector<char> determineSuits);
	int straight(vector<int> determineValues);
	int threeofakind(vector<int> determineValues);
	int fourofakind(vector<int> determineValues);
	int fullhouse(vector<int> determineValues);
	int FindHighCard(vector<string>,vector<string>);
	int DetermineHand(vector<int >values, vector<char>suits);
	void FoldValue(bool,int,int,int,int);
	void FoldValueC(bool,int,int,int,int);
	int highCardValues(vector<string>);
	string handText(int);
	Checks();
};

#endif