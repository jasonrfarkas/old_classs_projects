/*
 * Class that stores a multiple nodes and links them together via their addresses
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
	Node *head; //holds info for the location of the first node in the linked list
	Node *tail; //holds info for the location of the last node in the linked list
	int count; ///holds info for how many nodes there are in this list
public:
	LinkedList(); // default constructor
	LinkedList(const LinkedList& otherList); //copy constructor
	Card* getHead() const; // returns the data contents of the first node
	Card* getTail() const; // returns the data contents of the last node
	Card* getAtIndex(int) const; // returns the data contents a node at a specific index
	void insertAtHead(Card* data); //insert a node before all other nodes in the chain
	void insertAtTail(Card* data); //insert a node after all other nodes in the chain
	bool insertAtIndex(Card* data, int index); //insert a node before all other nodes after a specific index passed via arguement
	int getCount() const; //return the number of nodes in the list
	Card* removeAtHead() ; //remove the first node
	Card* removeAtTail() ; //remove the last node
	Card* removeAtIndex(int index);//remove a node at a specific index
	Card* remove(Card* data); //remove a node with the data of a specific card
	bool contains(Card* data); //return true if the list contains equal data to a  paralleled card
	int search(Card* data) const;// returns an int for the index where a specific  piece of data can be found if at all
	int search(int) const;//searches by rank
	bool isEmpty() const;
	const Card& operator[](int index);
	string displayList() const;//returns a string displaying the contents of the list
	friend ostream& operator<<(ostream&, const LinkedList&); //overload operator for display
	LinkedList& operator=(const LinkedList& otherList); // overload assignment operator
	~LinkedList(); //destructor
};

#endif
