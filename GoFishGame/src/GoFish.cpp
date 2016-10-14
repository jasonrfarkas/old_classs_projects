# include "Player.h"
# include "Deck.h"
# include "GoFish.h"
#include <sstream>
# include <iostream>
using namespace std;

int convertStoNumb(string Text); // this is not part of the contact class but is a function that may be used in anything that calls the contact class

	GoFish::GoFish()
	{
		players[0] = Player("Player 1");
		players[1] = Player("Player 2");
		deck = Deck();
		deck.shuffle();
		cp=0; // start with the first player
		op=1;
	}
	//default constructor
	void GoFish::setNames()
	{
		for(int i=0; i<2; i++)
		{
		string n;
		cout << "please enter Player " << i+1 << "'s name: ";
		cin >> n;
		players[i].setName(n);
		}

		cout<< players[0].getName() << " and " << players[1].getName() << " get ready for the most epic game of GO FISH!!!" << endl << "BEGIN!!" <<endl;
	} 
	//input PLayers' names
	void GoFish::dealCards()
	{
		for (int i = 0; i < 2; i ++)
		{
			for (int j = 0; j < 7; j++)
			{
				if(!deck.isEmpty())
				{
				players[i].addCard(deck.deal());
				}
				else
				{
					cout << "deck is empty";
				}
			}
		}
		
	} 
	//Deal 7 Cards to each Player
	void GoFish::playGame()
	{
		setNames();
		dealCards();
		turn(cp);
	}

	void GoFish::displayHands()
	{
		for (int i = 0; i < 2; i++)
		{
			cout << "Player " << i << " 's hand includes" <<  players[i].showHand() << endl;
		}

	} 
	//Display Player info for all players

	int GoFish::getRank(int op)
	{
		int r;
		string y;
		cout << "what you want?: " << endl;
		r = -2;

		do{
			cout << "Enter a rank which you currently have: " << endl;
			cin >> y;
			r= convertStoNumb(y);
				if(y=="a" || y== "A")
				{
					r=1;
				}
				else if(y=="j" || y=="J" || y=="Jack" || y=="jack")
				{
					r=11;
				}
				else if(y=="q" || y== "Q" || y=="Queen" || y=="queen")
				{
					r=12;
				}
				else if(y=="k" || y=="K" || y=="King" || y=="king")
				{
					r=13;
				}
			r=r-1;
			}
		while( !players[cp].hasRank(r));

		if (players[op].hasRank(r))
		{
			LinkedList tem = players[op].getCards(r);
			players[cp].addCards(tem);
			cout << players[op].getName() << " has that card!!" << endl;
		}
		else
		{
			cout << players[op].getName() << " does not have that card. Sorry! " << endl;
			r= -1;
		}

		return r;
	}
	//*/
	//input rank from the keyboard
	void GoFish::gameResults()
	{
		int points[2];
		
		for(int i=0; i < 2; i++)
		{
			points[i]= players[i].getPoints();
			cout << players[i].getName() << " has: " << points[i] << " points" << endl;
		}

		//make another loop so that the points of every player prints first
		/*for(int j=0; j<2; j++)
		{
			if(points[j] >= 7 || points[j] >= points[j+1] || points[j] >= points[j-1])
			{
				cout << "CONGRATULATIONS " << players[j].getName() << " A WINNER IS YOU!" << endl << players[j].getName() << " won with " << points [j] << " points" << endl << "GAME OVER!!!!!";
			}
		}
		 // if it was designed for multiplayer there would be a search to find the player with the most points sorta, better then the above..
		int j=0;
		if(!(points[j] >= 7 || points[j] > points[j+1]))
			j=1;
		cout << "CONGRATULATIONS " << players[j].getName() << " A WINNER IS YOU!" << endl << players[j].getName() << " won with " << points [j] << " points" << endl << "GAME OVER!!!!!";
		*/

		if(points[0] >= points[1])
			{
				cout << "CONGRATULATIONS " << players[0].getName() << " A WINNER IS YOU!" << endl << players[0].getName() << " won with " << points [0] << " points" << endl << "GAME OVER!!!!!" << endl;
			}
		if(points[1] >= points[0])
			{
				cout << "CONGRATULATIONS " << players[1].getName() << " A WINNER IS YOU!" << endl << players[1].getName() << " won with " << points [1] << " points" << endl << "GAME OVER!!!!!";
			}


		exit(1);
	} 
	//Display game results

	void GoFish::turn(int ccp)
	{
		cout << "It is now " << players[ccp].getName() << "'s turn : " << endl;
		//check if the game ended, if either player has no cards in their hand, or if the deck is empty;
		if(players[cp].emptyHand() || deck.isEmpty())
		{
			gameResults();
			return; //it should exit the program anyways
		}
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << players[ccp].getName() << " its your turn and you have: " << players[ccp].showHand() << endl;

		if ( getRank(op) == -1 )
		{
			cout << "Go Fish! " << endl;
			players[cp].addCard(deck.deal());
		}

		int p= players[cp].checkHand();
		cout << endl << "You have " << p << " points" << endl;
		//checks to see if he has 7 or more points the game is over, as he must win,
		if (p >= 7)
		{
			gameResults();
		}

		//change the players, for two players we will do a temp switch
		int temp;
		temp=cp;
		cp=op;
		op=temp;
		turn(cp);//give the turn to the current player
	}

		int convertStoNumb(string Text)
	{
		int Result;          //number which will contain the result
		istringstream convert(Text); // stringstream used for the conversion constructed with the contents of 'Text'
		                         // ie: the stream will start containing the characters of 'Text'
			if ( !(convert >> Result) ) //give the value to 'Result' using the characters in the stream
			    Result = 0;             //if that fails set 'Result' to 0
	return Result;
	}
