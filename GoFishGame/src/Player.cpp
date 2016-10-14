
# include "Player.h"
# include <string>
#include <cstring>
# include <iostream>
using namespace std;

Player::Player():name(""),hand(Hand()),points(0)
{

}


Player::Player(string n):name(n),hand(Hand()),points(0)
{
}
	void Player::setName(string n)
	{
		name = n;
	}
	string Player::getName() const
	{
		return name;
	}
	string Player::playerInfo()
	{
		string temp = "Name: " + name + "  Points: ";
		temp += points;
		return temp;

	} //return player's info
	string Player::showHand() const
	{
		return hand.sDisplay();
	} //return player's hand as a string
	bool Player::hasRank(int r) const
	{
		return hand.hasRank(r);
	}
	void Player::addCard(Card* c)
	{
		hand.insertByRank(c);
	}
	/*void Player::addCards( LinkedList h)
	{
		cout<< "tesft" <<endl;
		//hand.insertHand(h);
		//hand.insertHand(h);
		cout << " testingyy " << endl;
	}*/
	void Player::addCards(LinkedList &h)
	{
		hand.insertHand(h);
	}

	Card* Player::getCardAt(int index) const
	{
		return hand.getCardAt(index);
	}
	int Player::checkHand()
	{
		points += hand.evaluate();
		return points;
		// hand.findRank(r)

	} //evaluate and return points of Hand
	int Player::getPoints()
	{
		return points;
	}
	int Player::getTotalCards()
	{
		return hand.getCount();
	} //return Player's total Cards

	bool Player::emptyHand()
	{
		//returns if hand is empty
		return hand.isEmpty();
	}
	LinkedList Player::getCards(Card* c)
	{
		return hand.findRank(c->getRank());
	}

	LinkedList Player::getCards(int r)
	{
		return hand.findRank(r);
	}
