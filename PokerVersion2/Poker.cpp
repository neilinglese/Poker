#include "Aesthetics.h"
#include "GamePlay.h"
#include "Checks.h"
#include "Poker.h"
#include "Deck.h"
#include "DrawCard.h"
#include "Hands.h"

// create and shuffle the deck


void Poker::createdeck(vector<string>& deck)
{
	

	Hands hands;
	hands.createdeck(deck);
}


//pushback to hands
void Poker::playercard(vector<string>& deck)
{

	hand.clear();

	Hands hands;
	hands.playercard(deck);


}
void Poker::cpucard(vector<string>&deck)
{
	cpuhand.clear();
	Hands hands;
	hands.cpucard(deck);
}
void Poker::tablecards(vector<string>& deck, int x)
{
	tablehand.clear();

	Hands hands;
	hands.tablecards(deck,x);
}
//

//set up and draw cards
vector<string> Poker::suits(vector<string> cards, string suit)
{
	cards.empty();



	DrawCard dc;
	dc.suits(cards,suit);

	return cards;
}
void Poker::createhand(vector<string> hand, int x, int y)
{

	//testhand(hand, cpuhand);

	DrawCard dc;
	dc.createhand(hand,x,y);


	

}

void Poker::drawdefaultcpu(vector<string> cpuhand, int x, int y)
{
	DrawCard dc;
	dc.drawCardBack(cpuhand, x, y);
}

void Poker::createtable(vector<string> tablehand, int x, int y)
{

	//testhand(hand, cpuhand);


	
	string val;

	DrawCard dc;
	dc.createhand(tablehand, x, y);





	

}

void Poker::DrawingCards(string value, vector<string> card, int col, int x, int y)
{

	DrawCard dc;
	dc.DrawingCards(value, card, col, x, y);


}
//
void Poker::drawcpudefault(string value, vector<string> card, int col, int x, int y)
{



	DrawCard dc;
	dc.DrawingCards(value, card, 31, x, y);



}

//

//breaking up cards
void Poker::playerCompleteHand(vector<string> tablehand, vector<string> hand)
{

	playerhand.clear();

	Hands hands;
	playerhand = hands.completeHand(tablehand, hand);



}
void Poker::playerSuit(vector<string>playerhand)
{
	psuits.clear();


	Hands hands;
	psuits = hands.getSuit(playerhand);
}
void Poker::playerValue(vector<string>playerhand)
{

	PlayerValues.clear();
	Hands hands;
	PlayerValues = hands.handValue(playerhand);
}


void Poker::computerCompleteHand(vector<string> tablehand, vector<string> cpuhand)
{

	computerhand.clear();
	Hands hands;
	computerhand = hands.completeHand(tablehand, cpuhand);



}
void Poker::computerSuit(vector<string>computerhand)
{
	csuits.clear();
	Hands hands;
	csuits = hands.getSuit(computerhand);
}
void Poker::computerValue(vector<string>computerhand)
{

	cvalues.clear();

	Hands hands;
	cvalues = hands.handValue(computerhand);
}
//
