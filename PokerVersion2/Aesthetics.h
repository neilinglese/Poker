#ifndef AESTETICS_H
#define AESTETICS_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <algorithm> 
#include <stdio.h>
#include <vector>
#include <ctime>
#include <winuser.h>
#include <windef.h>
#include <stdexcept>
#include <Windows.h>



using namespace std;
using std::string;

#include "ComputerPlayer.h"
#define MaxNo_Menu 5
#define MaxNo_Menu1 3
#define MaxNo_Menu2 3
#define MaxNo_Menu3 3
#define RaiseMenu 2
#define CPUBet 2


class Aesthetics
{
public:
	
	
	int playerAmount;
	int playerMenu();
	void choosePlayerScreen();
	void screenSetup(int);
	void loadCpuPlayers(int);
	void gotoxy(int, int);
	void textattr(int);
	void mainText(string);
	void changingText(int, string,vector<ComputerPlayer>,string,int,string);
	void text1(string);
    void SetWindow(int, int);
	void Start();
	void setBoolToAlertPlayer();
	//void newMenuForCheckMenu(int, int, char[]);
	
	void header();
	void MainMenu();
	int raiseMenu(int valueOfCPUBet);
	void Credits();
	void OutOfMoney(string);
	void randomHeaderCards();
	int gameplayMenu();
	void ShowLastSystemError();
	int centerWindow();
	void receiveCpuBetFromGamePlay(int);
	bool ifTrueChangeOrigMenuToBlack;
	bool ifTrueChangeUserAlert;
	bool beforeHandSetTempNodeCPUCash;	
	string Instructions;

	int displayCpuBet;

	void playerMainText();
	void computerMainText();
	void otherMainText(string);

	void playerChangingText(int,string);
	void computerChangingText(vector<ComputerPlayer>);
	void otherChangingText(int,string,string);
	void receiveCurrentNodeFromGP(ComputerPlayer);
	void receiveCurrentVectorFromGP(vector<ComputerPlayer> tempVector);
	ComputerPlayer tempCurrentNode;
	vector<ComputerPlayer> tempVectorList;
	int handIterator;
};


#endif