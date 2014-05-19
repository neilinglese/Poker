#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H



class ComputerPlayer
{
public:

	vector<string> cpuhand;
	vector<char> csuits;
	vector<int> cvalues;
	vector<string> computerhand;

	int CpuHandValue;
	int cpubet;
	int cpucash;
	int cpuHighCardValue;

	string computerHandText;
	string name;

	bool didFold;
	int didStart;

	int cardX;
	int cardY;
	int cardbackColor;
};

#endif





