/*
 *A class based off of the stack class that fucntions as a stack of cards
 */
#ifndef DECK_H
#define DECK_H

#include "Stack.h"

class Deck
{
private:
	Stack deck;

public:
	Deck(); //default constructor
	void shuffle(); // function that shuffles the deck
	int getCount(); // function that returns the amount of cards left in the deck
	Card* deal(); //function that removes a card and returns it to be used somewhere else
	bool isEmpty(); //returns true if the deck is empty
	LinkedList deal(int); //Extra Credit  // returns a linkedList of cards, aka multiple cards, it returns as many as passed via the argument
	friend ostream& operator <<(ostream&, const Deck&); //overloaded operator to print with ease.
};

#endif
