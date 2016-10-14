#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{
	cards = new Card[100];
	capacity = 100;
	count = 0;
}

Stack::Stack(int size)
{
	cards = new Card[size];
	capacity = size;
	count = 0;
}

Stack::Stack(const Stack& otherStack)
{
	capacity = otherStack.capacity;
	count = otherStack.count;
	cards = new Card[capacity];

	for(int i=0; i < count; i++)
		cards[i] = otherStack.cards[i];
}

Stack::~Stack()
{
	delete [] cards;
}

int Stack::getCount()
{
	return count;
}

bool Stack::push(const Card& c)
{
	if(!isFull())
	{
		cards[count] = c;
		count++;
		return true;
	}
	
	else
	{
	cout << "Stack is full!!!";
	}

	return false;
}

Card* Stack::pop()
{
	if(!isEmpty())
	{
		count--;
		return &(cards[count]);
	}
	
	cout << "Stack is empty!!!";
	return 0;
}

Card* Stack::peek() 
{
	if(!isEmpty())
		return &(cards[count]);
	
	cout << "Stack is empty!!!";
	return NULL;
}
	
bool Stack::isEmpty()
{
	return count == 0;
}
	
bool Stack::isFull()
{
	return count == capacity;
}

Stack& Stack::operator=(const Stack& otherStack)
{
	if(this == &otherStack)
		return *this;
	
	delete [] cards;

	capacity = otherStack.capacity;
	count = otherStack.count;
	cards = new Card[capacity];

	for(int i=0; i < count; i++)
		cards[i] = otherStack.cards[i];

	return *this;
}

string Stack::display()
{
	string str = "";

	for(int i=count-1; i >= 0; i--)
		str += cards[i].display() + "\n";
	
	return str;
}

ostream& operator<<(ostream& out, const Stack& stack)
{
	for(int i = stack.count-1; i >= 0; i--)
		out << stack.cards[i] << endl;

	return out;
}
	
