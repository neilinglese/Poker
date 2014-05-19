#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include "Aesthetics.h"

template <typename T> 
class Deck
{
private:
	vector<T> original;
	vector<T> playable;

public:
	typedef typename std::vector<T>::size_type SizeType;


	void reset();
	vector<T> shuffle(vector<T> playable);
	vector<T> createdeck(vector<T> playable);
};


template <class T> void Deck<T>::reset()
{
	playable = original;
}

template <class T> vector<T> Deck<T>::shuffle(vector<T> playable)
{
	if (!playable.empty())
	{
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(playable.begin(), playable.end());
	}
	return playable;
}

template <class T> vector<T> Deck<T>::createdeck(vector<T> playable)
{


	const int suits = 4;
	const int values = 13;
	string cardValue[] = { "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	string cardSuit[] = { "H", "D", "S", "C" };
	string card;
	

	for (size_t i = 0; i < suits; ++i)
	{
		for (size_t j = 0; j < values; ++j)
		{
			if (playable.size() < 52)
			{
				card = cardValue[j] + cardSuit[i];
				playable.push_back(card);
			}

		}
	}
	return playable;


}

#endif