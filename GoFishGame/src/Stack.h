#ifndef STACK_H
#define STACK_H

/*
 * First in Last out data stucture to conatin cards
 */

#include "Card.h"

class Stack
{
private:
	Card *cards; //an array of cards
	int capacity; // contains the size of the array of cards
	int count; // tells the current amount of spots filled in the array
public:
	Stack(); //default
	Stack(int); //constructor that takes the compacity as an argument
	Stack(const Stack&); // copy constructor
	~Stack(); //destructor
	int getCount(); //returns the amount of spots currently filled
	bool push(const Card& c); // places an element on the stack and returns true if there was space
	Card* pop(); //  removes an element from the stack and returns true if it was there to remove
	Card* peek(); // returns, but does not remove an element from the stack
	bool isEmpty(); //returns true if the count is zero
	bool isFull(); //returns true if count == compacity
	Stack& operator=(const Stack&); //assignment overload
	string display(); //returns a string that contains all relevant info of the stack
	friend ostream& operator <<(ostream&, const Stack&); // overload for printing
};

#endif
