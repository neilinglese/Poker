#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Deck.h"
#include "DrawCard.h"
#include "Hands.h"
#include "State.h"
#include <map>


Hands hands;
DrawCard drawcard;
Checks checks;
Aesthetics aesthetics;

GamePlay::GamePlay() 
{
	
}
void GamePlay::loadingPlayers(vector<ComputerPlayer> cp)
{
	listOfComputerPlayers = cp;
	Start();
}
//clears
void GamePlay::Clear()
{
	pot = 0;
	result = "";
	inhand = "";
	playerhand.clear();
	deck.clear();
	hand.clear();
	tablehand.clear();
	psuits.clear();
	PlayerValues.clear();

	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{

		listOfComputerPlayers[i].cpuhand.clear();
		listOfComputerPlayers[i].computerhand.clear();
		
		listOfComputerPlayers[i].cvalues.clear();
		listOfComputerPlayers[i].csuits.clear();
	}
}

void GamePlay::Clears()
{
	playerhand.clear();
	psuits.clear();
	PlayerValues.clear();

	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].computerhand.clear();
		listOfComputerPlayers[i].csuits.clear();
		listOfComputerPlayers[i].cvalues.clear();
	}
}

void GamePlay::Cards()
{


	Clears();

	playerhand = hands.completeHand(tablehand, hand);
	psuits = hands.getSuit(playerhand);
	PlayerValues = hands.handValue(playerhand);
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].computerhand = hands.completeHand(tablehand, listOfComputerPlayers[i].cpuhand);
		listOfComputerPlayers[i].csuits = hands.getSuit(listOfComputerPlayers[i].computerhand);
		listOfComputerPlayers[i].cvalues = hands.handValue(listOfComputerPlayers[i].computerhand);

	}
}

void GamePlay::Setup()
{
	PlayerHandValue = 0;
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].CpuHandValue = 0;
	}
	result = "";

}

void GamePlay::uiText()
{
	system("cls");
	
	if (listOfComputerPlayers.size() == 1)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, listOfComputerPlayers[0].cardX, listOfComputerPlayers[0].cardY, listOfComputerPlayers[0].cardbackColor);
	}
	if (listOfComputerPlayers.size() == 2)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, listOfComputerPlayers[0].cardX, listOfComputerPlayers[0].cardY, listOfComputerPlayers[0].cardbackColor);
		drawcard.drawCardBack(listOfComputerPlayers[1].cpuhand, listOfComputerPlayers[1].cardX, listOfComputerPlayers[1].cardY, listOfComputerPlayers[1].cardbackColor);
	}
	if (listOfComputerPlayers.size() == 3)
	{
		drawcard.createhand(hand, 1, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, listOfComputerPlayers[0].cardX, listOfComputerPlayers[0].cardY, listOfComputerPlayers[0].cardbackColor);
		drawcard.drawCardBack(listOfComputerPlayers[1].cpuhand, listOfComputerPlayers[1].cardX, listOfComputerPlayers[1].cardY, listOfComputerPlayers[1].cardbackColor);
		drawcard.drawCardBack(listOfComputerPlayers[2].cpuhand, listOfComputerPlayers[2].cardX, listOfComputerPlayers[2].cardY, listOfComputerPlayers[2].cardbackColor);
	}
	//drawcard.drawCardBack(listOfComputerPlayers[0].cpuhand, 24, 3);

	if (!showComputer)
	{
		for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
		{
			listOfComputerPlayers[i].computerHandText = "?????";
		}
	}
	if (!shows)
	{
		PressEnterToContinue = " ";
	}
	if (!foldc)
	{
		fold = " ";
	}

	inhand = checks.handText(PlayerHandValue);

	aesthetics.mainText("1");

	//CHANGE ME
	aesthetics.changingText(cash, inhand, listOfComputerPlayers, fold, pot, result);
	
}

int GamePlay::transferCpuBetToAesthetics(int _cpubet)
{
	//CHANGE ME
	_cpubet = listOfComputerPlayers[0].cpubet;

	return _cpubet;
}

void GamePlay::Start() //What user will see first, displays start money (Omoney)
{
	
	Clear();
	system("cls");
	pot = 0;
	cash = 200;
	nodeCount = 0;
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].cpucash = 200;
	}
	
	Flop();

}

void GamePlay::makeHands()
{
	
	deck = hands.createdeck(deck);
	tablehand = hands.dealCards(deck,tablehand, 3);
	hand = hands.dealCards(deck,hand,2);
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].cpuhand = hands.dealCards(deck, listOfComputerPlayers[i].cpuhand, 2);
		listOfComputerPlayers[i].computerHandText = "??????";
	}
	Cards();//creating the hands  
}
void GamePlay::Flop()
{
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].cardbackColor = 31;
		listOfComputerPlayers[i].didFold = false;
	}
	gameoverCheck();
	Setup();
	makeHands();
	getValues();
	uiText();
	betSystem();
	Turn();
}

void GamePlay::Turn()
{

	Setup();
	tablehand = hands.dealCards(deck, tablehand,  1);
	Cards();
	getValues();
	uiText();
	betSystem();
	River();
}

void GamePlay::River()
{
	Setup();
	tablehand = hands.dealCards(deck, tablehand, 1);
	Cards(); //creating the hands  
	getValues();
	uiText();
	betSystem();
	finalCards();
}

void GamePlay::finalCards()
{
	//CHANGE ME
	PlayerHandValue = 0;
	listOfComputerPlayers[0].CpuHandValue = 0;
	showComputer = true;
	shows = true;

	system("cls");
	if (tablehand.size() < 4)
	{

		tablehand = hands.dealCards(deck, tablehand, 2);
	}
	if (tablehand.size() < 5)
	{

		tablehand = hands.dealCards(deck, tablehand, 1);
	}
	Cards();
	getValues();
	
	if (playerFold == true)
	{
		PlayerHandValue = 0;
	}
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{

			listOfComputerPlayers[i].computerHandText = checks.handText(listOfComputerPlayers[i].CpuHandValue);
		
	}

	determine();

	uiText();

	if (listOfComputerPlayers.size() == 1)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.createhand(listOfComputerPlayers[0].cpuhand, 24, 3);
	}
	if (listOfComputerPlayers.size() == 2)
	{
		drawcard.createhand(hand, 25, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.createhand(listOfComputerPlayers[0].cpuhand, 1, 3);
		drawcard.createhand(listOfComputerPlayers[1].cpuhand, 60, 3);
	}
	if (listOfComputerPlayers.size() == 3)
	{
		drawcard.createhand(hand, 1, 40);
		drawcard.createhand(tablehand, 5, 20);
		drawcard.createhand(listOfComputerPlayers[0].cpuhand, 1, 3);
		drawcard.createhand(listOfComputerPlayers[1].cpuhand, 60, 3);
		drawcard.createhand(listOfComputerPlayers[2].cpuhand, 60, 40);
	}


	cin.get();


	gameoverCheck();

	Clear();
	system("cls");
	Flop();
}


//extracted and created a function so i can check if player or cpu had no money at the start of flop
void GamePlay::gameoverCheck()
{
	//CHANGE ME

	if (cash <= 0)
	{
		aesthetics.OutOfMoney("You");
	}
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		if (listOfComputerPlayers[i].cpucash <= 0)
		{
			//listOfComputerPlayers.erase(&listOfComputerPlayers.at(i));
		}
	}



}

void GamePlay::getValues()
{

	PlayerHandValue = 0;
	PlayerHandValue = checks.DetermineHand(PlayerValues, psuits);
	inhand = checks.handText(PlayerHandValue);
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].CpuHandValue = 0;
		listOfComputerPlayers[i].CpuHandValue = checks.DetermineHand(listOfComputerPlayers[i].cvalues, listOfComputerPlayers[i].csuits);
	}
}


//THIS NEEDS ALOT WORK
//bet system stuff in here
void GamePlay::betSystem()
{




		// method for cpu betting logic, passing in CpuHandValue to determine what it does

		// storing the variable returned from menu class to bet
		bet = aesthetics.gameplayMenu();

		if (bet == 100)
		{
			allin = true;
			bet = 100;
			getValues();
			Betting(bet);

			for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
			{
				CpuBetting(listOfComputerPlayers[i].CpuHandValue, listOfComputerPlayers[i].name, listOfComputerPlayers[i].cpubet, listOfComputerPlayers[i].cpucash);
			}
			finalCards();
		}
		if (bet == 200)
		{
			playerFold = true;
			finalCards();
		}

		//needs a bool if the cpu didnt fold only to do these, if it did fold dont do them
		getValues();
		Betting(bet); // player betting method passing in the value stored at bet

		for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
		{
			CpuBetting(listOfComputerPlayers[i].CpuHandValue, listOfComputerPlayers[i].name, listOfComputerPlayers[i].cpubet, listOfComputerPlayers[i].cpucash);
		}
	
	
	
}
void GamePlay::Betting(int bet)
{
	if (cash > 0)
	{
		if (bet == 200)
		{
			playerFold = true;
			finalCards();
		}
		if (bet == 100)
		{

			bet = cash;
			cash = cash - bet;
			pot = pot + bet;
		}
		else if (bet == 50)
		{
			bet = 50;
			cash = cash - bet;
			pot = pot + bet;
		}
		else if (bet == 10)
		{
			bet = 10;
			cash = cash - bet;
			pot = pot + bet;
		}
		else if (bet == 0)
		{
			bet = 0;
			playerCheck = true;
			cash = cash - bet;
			pot = pot + bet;
		}
	}
}

void GamePlay::raiseMenu(int cpube2t)
{
	bet = aesthetics.raiseMenu(listOfComputerPlayers[0].cpubet);
	Betting(bet);
	bet = aesthetics.gameplayMenu();
}

void GamePlay::CpuBetting(int CpuHandValue, string name, int cpubet, int cpucash)
{
	aesthetics.receiveCurrentVectorFromGP(listOfComputerPlayers);
	if (listOfComputerPlayers.size() == 3)
	{
		if (nodeCount > 2)
		{
			nodeCount = 0;
		}
	}

	if (listOfComputerPlayers.size() == 2)
	{
		if (nodeCount > 1)
		{
			nodeCount = 0;
		}
	}

	if (listOfComputerPlayers.size() == 1)
	{

		nodeCount = 0;
		if (playerCheck && !currentNode.didFold)
		{
			if (CpuHandValue < 50 && CpuHandValue >= 6)
			{

				//*****pseudo code for this behavior:*****//
				//*****random int between 1 and 100*****//
				random = rand() % 100;
				//random = 34;
				//*****if random int is between 1 and 34 *****//
				//*****cpu check*****//

				if (random < 35)
				{

					listOfComputerPlayers[nodeCount].cpubet = 10;
					listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
					pot = pot + listOfComputerPlayers[nodeCount].cpubet;
					//listOfComputerPlayers[nodeCount] = currentNode;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					aesthetics.receiveCurrentNodeFromGP(listOfComputerPlayers[nodeCount]);

					aesthetics.receiveCurrentVectorFromGP(listOfComputerPlayers);
				}
				//*****else if random int is between 35 and 60*****//
				//**********random int between 1 and 10*****//
				//**********if random int is between 1 and 3*****//
				else if (random >= 35 && random < 61)
				{
					newrandom = rand() % 10;
					if (newrandom < 4)
					{
						//**************check*****//
						listOfComputerPlayers[nodeCount].cpubet = 0;
						aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					}
					//**********else*****//
					//**************bet array 10, 50, all in*****//
					//**************randomly select one element*****//
					//**************cpuBet = randomlySelectedBetArrayElement*****//
					else
					{
						a = 10;
						b = 50;
						c = 100;
						betVector.push_back(a);
						betVector.push_back(b);
						betVector.push_back(c);
						int randomlySelectedFromBetVector;

						int selectWhichElementToPick = rand() % 3;

						if (selectWhichElementToPick == 1)
						{
							randomlySelectedFromBetVector = a;
						}
						else if (selectWhichElementToPick == 2)
						{
							randomlySelectedFromBetVector = b;
						}
						else
						{
							randomlySelectedFromBetVector = c;
						}

						listOfComputerPlayers[nodeCount].cpubet = randomlySelectedFromBetVector;
						listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
						pot = pot + listOfComputerPlayers[nodeCount].cpubet;
						aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
						//need to have player now have new menu for raise
						//bet = aesthetics.raiseMenu(cpubet);
					}
				}

				//*****else if random int is between 61 and 99*****//
				//**********cpu raise 50*****//
				else if (random >= 61 && random <= 99)
				{
					listOfComputerPlayers[nodeCount].cpubet = 50;
					listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
					pot = pot + listOfComputerPlayers[nodeCount].cpubet;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					//need to have player now have new menu for raise
				}
				//*****else if random int is 100*****//
				//**********cpu raise all in*****//
				else //basically saying if random = 100
				{
					listOfComputerPlayers[nodeCount].cpubet = listOfComputerPlayers[nodeCount].cpucash;
					listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
					pot = pot + listOfComputerPlayers[nodeCount].cpubet;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					//need to have player now have new menu for raise
				}

				//only run next lines if cpubet is not 0

				//need to make raise menu for player.
				aesthetics.ifTrueChangeOrigMenuToBlack = false;
				aesthetics.setBoolToAlertPlayer();
				aesthetics.mainText(name);

				//bet = aesthetics.gameplayMenu(); // storing the variable returned from menu class to bet
				//change Instructions to "ALERT: CPU raised [hit enter to call or fold]"
				raiseMenu(listOfComputerPlayers[nodeCount].cpubet);
				//playerCheck = false;
			}

			else if (CpuHandValue < 90 && CpuHandValue >= 50)
			{
				//so we should be having CPU raise a little more than he would check if his value is above 50.
				//57% of the time CPU should be raising by 10 or 50, 15% of the time raise 100, 2% of the time all in, and 26% of the time check

				//random = rand()% 100
				random = rand() % 100;

				if (random < 58)
				{
					int findBetForCpu = rand() % 100;
					if (findBetForCpu < 76)
					{
						//cpu bet = 10 (raise)
						//call aesthetics class to send cpu bet
						listOfComputerPlayers[nodeCount].cpubet = 10;
						aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					}

					else if (findBetForCpu >= 76)
					{
						//cpu bet = 50 (raise)
						//call aesthetics class to send cpu bet
						listOfComputerPlayers[nodeCount].cpubet = 50;
						aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					}
				}

				else if (random >= 58 && random < 74)
				{
					//cpu bet = 100 (raise)
					//call aesthetics class to send cpu bet

					listOfComputerPlayers[nodeCount].cpubet = 10;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				}

				else if (random >= 74 && random < 77)
				{
					//raise all in
					//call aesthetics class to send cpu bet
					listOfComputerPlayers[nodeCount].cpubet = listOfComputerPlayers[nodeCount].cpucash;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				}

				else if (random >= 77)
				{
					//check
					listOfComputerPlayers[nodeCount].cpubet = 0;
				}
			}
			//else if (CpuHandValue < 50 && CpuHandValue >= 6)
			//{
			//	//so we should be having CPU raise a little more than he would check if his value is above 50.
			//	//57% of the time CPU should be checking, 17% of the time raise 50, and 26% of the time raise by 10

			//	random = rand() % 100;

			//	if(random < 58)
			//	{
			//		//check
			//	}

			//	else if (random > 57 && random < 75)
			//	{
			//		//raise by 50
			//		//call aesthetics class to send cpu bet
			//	}

			//	else if (random > 74)
			//	{
			//		//raise by 10
			//		//call aesthetics class to send cpu bet
			//	}


			//}
			else if (CpuHandValue < 5)
			{

				//10% chance of a bet from CPU, otherwise check
				random = rand() % 10;

				if (random < 2)
				{
					//raise 10
					//call aesthetics class to send cpu bet
					listOfComputerPlayers[nodeCount].cpubet = 10;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

				}

				else
					//check
					listOfComputerPlayers[nodeCount].cpubet = 0;
			}

			playerCheck = false;
		}

		if (listOfComputerPlayers[nodeCount].cpucash > 0 && !playerCheck)
		{


			if (CpuHandValue >= 90)
			{

				listOfComputerPlayers[nodeCount].cpubet = listOfComputerPlayers[nodeCount].cpucash;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

			}
			else if (CpuHandValue < 90 && CpuHandValue >= 50)
			{
				listOfComputerPlayers[nodeCount].cpubet = 10;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

			}
			else if (CpuHandValue < 50 && CpuHandValue >= 6)
			{
				listOfComputerPlayers[nodeCount].cpubet = 10;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);


			}
			else if (CpuHandValue < 5)
			{

				listOfComputerPlayers[nodeCount].cpubet = 0;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

			}
		}
	}

	if (listOfComputerPlayers.size() > 1)
	{
		if (nodeCount == 0)
		{
			currentNode = listOfComputerPlayers[nodeCount];

			nextNode = listOfComputerPlayers[nodeCount + 1];
		}

		//if (nodeCount > 3)
		//{
		//	nodeCount = 0;
		//}
		else
		{
			previousNode = currentNode;
			currentNode = nextNode;
			//if statement would be here to check if there is more than 2 cpu's
			//nextNode = listOfComputerPlayers[nodeCount];
			nextNode = listOfComputerPlayers[nodeCount];
		}

		if (previousNode.CpuHandValue > currentNode.CpuHandValue)
		{
			//Fold();
			//--nodeCount;
			listOfComputerPlayers[nodeCount].didFold = true;
			listOfComputerPlayers[nodeCount].cardbackColor = 199;
			listOfComputerPlayers[nodeCount].computerHandText = "Folded";
			currentNode = nextNode;

		}
	}
	
	//needs to put in bool here if cpu folds not to execute any of these if statments


	//Need to fix:
	/*
	-if a cpu raises, the next nodes cpu hand value must be compared to the cpu that raises and if its lower fold.
	*/
	if (playerCheck && !currentNode.didFold && listOfComputerPlayers.size() > 1)
	{
		if (CpuHandValue < 50 && CpuHandValue >= 6)
		{

			//*****pseudo code for this behavior:*****//
			//*****random int between 1 and 100*****//
			random = rand() % 100;
			//random = 34;
			//*****if random int is between 1 and 34 *****//
			//*****cpu check*****//

			if (random < 35)
			{

				listOfComputerPlayers[nodeCount].cpubet = 10;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				//listOfComputerPlayers[nodeCount] = currentNode;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				aesthetics.receiveCurrentNodeFromGP(listOfComputerPlayers[nodeCount]);

				aesthetics.receiveCurrentVectorFromGP(listOfComputerPlayers);
			}
			//*****else if random int is between 35 and 60*****//
			//**********random int between 1 and 10*****//
			//**********if random int is between 1 and 3*****//
			else if (random >= 35 && random < 61)
			{
				newrandom = rand() % 10;
				if (newrandom < 4)
				{
					//**************check*****//
					listOfComputerPlayers[nodeCount].cpubet = 0;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				}
				//**********else*****//
				//**************bet array 10, 50, all in*****//
				//**************randomly select one element*****//
				//**************cpuBet = randomlySelectedBetArrayElement*****//
				else
				{
					a = 10;
					b = 50;
					c = 100;
					betVector.push_back(a);
					betVector.push_back(b);
					betVector.push_back(c);
					int randomlySelectedFromBetVector;

					int selectWhichElementToPick = rand() % 3;

					if (selectWhichElementToPick == 1)
					{
						randomlySelectedFromBetVector = a;
					}
					else if (selectWhichElementToPick == 2)
					{
						randomlySelectedFromBetVector = b;
					}
					else
					{
						randomlySelectedFromBetVector = c;
					}

					listOfComputerPlayers[nodeCount].cpubet = randomlySelectedFromBetVector;
					listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
					pot = pot + listOfComputerPlayers[nodeCount].cpubet;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
					//need to have player now have new menu for raise
					//bet = aesthetics.raiseMenu(cpubet);
				}
			}

			//*****else if random int is between 61 and 99*****//
			//**********cpu raise 50*****//
			else if (random >= 61 && random <= 99)
			{
				listOfComputerPlayers[nodeCount].cpubet = 50;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				//need to have player now have new menu for raise
			}
			//*****else if random int is 100*****//
			//**********cpu raise all in*****//
			else //basically saying if random = 100
			{
				listOfComputerPlayers[nodeCount].cpubet = listOfComputerPlayers[nodeCount].cpucash;
				listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
				pot = pot + listOfComputerPlayers[nodeCount].cpubet;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				//need to have player now have new menu for raise
			}

			//only run next lines if cpubet is not 0

			//need to make raise menu for player.
			aesthetics.ifTrueChangeOrigMenuToBlack = false;
			aesthetics.setBoolToAlertPlayer();
			aesthetics.mainText(name);

			//bet = aesthetics.gameplayMenu(); // storing the variable returned from menu class to bet
			//change Instructions to "ALERT: CPU raised [hit enter to call or fold]"
			raiseMenu(listOfComputerPlayers[nodeCount].cpubet);
			//playerCheck = false;
		}

		else if (CpuHandValue < 90 && CpuHandValue >= 50)
		{
			//so we should be having CPU raise a little more than he would check if his value is above 50.
			//57% of the time CPU should be raising by 10 or 50, 15% of the time raise 100, 2% of the time all in, and 26% of the time check

			//random = rand()% 100
			random = rand() % 100;

			if (random < 58)
			{
				int findBetForCpu = rand() % 100;
				if (findBetForCpu < 76)
				{
					//cpu bet = 10 (raise)
					//call aesthetics class to send cpu bet
					listOfComputerPlayers[nodeCount].cpubet = 10;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				}

				else if (findBetForCpu >= 76)
				{
					//cpu bet = 50 (raise)
					//call aesthetics class to send cpu bet
					listOfComputerPlayers[nodeCount].cpubet = 50;
					aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
				}
			}

			else if (random >= 58 && random < 74)
			{
				//cpu bet = 100 (raise)
				//call aesthetics class to send cpu bet

				listOfComputerPlayers[nodeCount].cpubet = 10;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
			}

			else if (random >= 74 && random < 77)
			{
				//raise all in
				//call aesthetics class to send cpu bet
				listOfComputerPlayers[nodeCount].cpubet = listOfComputerPlayers[nodeCount].cpucash;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);
			}

			else if (random >= 77)
			{
				//check
				listOfComputerPlayers[nodeCount].cpubet = 0;
			}
		}
		//else if (CpuHandValue < 50 && CpuHandValue >= 6)
		//{
		//	//so we should be having CPU raise a little more than he would check if his value is above 50.
		//	//57% of the time CPU should be checking, 17% of the time raise 50, and 26% of the time raise by 10

		//	random = rand() % 100;

		//	if(random < 58)
		//	{
		//		//check
		//	}

		//	else if (random > 57 && random < 75)
		//	{
		//		//raise by 50
		//		//call aesthetics class to send cpu bet
		//	}

		//	else if (random > 74)
		//	{
		//		//raise by 10
		//		//call aesthetics class to send cpu bet
		//	}


		//}
		else if (CpuHandValue < 5)
		{

			//10% chance of a bet from CPU, otherwise check
			random = rand() % 10;

			if (random < 2)
			{
				//raise 10
				//call aesthetics class to send cpu bet
				listOfComputerPlayers[nodeCount].cpubet = 10;
				aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

			}

			else
				//check
				listOfComputerPlayers[nodeCount].cpubet = 0;
		}

		playerCheck = false;
	}

	if (listOfComputerPlayers[nodeCount ].cpucash > 0 && !playerCheck)
	{


		if (CpuHandValue >= 90)
		{

			listOfComputerPlayers[nodeCount].cpubet = listOfComputerPlayers[nodeCount].cpucash;
			listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
			pot = pot + listOfComputerPlayers[nodeCount].cpubet;
			aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

		}
		else if (CpuHandValue < 90 && CpuHandValue >= 50)
		{
			listOfComputerPlayers[nodeCount].cpubet = 10;
			listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
			pot = pot + listOfComputerPlayers[nodeCount].cpubet;
			aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

		}
		else if (CpuHandValue < 50 && CpuHandValue >= 6)
		{
			listOfComputerPlayers[nodeCount].cpubet = 10;
			listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
			pot = pot + listOfComputerPlayers[nodeCount].cpubet;
			aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);


		}
		else if (CpuHandValue < 5)
		{

			listOfComputerPlayers[nodeCount].cpubet = 0;
			listOfComputerPlayers[nodeCount].cpucash = listOfComputerPlayers[nodeCount].cpucash - listOfComputerPlayers[nodeCount].cpubet;
			pot = pot + listOfComputerPlayers[nodeCount].cpubet;
			aesthetics.receiveCpuBetFromGamePlay(listOfComputerPlayers[nodeCount].cpubet);

		}
	}
	//previousNode = currentNode;
	//currentNode = nextNode;
	////if statement would be here to check if there is more than 2 cpu's
	//nextNode = listOfComputerPlayers[nodeCount + 1];

	++nodeCount;
}

void GamePlay::CpuFold(int CpuHandValue)
{
	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		if (listOfComputerPlayers[i].cpucash > 0)
		{
			if (listOfComputerPlayers[i].CpuHandValue < 5)
			{
				listOfComputerPlayers[i].cpubet = 0;
				listOfComputerPlayers[i].cpucash = listOfComputerPlayers[i].cpucash - listOfComputerPlayers[i].cpubet;
				pot = pot + listOfComputerPlayers[i].cpubet;
				finalCards();
			}
		}
	}
	
}
//

struct findWinner{
	int handValue;//7 card hand value
	int highCard;// 2 card high card
	int cash;//money
	string name;//name
};

auto sortFunc = [](findWinner a, findWinner b) -> bool {
	return a.handValue < b.handValue;
};

auto sortFunc1 = [](findWinner a, findWinner b) -> bool {
	return a.highCard < b.highCard;
};



void GamePlay::determine()
{

	vector<findWinner> fw;
	vector<findWinner> fw2;
	vector<findWinner> fw3;
	vector<string> fw4;

	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		listOfComputerPlayers[i].cpuHighCardValue = checks.highCardValues(listOfComputerPlayers[i].cpuhand);
	}
	playerHighCardValue = checks.highCardValues(playerhand);


	for (size_t i = 0; i < listOfComputerPlayers.size(); i++)
	{
		if (listOfComputerPlayers[i].didFold == false)
		{
			fw.push_back({ listOfComputerPlayers[i].CpuHandValue, listOfComputerPlayers[i].cpuHighCardValue, listOfComputerPlayers[i].cpucash, listOfComputerPlayers[i].name });
		}
	}
	fw.push_back({ PlayerHandValue, playerHighCardValue, cash, "You" });


	sort(fw.begin(), fw.end(), sortFunc);



	for (size_t i = 0; i < fw.size(); i++)
	{
		if (fw.back().handValue == fw[i].handValue)
		{
			fw2.push_back(fw[i]);
		}
	}
	if (fw2.size() > 1)
	{
		sort(fw2.begin(), fw2.end(), sortFunc1);
		for (size_t i = 0; i < fw2.size(); i++)
		{
			if (fw2.back().highCard == fw2[i].highCard)
			{

				fw3.push_back(fw2[i]);
			}
		}
	}

	if (fw3.size() > 1)
	{
		for (size_t i = 1; i < fw3.size(); i++)
		{
			if (fw3[0].name != fw3[i].name)
			{
				fw4.push_back(fw3[i].name);

			}
			fw4.push_back(fw3[0].name);
		}
	}

	if (fw3.size() <= 1)
	{
		if (fw2.size() < 1)
		{
			fw4.push_back(fw.back().name);
		}
		if (fw2.size() >= 1)
		{
			fw4.push_back(fw2.back().name);
		}

	}

	std::sort(fw4.begin(), fw4.end());
	auto it = std::unique(fw4.begin(), fw4.end());
	fw4.erase(it, fw4.end());

	if (fw4.size() > 1)
	{


		int pot2 = pot / fw4.size();

		if (fw4.size() == 2)
		{
			result = "Split Pot " + fw4[0] + " " + fw4[1] + " split $" + to_string(pot2) + " each!";
		}
		if (fw4.size() == 3)
		{
			result = "Split Pot " + fw4[0] + " " + fw4[1] + " " + fw4[2] + " split $" + to_string(pot2) + " each!";

		}
		if (fw4.size() == 4)
		{
			result = "Split Pot " + fw4[0] + " " + fw4[1] + " " + fw4[2] + " " + fw4[3] + " split $" + to_string(pot2) + " each!";

		}

		for (string splitwinners : fw4)
		{

			if (splitwinners == "You")
			{
				cash = cash + pot2;
			}
			if (splitwinners == "Jim")
			{
				listOfComputerPlayers[0].cpucash = listOfComputerPlayers[0].cpucash + pot2;
			}
			if (splitwinners == "Tom")
			{
				listOfComputerPlayers[1].cpucash = listOfComputerPlayers[1].cpucash + pot2;
			}
			if (splitwinners == "John")
			{
				listOfComputerPlayers[2].cpucash = listOfComputerPlayers[2].cpucash + pot2;
			}
		}

	}
	else
	{

		if (fw4.back() == "You")
		{
			result = fw4.back() + " Win $" + to_string(pot)+"!!";
			cash = cash + pot;
		}
		if (fw4.back() == "Jim")
		{
			result = fw4.back() + " Wins $" + to_string(pot) + "!!";
			listOfComputerPlayers[0].cpucash = listOfComputerPlayers[0].cpucash + pot;
		}
		if (fw4.back() == "Tom")
		{
			result = fw4.back() + " Wins $" + to_string(pot) + "!!";
			listOfComputerPlayers[1].cpucash = listOfComputerPlayers[1].cpucash + pot;
		}
		if (fw4.back() == "John")
		{
			result = fw4.back() + " Wins $" + to_string(pot) + "!!";
			listOfComputerPlayers[2].cpucash = listOfComputerPlayers[2].cpucash + pot;
		}


	}






}











