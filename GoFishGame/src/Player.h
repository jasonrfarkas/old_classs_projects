/*
 * A class to store info about a player in a card game
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
# include <string>
# include <iostream>
using namespace std;

class Player
{
private:
	string name;
	Hand hand;
	int points;
public:
	Player(); //default
	Player(string n); //sets the name of a player as it constructs
	void setName(string n); //function to set player name
	string getName() const; //function to return player name
	string playerInfo(); //return player's info as a string
	string showHand() const; //return player's hand as a string
	bool hasRank(int r) const; //function to see if the hand of the player contains a specified rank via argument
	void addCard(Card* c); //adds a card to the hand of the player
	void addCards(LinkedList& h); //adds multiple cards to the hand of the player
	Card* getCardAt(int index) const; //function that returns the card at a specific index of the player's hand
	int checkHand(); //evaluate and return points of Hand
	int getPoints();//returns the points of a player
	int getTotalCards(); //return Player's total Cards
	bool emptyHand();//returns true if hand is empty
	LinkedList getCards(Card* c) ;//given a card, return all Cards with the same rank in the Hand, and remove them from the hand
	LinkedList getCards(int r); //return the cards of a player of a certain rank, and removes them from the hand
};

#endif
