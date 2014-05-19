#ifndef POKER_H
#define POKER_H



class Poker
{
public:
	void createdeck(vector<string>& deck);
	//void shuffle(vector<string>& deck);
	void playercard(vector<string>& deck);
	void cpucard(vector<string>&deck);
	void tablecards(vector<string>& deck, int);
	vector<string> suits(vector<string>, string);
	void createhand(vector<string> hand, int, int);
	void createtable(vector<string>, int, int);
	void DrawingCards(string, vector<string>, int, int, int);
	/*void drawcpucard(vector<string>, int, int);*/
	void drawcpucard2(vector<string>, int, int);
	void drawdefaultcpu(vector<string>, int, int);
	void drawcpudefault(string, vector<string>, int, int, int);
	void playerCompleteHand(vector<string>, vector<string>);
	void playerSuit(vector<string>);
	void playerValue(vector<string>);
	void computerCompleteHand(vector<string>, vector<string>);
	void computerSuit(vector<string>);
	void computerValue(vector<string>);

	
};

#endif