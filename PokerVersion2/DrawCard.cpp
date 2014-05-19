#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "Deck.h"
#include "DrawCard.h"


vector<string> DrawCard::suits(vector<string> passedCard, string suit)
{
	passedCard.empty();

	vector<string> spade;
	spade.push_back("    ,    ");
	spade.push_back("   / \\   ");
	spade.push_back("  (_ _)  ");
	spade.push_back("   /_\\   ");
	spade.push_back("         ");

	vector<string> clover;
	clover.push_back("    _    ");
	clover.push_back("   (_)   ");
	clover.push_back("  (_)_)  ");
	clover.push_back("   /_\\   ");
	clover.push_back("         ");

	vector<string> diamond;
	diamond.push_back("         ");
	diamond.push_back("    /\\   ");
	diamond.push_back("   <  >  ");
	diamond.push_back("    \\/   ");
	diamond.push_back("         ");

	vector<string> heart;
	heart.push_back("   _ _   ");
	heart.push_back("  / ^ \\  ");
	heart.push_back("  \\   /  ");
	heart.push_back("   \\ /   ");
	heart.push_back("    `    ");

	vector<string> cpudefault;
	cpudefault.push_back("    __   ");
	cpudefault.push_back("   /  |  ");
	cpudefault.push_back("      |  ");
	cpudefault.push_back("     _/  ");
	cpudefault.push_back("    |    ");
	cpudefault.push_back("          ");
	cpudefault.push_back("    *    ");



	if (suit == "spade")
	{
		passedCard = spade;
	}
	else if (suit == "heart")
	{
		passedCard = heart;
	}
	else if (suit == "clover")
	{
		passedCard = clover;
	}
	else if (suit == "diamond")
	{
		passedCard = diamond;
	}
	else if (suit == "cpudefault")
	{
		passedCard = cpudefault;
	}

	return passedCard;
}



void DrawCard::createhand(vector<string> passedCards, int x, int y)
{

	int color;
	string val;



	for (string item : passedCards)
	{


		if (item.at(1) == *"H")
		{
			cards = suits(cards, "heart");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"S")
		{
			cards = suits(cards, "spade");
			color = 240;
			val = item.at(0);
		}
		else if (item.at(1) == *"D")
		{
			cards = suits(cards, "diamond");
			color = 252;
			val = item.at(0);
		}
		else if (item.at(1) == *"C")
		{
			cards = suits(cards, "clover");
			color = 240;
			val = item.at(0);
		}
		else if (item.at(1) == *"CP")
		{
			cards = suits(cards, "cpudefault");
			color = 240;
			val = item.at(0);
		}


		DrawingCards(val, cards, color, x, y);
		x = x + 15;


	}

}



void DrawCard::drawCardBack(vector<string> passedCards, int x, int y, int colorCode)
{
	for (string item : passedCards)
	{
		//int color = colorCode;
		string val;


		item.at(1) = *"CP";
		cards = suits(cards, "cpudefault");
		//color = 240;
		val = " ";


		DrawingCards(val, cards, colorCode, x, y);
		x = x + 15;
	}
}


void DrawCard::DrawingCards(string value, vector<string> passedCard, int col, int x, int y)
{

	Aesthetics a;
	{ a.gotoxy(x, y);	 a.textattr(15); printf("  "); a.textattr(col); printf("         "); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 1);  a.textattr(15); printf("  "); a.textattr(col); printf("%s", value.c_str()); a.textattr(col); printf("        "); a.textattr(15); printf(" ");}
	{a.gotoxy(x, y + 2); a.textattr(15); printf("  "); a.textattr(col); printf("%s", passedCard[0].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 3); a.textattr(15); printf("  "); a.textattr(col); printf("%s", passedCard[1].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 4); a.textattr(15); printf("  "); a.textattr(col); printf("%s", passedCard[2].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 5); a.textattr(15); printf("  "); a.textattr(col); printf("%s", passedCard[3].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 6); a.textattr(15); printf("  "); a.textattr(col); printf("%s", passedCard[4].c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 7); a.textattr(15); printf("  "); a.textattr(col); printf("        "); a.textattr(col); printf("%s", value.c_str()); a.textattr(15); printf(" "); }
	{a.gotoxy(x, y + 8); a.textattr(15); printf("  "); a.textattr(col); printf("         "); a.textattr(15); printf(" "); }


}

