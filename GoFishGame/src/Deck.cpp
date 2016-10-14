#include "Deck.h"
#include "LinkedList.h"
#include<stdlib.h>
#include<time.h>
using namespace std;

Deck::Deck()
{
	deck = Stack(52);

	for(int i=0; i < 4; i++)
		for(int j=0; j < 13; j++){
			deck.push(Card(i, j));
			//cout << "                                push" << (i*13)+j << endl;
			}
}

void Deck::shuffle()
{
	srand(time(NULL));

	Card tempDeck[52];

	for(int q=0; q < 52;q++)
	{
		tempDeck[q]= *deck.pop();
	}

	for(int i=0; i < 1000; i++)
	{
		int rand1 = rand()%52;
		int rand2 = rand()%52;

		Card temp = tempDeck[rand1];
		tempDeck[rand1] = tempDeck[rand2];
		tempDeck[rand2] = temp;
	}

	for (int k = 0; k < 52; k++){
		deck.push(tempDeck[k]);
		//cout<< "TEMP PUSH "<< endl;
		}
}

int Deck::getCount()
{
	return deck.getCount();
}

Card* Deck::deal()
{
	Card* temp = deck.pop();

	if(temp == NULL)
		cout << "Deck is Empty!!!" << endl;

	return temp;
}
bool Deck::isEmpty()
{
	return deck.isEmpty();
}


//Deal multiple Cards
LinkedList Deck::deal(int r) 	//Bonus Question - Extra Points for Team
{
	LinkedList tempList;
	Card* temp;

	for(int i = 0; i < r ; i++)
	{
		Card* temp = deck.pop();
		tempList.insertAtTail(temp); //just to facilitate any game it places the cards in a random order linklist and the rest of the program should take the info from that linkedlist and analize it as fitting
	}

	if(temp == NULL)
		cout << "Deck is Empty!!!" << endl;

	return tempList;
}

ostream& operator<<(ostream& out, const Deck& deck)
{
	return out << deck.deck;
}
