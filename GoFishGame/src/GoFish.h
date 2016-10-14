#ifndef GOFISH_H
#define GOFISH_H

/*
 * Class to set up the rules for a goFish game
 */
#include "Player.h"
#include "Deck.h"

class GoFish
{
private:
	Player players[2]; //Array of players
	Deck deck; //Deck of Cards
	int cp;// holds an int for the current player
	int op;//holds an int for the other player
public:
	GoFish(); //default constructor
	void setNames(); //input PLayers' names
	void dealCards(); //Deal 7 Cards to each Player
	void playGame(); //starts the game which is a loop, only broken once the game is over
	void displayHands(); //Display Player info for all players
	int getRank(int); //input rank from the keyboard
	void gameResults(); //Display game results
	void turn(int);//conduct turn for player
};

#endif
