#include "LinkedList.h"
#include "Hand.h"
#include "Card.h"
#include <iostream>
#include<string>
using namespace std;

Hand::Hand()
{
	hand = LinkedList();
}

bool Hand::hasRank(int rank) const
{

	for (int i = 0; i < hand.getCount(); i++)
	{
		if (rank == hand.getAtIndex(i)->getRank())
		{
			return true;
		}
	}
	
	return false;
	}
	
int Hand::countRank(int rank)
{
	int count = 0;
	for (int i = 0; i < hand.getCount(); i++)
	{
		if (rank == hand.getAtIndex(i)->getRank())
		{
			count++;
		}
	}
	return count;
}

LinkedList Hand::findRank(int rank)
{
	LinkedList tempList;
	int temp = -1; // it will be hand.search(rank);

		do {
			temp = hand.search(rank);
			Card* tem = NULL;

			if( temp != -1)
			{
				tem = hand.removeAtIndex(temp);
				tempList.insertAtTail(tem);
			}
		}
		while(temp!=-1);

	return tempList;
}

Card* Hand::getCardAt(int index) const
{
	return hand.getAtIndex(index);
}

void Hand::insertByRank(Card* card)
{
	bool inserted = false;
	if (!hand.isEmpty())
	{
		for (int i = 0; i < hand.getCount(); i++)
		{
			if(!inserted)
			{
				 if (card->getRank() <= hand.getAtIndex(i)->getRank())
				{
					inserted = hand.insertAtIndex(card, i);
				}
				 else if( i >= hand.getCount()-1)
				{
					 hand.insertAtTail(card);
					 inserted=true;
				}
			}
		}
	}
	else
	{
		hand.insertAtHead(card);
	}
}


void Hand::insertHand(LinkedList& otherHand)
{
	int x =otherHand.getCount();

	if (!otherHand.isEmpty())
	{
		for (int i = 0; i < x; i++)
		{
				insertByRank(otherHand.getAtIndex(i));
		}
	}
}


int Hand::evaluate()
{
	int x = 0;
	for (int i = 0; i <= 12; i++)
	{
		if (countRank(i) == 4)
		{
			x += 1;
			findRank(i);//removes the card with that rank
		}
	}
	return x;
}

int Hand::getCount() const
{
	return hand.getCount();
}
//*/
bool Hand::isEmpty() const
{
	 if (hand.getCount() <= 0)
	 {
		 return true;
	 }

	 else
	 {
		 return false;
	 }
}

string Hand::sDisplay() const
{
	//returns a string of the cards in the hand
	return hand.displayList();
}


ostream& operator<<(ostream& out, const Hand& h)
{
	out << h.hand;
	return out;
}
