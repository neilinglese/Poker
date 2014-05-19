#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"



Checks::Checks()
{

}
int Checks::ispair(vector<int> determineValues)
{
	test.clear();

	sort(determineValues.begin(), determineValues.end());

	for (size_t z = 0; z < determineValues.size(); z++)
	{
		for (size_t j = 0; j < determineValues.size(); j++)
		{
			if (j != z)
			{
				if (determineValues[z] == determineValues[j])
				{
					test.push_back(determineValues[z]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 2 && test.size() < 4)
	{
		return 1;
	}

	if (test.size() >= 4 && test.size() <= 6)
	{
		return 2;
	}

	else
		return 0;
}

int Checks::flush(vector<char> determineSuits)
{
	test.clear();
	
	sort(determineSuits.begin(), determineSuits.end());

	for (size_t z = 0; z < determineSuits.size(); z++)
	{
		for (size_t j = 1; j < determineSuits.size(); j++)
		{
			if (j != z)
			{
				if (determineSuits[z] == determineSuits[j])
				{
					test.push_back(determineValues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 20 && test.size() <= 35)
	{
		return 1;
	}
	else
		return 0;

	return 0;


}
//working
int Checks::straight(vector<int>determineValues)
{
	sort(determineValues.begin(), determineValues.end());

	if (determineValues.size() == 5)
	{
		if ((determineValues[4] - determineValues[3] == 1) && (determineValues[3] - determineValues[2] == 1) && (determineValues[2] - determineValues[1] == 1) && (determineValues[1] - determineValues[0] == 1))
			return 1;
		else
			return 0;
	}
	if (determineValues.size() == 6)
	{
		if ((determineValues[4] - determineValues[3] == 1) && (determineValues[3] - determineValues[2] == 1) && (determineValues[2] - determineValues[1] == 1) && (determineValues[1] - determineValues[0] == 1))
			return 1;
		else if ((determineValues[5] - determineValues[4] == 1) && (determineValues[4] - determineValues[3] == 1) && (determineValues[3] - determineValues[2] == 1) && (determineValues[2] - determineValues[1] == 1))
			return 1;
		else
			return 0;
	}
	if (determineValues.size() == 7)
	{
		if ((determineValues[4] - determineValues[3] == 1) && (determineValues[3] - determineValues[2] == 1) && (determineValues[2] - determineValues[1] == 1) && (determineValues[1] - determineValues[0] == 1))
			return 1;
		else if ((determineValues[5] - determineValues[4] == 1) && (determineValues[4] - determineValues[3] == 1) && (determineValues[3] - determineValues[2] == 1) && (determineValues[2] - determineValues[1] == 1))
			return 1;
		else if ((determineValues[6] - determineValues[5] == 1) && (determineValues[5] - determineValues[4] == 1) && (determineValues[4] - determineValues[3] == 1) && (determineValues[3] - determineValues[2] == 1))
			return 1;
		else
			return 0;
	}
	else
		return 0;
} // end straight.
//working
int Checks::threeofakind(vector<int> determineValues)
{

	test.clear();

	sort(determineValues.begin(), determineValues.end());

	for (size_t z = 0; z < determineValues.size(); z++)
	{
		for (size_t j = 1; j < determineValues.size(); j++)
		{
			if (j != z)
			{
				if (determineValues[z] == determineValues[j])
				{
					test.push_back(determineValues[z]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 6 && test.size() <= 9)
	{
		return 1;
	}

	else
		return 0;

}//working
//working 
int Checks::fourofakind(vector<int> determineValues)
{
	
	test.clear();
	//int z;
	sort(determineValues.begin(), determineValues.end());

	for (size_t z = 0; z < determineValues.size(); z++)
	{
		for (size_t j = 1; j < determineValues.size(); j++)
		{
			if (j != z)
			{
				if (determineValues[z] == determineValues[j])
				{
					test.push_back(determineValues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 12 && test.size() <= 22)
	{
		return 1;
	}
	else
		return 0;

}
//working
int Checks::fullhouse(vector<int> determineValues)
{
	test.clear();
	
	sort(determineValues.begin(), determineValues.end());

	for (size_t z = 0; z < determineValues.size(); z++)
	{
		for (size_t j = 0; j < determineValues.size(); j++)
		{
			if (j != z)
			{
				if (determineValues[z] == determineValues[j])
				{
					test.push_back(determineValues[j]);

				}
			}
		}
	} // end loop.
	if (test.size() >= 8 && test.size() <= 12)
	{
		return 1;
	}
	else
		return 0;

	return 0;
}

int Checks::highCardValues(vector<string>passedHand)
{
	int val;
	vector<int> testValue;
	testValue.clear();

	for (string item : passedHand)
	{
		if (item.at(0) == *"A")
		{
			val = 14;
		}
		if (item.at(0) == *"K")
		{
			val = 13;
		}
		if (item.at(0) == *"Q")
		{
			val = 12;
		}
		if (item.at(0) == *"J")
		{
			val = 11;
		}
		if (item.at(0) == *"T")
		{
			val = 10;
		}
		if (item.at(0) == *"9")
		{
			val = 9;
		}
		if (item.at(0) == *"8")
		{
			val = 8;
		}
		if (item.at(0) == *"7")
		{
			val = 7;
		}
		if (item.at(0) == *"6")
		{
			val = 6;
		}
		if (item.at(0) == *"5")
		{
			val = 5;
		}
		if (item.at(0) == *"4")
		{
			val = 4;
		}
		if (item.at(0) == *"3")
		{
			val = 3;
		}
		if (item.at(0) == *"2")
		{
			val = 2;
		}


		testValue.push_back(val);
	}
	sort(testValue.begin(), testValue.end());

	return testValue.at(1);
}


// determing hand checks
int Checks::DetermineHand(vector<int >values, vector<char>suits)
{
	determineValues.empty();
	determineSuits.empty();
	determineValues = values;
	determineSuits = suits;

	sort(determineValues.begin(), determineValues.end());

	if ((flush(determineSuits)) && (straight(determineValues)))
	{
		if (determineValues[7] == 14)
		{
			return 100;
		}
		else
		{
			return 90;
		}
	}
	else if (flush(determineSuits) == 1)
	{
		return 80;
	}
	else if (straight(determineValues) == 1)
	{
		return 70;
	}
	else if (fourofakind(determineValues) == 1)
	{
		return 60;
	}
	else if (fullhouse(determineValues) == 1)
	{
		return 50;
	}
	else if (threeofakind(determineValues) == 1)
	{
		return 40;
	}
	else if (ispair(determineValues) == 2)
	{
		return 30;
	}
	else if (ispair(determineValues) == 1)
	{
		return 20;
	}
	else 
	{
		return determineValues.back();
	}
}

string Checks::handText(int val)
{
	if (val == 100)
	{
		return "Royal Flush!!";
	}
	else if (val == 90)
	{
		return "Straight Flush!!";
	}
	else if (val == 80)
	{
		return "Flush!!";
	}
	else if (val == 70)
	{
		return "Straight!!";
	}
	else if (val == 60)
	{
		return "Four of a Kind!!";
	}
	else if (val == 50)
	{
		return "FullHouse";
	}
	else if (val == 40)
	{
		return "Three of a Kind!!";
	}
	else if (val == 30)
	{
		return "Two Pair!!";
	}
	else if (val == 20)
	{
		return "Pair!!";
	}
	else
	{
		return  "Absolutely Nothing!!";
	}
}
//determine the winner

void Checks::FoldValue(bool playerFold,int cash,int cpucash,int pot,int bet)
{
	if (playerFold)
	{
		cpucash = cpucash + pot;
		cash = cash - bet;
	}
}
void Checks::FoldValueC(bool playerFold, int cash, int cpucash, int pot, int bet)
{
	if (playerFold)
	{
		cash = cash + pot;
		cpucash = cpucash - bet;
	}
}
