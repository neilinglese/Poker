#ifndef DRAWCARD_H
#define DRAWCARD_H



class DrawCard
{

public:

	vector<string>cards;

	void DrawingCards(string, vector<string>, int, int, int);

	void createhand(vector<string> passedCards, int x, int y);

	void drawCardBack(vector<string> passedCards, int x, int y,int);

	vector<string> suits(vector<string> passedCards, string suit);
};

#endif