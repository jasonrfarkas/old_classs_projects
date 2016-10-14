/*
 * A data structure that contains information (a card )  and an address to another container
 */
#ifndef NODE_H
#define NODE_H

#include "Card.h"

class Node
{
private:
	Card* data; //holds location of actual info
	Node* next; //hold location of another node
public:
	Node(); //default constructor
	Node(Card*); //constructor that take info as an argument
	Node(Card*, Node*); //takes a constructor and a pointer to another node
	void setData(Card*); // sets the info pointed to by the container via an argument
	Card* getData() const; // returns the location of information in the container
	void setNext(Node*); // modifies the container which it points to
	Node* getNext() const; // accesses the container which it points to.
};

#endif
