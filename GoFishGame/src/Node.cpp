#include "Node.h"

Node::Node()
{
	next = NULL;
	data=NULL;
}

Node::Node(Card* c)
{
	data = c;
	next = NULL;
}

Node::Node( Card* c, Node* n)
{
	data = c;
	next = n;
}

void Node::setData(Card* c)
{
	data = c;
}

Card* Node::getData() const
{
	return data;
}

void Node::setNext(Node* n)
{
	next = n;
}

Node* Node::getNext() const
{
	return next;
}
