#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "Hands.h"
#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "Deck.h"
#include "DrawCard.h"


using namespace std;
class Machine
{
	class State *current;

public:
	Machine();
	void setCurrent(State *s);
};


class State
{

public:
	Aesthetics aesthetics;
};

class PREGAME_STATE : public State
{
public:
	PREGAME_STATE()
	{
		system("cls");
		aesthetics.ifTrueChangeUserAlert = true;
		aesthetics.SetWindow(100, 55); // Set windows size
		aesthetics.centerWindow();
		aesthetics.header(); // calling our game header
		aesthetics.MainMenu(); // calling our menu system
	}

	~PREGAME_STATE()
	{
		cout << " dtor-PREGAME_STATE\n";
	}

};






#endif