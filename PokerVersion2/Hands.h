#ifndef HANDS_H
#define HANDS_H
#include "State.h"
#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "Deck.h"
#include "DrawCard.h"


class Hands
{
public:
	vector<string> createdeck(vector<string>& deck);
	vector<string> dealCards(vector<string>& deck,vector<string>,int);
	vector<string> cpucard(vector<string>&deck,vector<string>);
	vector<string> tablecards(vector<string>& deck,vector<string>, int x); 
	vector<string> completeHand(vector<string> tablehand, vector<string> passedHand);
	vector<int> handValue(vector<string> passedHand);
	vector<char> getSuit(vector<string>passedHand);
	
};

#endif