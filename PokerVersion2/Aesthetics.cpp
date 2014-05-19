#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "DrawCard.h"
#include "Hands.h"
#include "ComputerPlayer.h"

HWND hwnd = GetConsoleWindow();

HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
GamePlay gp;

vector<ComputerPlayer> cp;


void Aesthetics::Start()
{
	ifTrueChangeUserAlert = true;
	
	Machine m;
}

void Aesthetics::choosePlayerScreen()
{
	system("cls");
	Aesthetics::beforeHandSetTempNodeCPUCash = true;
	SetWindow(100, 55);
	centerWindow();
	randomHeaderCards();
	playerAmount = playerMenu();
	screenSetup(playerAmount);

}

int Aesthetics::playerMenu()
{
	char *menu_list[MaxNo_Menu3] = { "1 Opponent", "2 Opponents", "3 Opponents" };
	int i,
		xpos = 45,
		ypos[MaxNo_Menu3] = { 24, 27, 30 };

	for (i = 0; i< MaxNo_Menu3; ++i)
	{
		gotoxy(xpos, ypos[i]);
		textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		gotoxy(xpos, ypos[i]);
		textattr(11);
		printf("%s", menu_list[i]);

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/

		switch (_getch())
		{
			//up
		case 72:
			if (i>0)
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			//break;

			//down
		case 80:
			if (i< MaxNo_Menu1 - 1)
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { return 1; }
			if (i == 1) { return 2; }
			if (i == 2) { return 3; }
			//break;
		}
	}

}

void Aesthetics::screenSetup(int amount)
{
	
	cp.clear();
	ComputerPlayer opponent1;
	ComputerPlayer opponent2;
	ComputerPlayer opponent3;
	opponent1.name = "Jim";
	opponent1.cardX = 1;
	opponent1.cardY = 3;
	opponent1.cardbackColor = 31;

	opponent2.name = "Tom";
	opponent2.cardX = 60;
	opponent2.cardY = 3;
	opponent2.cardbackColor = 31;

	opponent3.name = "John";
	opponent3.cardX = 60;
	opponent3.cardY = 40;
	opponent3.cardbackColor = 31;

	switch (amount)
	{
	case 1:
		opponent1.name = "Jim";
		opponent1.cardX = 24;
		opponent1.cardY = 3;
		opponent1.cardbackColor = 31;
		
		cp.push_back(opponent1);
		SetWindow(100, 60);
		centerWindow();
		gp.loadingPlayers(cp);
		break;
	case 2:
		cp.push_back(opponent1);
		cp.push_back(opponent2);
		SetWindow(130, 60);
		centerWindow();
		gp.loadingPlayers(cp);
		break;
	case 3:
		cp.push_back(opponent1);
		cp.push_back(opponent2);
		cp.push_back(opponent3);
		SetWindow(130, 60);
		centerWindow();
		gp.loadingPlayers(cp);
		break;
	}
	
}

void Aesthetics::gotoxy(int x, int y)
{
	COORD Coord;
	Coord.X = x;
	Coord.Y = y;

	SetConsoleCursorPosition(con, Coord);
}

void Aesthetics::textattr(int color)
{
	SetConsoleTextAttribute(con, color);
}

void Aesthetics::setBoolToAlertPlayer()
{
	ifTrueChangeUserAlert = true;
	ifTrueChangeOrigMenuToBlack = true;
}

void Aesthetics::receiveCpuBetFromGamePlay(int _cpubet)
{
	displayCpuBet = _cpubet;
}

void Aesthetics::mainText(string name)
{
	playerMainText();
	computerMainText();
	otherMainText(name);
}
void Aesthetics::receiveCurrentNodeFromGP(ComputerPlayer tempNode)
{
	tempCurrentNode = tempNode;
}

void Aesthetics::receiveCurrentVectorFromGP(vector<ComputerPlayer> tempVector)

{
	 tempVectorList = tempVector;
}
void Aesthetics::playerMainText()
{
	int yourCardsX;
	int youMoneyX;
	int yourCurrentHandX;

	if (cp.size() == 3)
	{
		yourCardsX = 8;
		youMoneyX = 5;
		yourCurrentHandX = 5;
	}
	else
	{
		yourCardsX = 33;
		youMoneyX = 30;
		yourCurrentHandX = 30;
	}

	textattr(11);
	gotoxy(yourCardsX, 38);
	printf("%s", "Your Cards");
	textattr(2);
	gotoxy(youMoneyX, 50);
	printf("%s", "Your Money");

	gotoxy(yourCurrentHandX, 52);
	textattr(11);
	printf("%s", "Current Hand:");
}
void Aesthetics::computerMainText()
{
	int cpu1CardsX;
	int cpu1HandX;
	int cpu1MoneyX;

	if (cp.size() == 1)
	{
		cpu1CardsX = 33;
		cpu1HandX = 30;
		cpu1MoneyX = 30;

		
	}
	if (cp.size() == 2)
	{
		cpu1CardsX = 8;
		cpu1HandX = 5;
		cpu1MoneyX = 5;

		textattr(14);
		gotoxy(70, 1);
		cout << "Tom's Cards";
		textattr(14);
		gotoxy(70, 15);
		cout << "Tom's Hand:";

		gotoxy(70, 13);
		textattr(2);
		cout << "Tom's Money:";
	}
	if (cp.size() == 3)
	{
		cpu1CardsX = 8;
		cpu1HandX = 5;
		cpu1MoneyX = 5;

		textattr(14);
		gotoxy(70, 1);
		cout << "Tom's Cards";
		textattr(14);
		gotoxy(70, 15);
		cout << "Tom's Hand:";

		gotoxy(70, 13);
		textattr(2);
		cout << "Tom's Money:";

		textattr(14);
		gotoxy(70, 38);
		cout << "John's Cards";
		textattr(14);
		gotoxy(70, 52);
		cout << "John's Hand:";

		gotoxy(70, 50);
		textattr(2);
		cout << "John's Money:";
	}


	textattr(14);
	gotoxy(cpu1CardsX, 1);
	cout<< "Jim's Cards";
	textattr(14);
	gotoxy(cpu1HandX, 15);
	cout << "Jim's Hand:";
	//cpu1MoneyX = tempCurrentNode.cpucash;
	gotoxy(cpu1MoneyX, 13);
	textattr(2);
	cout<<"Jim's Money:";
}
void Aesthetics::otherMainText(string name)
{
	int instructionsX;
	int potX;

	if (cp.size() == 1)
	{
		instructionsX = 70;
		potX = 28;
	}
	else
	{
		instructionsX = 100;
		potX = 48;
	}

	if (!ifTrueChangeUserAlert)
	{
		Instructions = "Instructions:";
		gotoxy(instructionsX, 30);
		textattr(15);
		cout << Instructions;
		gotoxy(instructionsX, 33);
		textattr(15);
		cout << "<-- --> arrow keys to move";

		gotoxy(instructionsX, 36);
		textattr(15);
		cout << "Hit Enter";

	}

	if (ifTrueChangeUserAlert)
	{
		textattr(4);
		gotoxy(instructionsX, 30);
		cout << "!!! "+name+" RAISED " << displayCpuBet << " CHIPS !!!";
		ifTrueChangeUserAlert = false;

		gotoxy(instructionsX, 33);
		textattr(0);
		cout << "<-- --> arrow keys to move";

		gotoxy(instructionsX, 33);
		textattr(5);
		cout << "Hit Enter To Call Or Fold";


		gotoxy(instructionsX, 36);
		textattr(0);
		cout << "Hit Enter";
	}
	//cout << Instructions;

	//textattr(13);
	//gotoxy(55, 28);
	//cout << PressEnterToContinue;
	gotoxy(potX, 33);
	textattr(2);
	printf("%s", "Pot Total");
}




void Aesthetics::changingText(int playerMoney, string playerHand,vector<ComputerPlayer> ct,string didFold, int thePot, string theResult)
{
	playerChangingText(playerMoney, playerHand);
	computerChangingText(ct);
	otherChangingText(thePot, didFold, theResult);
}

void Aesthetics::playerChangingText(int playerMoney, string playerHand)
{
	int playerMoneyX;
	int playerHandX;

	if (cp.size() == 3)
	{
		playerMoneyX = 16;
		playerHandX = 19;
	}

	else
	{
		playerMoneyX = 41;
		playerHandX = 44;
	}
	gotoxy(playerMoneyX, 50);
	textattr(10);
	cout << playerMoney; // displaying player cash


	gotoxy(playerHandX, 52);
	textattr(15);
	cout << playerHand; // displaying what you have in your hand
}
void Aesthetics::computerChangingText(vector<ComputerPlayer> ct)
{

	handIterator++;
	int cpu1HandX;
	int cpu1CashX;
	DrawCard dc;

	if (cp.size() == 1)
	{
		cpu1HandX = 40;
		cpu1CashX = 40;
	}
	if (cp.size() == 2)
	{
		cpu1HandX = 18;
		cpu1CashX = 18;
		gotoxy(83, 15);
		textattr(15);
		if (ct[1].didFold == true)
		{
			cout << "Folded";
		}
		else
		{
			cout << ct[1].computerHandText;
		}


		gotoxy(85, 13);
		textattr(10);
		if (handIterator > 1)
		{
			ct[1].cpucash = tempVectorList[1].cpucash;
		}
		cout << ct[1].cpucash; // displaying cpu cash
	}
	if (cp.size() == 3)
	{
		cpu1HandX = 18;
		cpu1CashX = 18;

		gotoxy(83, 15);
		textattr(15);
		if (ct[1].didFold == true)
		{
			cout << "Folded";
		}
		else
		{
			cout << ct[1].computerHandText;
		}


		gotoxy(85, 13);
		textattr(10);
		if (handIterator > 1)
		{
			ct[1].cpucash = tempVectorList[1].cpucash;
		}
		cout << ct[1].cpucash; // displaying cpu cash

		gotoxy(83, 52);
		textattr(15);
		if (ct[2].didFold == true)
		{
			cout << "Folded";
		}
		else
		{
			cout << ct[2].computerHandText;
		}


		gotoxy(85, 50);
		textattr(10);
		if (handIterator > 1)
		{
			ct[2].cpucash = tempVectorList[2].cpucash;
		}
		cout << ct[2].cpucash; // displaying cpu cash
	}
	gotoxy(cpu1HandX, 15);
	textattr(15);
	if (ct[0].didFold == true)
	{
		cout << "Folded";
	}
	else
	{
		cout << ct[0].computerHandText;
	}
	


	gotoxy(cpu1CashX, 13);
	textattr(10);
	int firstCPUCashBeforeHand = 200;
	int i = 10;

	//ct[0].cpucash = tempVectorList[0].cpucash;
	//ct[0].cpucash = tempCurrentNode.cpucash;
	if (handIterator > 1)
	{
		ct[0].cpucash = tempVectorList[0].cpucash;
	}
	cout << ct[0].cpucash; // displaying cpu cash 
}
void Aesthetics::otherChangingText(int thePot, string didFold, string theResult)
{
	int didFoldX;
	int thePotX;
	int theResultX;

	if (cp.size() == 1)
	{
		 didFoldX = 37;
		 thePotX = 40;
		 theResultX = 37;
	}
	else
	{
		didFoldX = 37;
		thePotX = 60;
		theResultX = 57;
	}
	

	textattr(8);
	gotoxy(didFoldX, 33);
	cout << didFold;
	gotoxy(thePotX, 33);
	textattr(10);
	cout << thePot; // displaying the pot total

	textattr(8);
	gotoxy(theResultX, 30);
	cout << theResult; // displaying if you won or lost the hand

}

void Aesthetics::text1(string words)
{
	system("cls");
	gotoxy(1, 20);
	textattr(15);
	printf("%s", words.c_str());

}

void Aesthetics::header()
{
	system("cls");
	randomHeaderCards();
	gotoxy(35, 20); textattr(15); cout << "C++ II Final : Console Poker" << endl;
	gotoxy(35, 21); cout << "By: Jordan Max & Neil Inglese" << endl;


}

void Aesthetics::MainMenu()
{

	char *menu_list[MaxNo_Menu1] = { "Start", "Credits", "Exit" };
	int i,
		xpos = 45,
		ypos[MaxNo_Menu1] = { 24, 27, 30 };

	for (i = 0; i< MaxNo_Menu1; ++i)
	{
		gotoxy(xpos, ypos[i]);
		textattr(3);
		printf("%s", menu_list[i]);
	}

	i = 0;
	while (1)
	{
		gotoxy(xpos, ypos[i]);
		textattr(11);
		printf("%s", menu_list[i]);

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/

		switch (_getch())
		{
			//up
		case 72:
			if (i>0)
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				--i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 2;
			}
			//break;

			//down
		case 80:
			if (i< MaxNo_Menu1 - 1)
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				++i;
			}
			else
			{
				gotoxy(xpos, ypos[i]);
				textattr(3);
				printf("%s", menu_list[i]);
				i = 0;
			}
			break;

			//enter
		case 13:
			if (i == 0) { choosePlayerScreen(); }
			if (i == 1) { Credits(); }
			if (i == 2) { exit(0); }
			//break;
		}
	}

}

int Aesthetics::raiseMenu(int valueOfCPUBet)
{
	int x;

	if (cp.size() == 1)
	{
		x = 30;
	}
	if (cp.size() == 2)
	{
		x = 45;
	}
	if (cp.size() == 3)
	{
		x = 45;
	}

	char *menu_list[RaiseMenu] = { "Call", "Fold" };
	
	int i,
		xpos[RaiseMenu] = { x, x+15 },
		ypos = 53;

	// list the menu
	for (i = 0; i< RaiseMenu; ++i)
	{

		gotoxy(xpos[i], ypos);
		textattr(3);
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the beginning
	while (1)
	{

		gotoxy(xpos[i], ypos);// set cursor position
		textattr(11); // this sets menu item to green text
		printf("%s", menu_list[i]); // print out highlighted item in new color

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/
		//getting key information switch

		switch (_getch())
		{
			//right
		case 75:
			if (i>0)
			{

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 3;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< RaiseMenu - 1)
			{

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			if (i == 0) { return valueOfCPUBet; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			/*if i = 1*/
			/****return int pass by from CPU*/
			if (i == 1) { return 200; }
			break;
		}
	}
	ifTrueChangeOrigMenuToBlack = false;
}

//moved gameplay menu here, makes more sense

//void Aesthetics::newMenuForCheckMenu(int xpos, int ypos, char[] menu_list)
//{
//	for (i = 0; i < MaxNo_Menu; ++i)
//	{
//
//		gotoxy(xpos[i], ypos);
//		ifTrueChangeOrigMenuToBlack = true;
//		textattr(3);
//		if (!ifTrueChangeOrigMenuToBlack)
//			textattr(2);
//		printf("%s", menu_list[i]);
//	}
//}
int Aesthetics::gameplayMenu()
{
	int x;

	if (cp.size() == 1)
	{
		x = 15;
	}
	if (cp.size() == 2)
	{
		x = 30;
	}
	if (cp.size() == 3)
	{
		x = 30;
	}
	
	char *menu_list[MaxNo_Menu] = { "Check", "Bet 10", "Bet 50", "All In", "Fold" };

	int i,
		xpos[MaxNo_Menu] = { x, x+15, x+30, x+45, x+60 },
		ypos = 58;

	// list the menu
	//call function for for-loop
	for (i = 0; i< MaxNo_Menu; ++i)
	{

		gotoxy(xpos[i], ypos);
		textattr(3);
		
		if (ifTrueChangeOrigMenuToBlack)
		{
			textattr(0);
		}
			
			
		printf("%s", menu_list[i]);
	}

	// make menu available to choose
	i = 0; // set i to 0 to start menu at the begining
	while (1)
	{

		gotoxy(xpos[i], ypos);// set cursor position
		textattr(11); // this sets menu item to green text
		if (ifTrueChangeOrigMenuToBlack)
		{
			textattr(0);
			ifTrueChangeOrigMenuToBlack = false;
		}
		printf("%s", menu_list[i]); // print out highlighted item in new color

		/* note : 72 -> UP button
		75 -> RIGHT button
		77 -> LEFT button
		80 -> DOWN button
		*/
		//getting key information switch
		switch (_getch())
		{

			//right
		case 75:
			if (i>0)
			{

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3); // set text color passing in color
				printf("%s", menu_list[i]); // print the menu item out in new color
				--i;//up key subtract from i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 4;//set i to 2 to start menu from bottom
			}
			break;

			//left
		case 77:
			if (i< MaxNo_Menu - 1)
			{

				gotoxy(xpos[i], ypos);//set cursor position passing in i
				textattr(3);//set text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				++i;// down key add to i
			}
			else
			{

				gotoxy(xpos[i], ypos);// set cursor position passing in i
				textattr(3); // reset text color
				printf("%s", menu_list[i]);//print the menu item out in new color
				i = 0;//set i to 0 to restart menu
			}
			break;

			//enter
		case 13:
			if (i == 0) { return 0; } /*system("cls"); hand.push_back(deck[3]); choosecard(deck,hand);*/
			if (i == 1) { return 10; }
			if (i == 2) { return 50; }
			if (i == 3) { return 100; }
			if (i == 4)  { return 200; }
			break;
		}
	}
}

void Aesthetics::Credits()
{
	system("cls");
	textattr(8); cout << "		 _________ "; textattr(12); cout << "  _________   "; textattr(8); cout << "_________   "; textattr(12); cout << "__________" << endl;
	textattr(8); cout << "	        /         \\"; textattr(12); cout << " /         \\ "; textattr(8); cout << "/         \\ "; textattr(12); cout << "/          \\" << endl;
	textattr(8); cout << "                 Jordan Max "; textattr(12); cout << " A          "; textattr(8); cout << " K          "; textattr(12); cout << "Neil Inglese" << endl;
	textattr(8); cout << "                     ,      "; textattr(12); cout << "    _ _     "; textattr(8); cout << "     _      "; textattr(12); cout << "            " << endl;
	textattr(8); cout << "                    / \\     "; textattr(12); cout << "   / ^ \\   "; textattr(8); cout << "     (_)    "; textattr(12); cout << "      /\\     " << endl;
	textattr(8); cout << "                   (_ _)    "; textattr(12); cout << "   \\   /   "; textattr(8); cout << "    (_)_)   "; textattr(12); cout << "     <  >    " << endl;
	textattr(8); cout << "                    /_\\     "; textattr(12); cout << "    \\ /    "; textattr(8); cout << "     /_\\    "; textattr(12); cout << "      \\/     " << endl;
	textattr(8); cout << "                            "; textattr(12); cout << "     `     "; textattr(8); cout << "            "; textattr(12); cout << "             " << endl;
	textattr(8); cout << "                 jdmdev.net  "; textattr(12); cout << "         A "; textattr(8); cout << "          K"; textattr(12); cout << " neildev.net " << endl;
	textattr(8); cout << "		\\_________/ "; textattr(12); cout << "\\_________/ "; textattr(8); cout << "\\_________/"; textattr(12); cout << " \\__________/" << endl; cout << "" << endl;

	MainMenu();
}

//game over function
void Aesthetics::OutOfMoney(string who)
{
	SetWindow(100, 55);
	centerWindow();
	system("cls");
	randomHeaderCards();
	gotoxy(40, 20); textattr(15); cout << who + " ran out of money" << endl;
	gotoxy(45, 21); cout << "Game Over" << endl;

	cin.get();
	system("cls");
	header(); // calling our game header
	MainMenu(); // calling our menu system
}

//random card generator for game over and start screen cards
void Aesthetics::randomHeaderCards()
{
	Hands hnds;
	DrawCard dc;

	vector<string>enddeck;
	vector<string> headercards;
	enddeck = hnds.createdeck(enddeck);
	headercards.push_back(enddeck[1]);
	headercards.push_back(enddeck[2]);
	headercards.push_back(enddeck[3]);
	headercards.push_back(enddeck[4]);


	dc.createhand(headercards, 20, 10);
}


//seting console size and centering, leave width at 55, if over 80 it throws an exception
//example call both functions, change the x to length of window we want, like i said id leave y 55
// SetWindow(100, 55);
//centerWindow();
void Aesthetics::SetWindow(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (h == INVALID_HANDLE_VALUE)
		throw std::runtime_error("Unable to get stdout handle.");

	{
		COORD largestSize = GetLargestConsoleWindowSize(h);
		if (x > largestSize.X)
			throw std::invalid_argument("The x dimension is too large.");
		if (y > largestSize.Y)
			throw std::invalid_argument("The y dimension is too large.");
	}


	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
		throw std::runtime_error("Unable to retrieve screen buffer info.");

	SMALL_RECT& winInfo = bufferInfo.srWindow;
	COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

	if (windowSize.X > x || windowSize.Y > y)
	{
		SMALL_RECT info =
		{
			0,
			0,
			x < windowSize.X ? x - 1 : windowSize.X - 1,
			y < windowSize.Y ? y - 1 : windowSize.Y - 1
		};

		if (!SetConsoleWindowInfo(h, TRUE, &info))
			throw std::runtime_error("Unable to resize window before resizing buffer.");
	}

	COORD size = { x, y };
	if (!SetConsoleScreenBufferSize(h, size))
		throw std::runtime_error("Unable to resize screen buffer.");


	SMALL_RECT info = { 0, 0, x - 1, y - 1 };
	if (!SetConsoleWindowInfo(h, TRUE, &info))
		throw std::runtime_error("Unable to resize window after resizing buffer.");


	//hiding the cursor
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}
int Aesthetics::centerWindow()
{
	HWND hwndScreen = GetDesktopWindow(),conwd = GetConsoleWindow();

	RECT rectScreen,rectcon;

	int ConsolePosX,ConsolePosY;

	if (!GetWindowRect(hwndScreen, &rectScreen)) return (GetLastError());
	if (!GetWindowRect(conwd, &rectcon)) return (GetLastError());

	ConsolePosX = (rectScreen.right - rectScreen.left - (rectcon.right - rectcon.left)) >> 1;
	ConsolePosY = (rectScreen.bottom - rectScreen.top - (rectcon.bottom - rectcon.top)) >> 1;
	if (!SetWindowPos(conwd, HWND_NOTOPMOST, ConsolePosX, ConsolePosY, 0, 0, SWP_NOOWNERZORDER | SWP_NOSIZE)) return (GetLastError());

	return (0);
}
