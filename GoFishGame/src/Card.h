/*
 * This is a class to hold information for a single playing card
 *
 */
#ifndef CARD_H
#define CARD_H

#include<iostream>
using namespace std;

class Card
{
private:
	//suit is represented with values 0-3
	int suit;
	//rank is represented with values 0-12
	int rank;
public:
	Card(); // default constructor
	Card(int, int); // constructor that takes arguments for the rank and suit
	int getSuit(); // returns the suit in an int
	void setSuit(int); //mutator for suit
	int getRank() const; // returns the rank as an int
	void setRank(int); // mutator for rank
	int compareByRank(const Card&); //takes a card by returns if the current card has the same rank as that card
	int compareByRank(int r); // same as above but takes an int as an argument
	int compareBySuit(const Card&); // compares the suit of the card to the card pass through an argument
	bool equals(const Card&); // checks if the two cards have the same suit
	string getRankAsString() const; // returns the rank of the card as a string, and translates 10-13 to j,q,k and 1 to a
	string getSuitAsString() const; // analizes the suit of the card and translates into a string
	string display(); //prints the info of the card,
	Card operator = (const Card&); //overload assignment operator
	friend ostream& operator <<(ostream&, const Card&); //prints the info of the card,
};

#endif
