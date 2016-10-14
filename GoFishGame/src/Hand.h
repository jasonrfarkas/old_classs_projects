/*
 * A data structure to hold info regarding a linkedList of cards
 */
#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"

class Hand
{
private:
	LinkedList hand;
public:
	Hand(); //default constructor
	LinkedList& getHand(); //returns hand
	bool hasRank(int rank) const; //is a specified rank in the hand
	int countRank(int rank); //return number of Cards of a specified rank
	LinkedList findRank(int rank); //returns all Cards of a rank as a LinkedList
	Card* getCardAt(int index) const; //return Card at position
	void insertByRank(Card* card); //insert Card ordered by rank
	void insertHand(LinkedList&); //insert other Hand ordered by rank
	int evaluate(); //evaluate Hand and return number of books - remove books from Hand
	int getCount() const; //return number of Cards in the Hand
	bool isEmpty() const; //is hand empty
	string sDisplay() const;//returns a string of the cards in the hand
	friend ostream& operator<<(ostream&, const Hand&); //print Hand
};

#endif
