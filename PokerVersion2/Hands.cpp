#include "Hands.h"

Deck<string> dk;

vector<string> Hands::createdeck(vector<string>& deck)
{
	//Deck<string> dk;
	//deck = dk.createdeck(deck);
	//deck = dk.shuffle(deck);
	deck = dk.createdeck(deck);
	deck = dk.shuffle(deck);
	//m->setCurrent(new SHUFFLE_STATE());
	//ss.setDeck(deck);
	return deck;
}


//pushback to hands
vector<string> Hands::dealCards(vector<string>& deck,vector<string> passedHand, int num)
{

	//hand.clear();

	for (int i = 0; i < num; i++)
	{
		passedHand.push_back(deck.back());
		deck.pop_back();
	}


	return passedHand;
}


vector<string> Hands::completeHand(vector<string> tablehand, vector<string> passedHand)
{
	vector<string>completeHand;

	completeHand.clear();

	for (string item : tablehand)
	{
		completeHand.push_back(item);
	}
	for (string item : passedHand)
	{
		completeHand.push_back(item);
	}

	return completeHand;

}

vector<char> Hands::getSuit(vector<string>passedHand)
{
	vector<char> passedSuits;
	passedSuits.clear();
	for (string item : passedHand)
	{
		passedSuits.push_back(item.at(1));
	}
	return passedSuits;
}
vector<int> Hands::handValue(vector<string>passedhand)
{
	int n;
	vector<int> passedValues;
	passedValues.clear();
	for (string item : passedhand)
	{
		if (item.at(0) == *"2")
		{
			n = 2;
		}
		if (item.at(0) == *"3")
		{
			n = 3;
		}
		if (item.at(0) == *"4")
		{
			n = 4;
		}
		if (item.at(0) == *"5")
		{
			n = 5;
		}
		if (item.at(0) == *"6")
		{
			n = 6;
		}
		if (item.at(0) == *"7")
		{
			n = 7;
		}
		if (item.at(0) == *"8")
		{
			n = 8;
		}

		if (item.at(0) == *"9")
		{
			n = 9;
		}

		if (item.at(0) == *"T")
		{
			n = 10;
		}
		if (item.at(0) == *"J")
		{
			n = 11;
		}
		if (item.at(0) == *"Q")
		{
			n = 12;
		}
		if (item.at(0) == *"K")
		{
			n = 13;
		}
		if (item.at(0) == *"A")
		{
			n = 14;
		}
		passedValues.push_back(n);
	}
	return passedValues;
}