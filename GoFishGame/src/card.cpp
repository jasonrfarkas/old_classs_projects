#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <typeinfo>

using namespace std;



Card::Card()
{
	srand(time(NULL));
	suit = rand() % 4;
	rank = rand() % 13;
}

Card::Card(int suit, int rank)
{
	this->suit = suit;;
	this->rank = rank;
}

int Card::getSuit()
{
	return suit;
}

int Card::getRank() const
{
	return rank;
}

void Card::setSuit(int suit)
{
	this->suit = suit;
}

void Card::setRank(int rank)
{
	this->rank = rank;
}

string Card::getRankAsString() const
{
	string ranks[] = { "A", "2", "3", "4", "5", "6 ", "7", "8", "9", "10", "J", "Q", "K" };

	return ranks[rank];
}

string Card::getSuitAsString() const
{
	string suits[] = { "Diamonds", "Clubs", "Hearts", "Spades" };

	return suits[suit];
}

int Card::compareByRank(const Card& otherCard)
{
	if (rank > otherCard.rank)
	return 1;
	else if (rank < otherCard.rank)
	return -1;
	else return 0;

	return rank - otherCard.rank;
}

int Card::compareByRank(int r)
{
	return rank - r;
}

int Card::compareBySuit(const Card& otherCard)
{
	if (suit > otherCard.suit)
	return 1;
	else if (suit < otherCard.suit)
	return -1;
	else return 0;

	return suit - otherCard.suit;
}

bool Card::equals(const Card& other)
{
	if(other.rank==rank)
	{
		return true;
	}
	return false;
}
string Card::display()
{
	return  getRankAsString() + " of " + getSuitAsString();
	//cout << "Your Card is " << getRankAsString() << " of " << getSuitAsString() << endl;
}

Card Card::operator = (const Card& other)
{
	rank=other.rank;
	suit=other.suit;
	return *this;
}

ostream& operator <<(ostream& out, const Card& card)
{

	out<< card.getRankAsString() + " of " + card.getSuitAsString();
	return out;
}

