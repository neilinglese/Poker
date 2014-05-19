// State.cpp : Defines the entry point for the console application.
//
#include "State.h"

void Machine::setCurrent(State *s)
{
	current = s;
}

Machine::Machine()
{
	current = new PREGAME_STATE();
	cout << '\n';
}