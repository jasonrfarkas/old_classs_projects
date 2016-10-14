/*
 * ContactClassDec.h
 *
 *  Created on: Apr 4, 2014
 *      Author: SruliF
 *      Owner Name: Jason Farkas
File Goal: to declare what occurs in the contact class.
Variables: it holds name information( first and last), address info, contact info ( email and phone), and a group association ( for further recognition searching and categorization)
 Methods: includes accesssors and mutators for all variables, functions to determine if parts of a string are a character or a number, a function that uses that info to determine if an input is a valid phone number or email,
 also includes the ability for user to input or print all info and the ability to compare different contacts, with overloaded operators to make life better


 */

#include <string>
#include <iostream>
#include "Address.h"

#ifndef CONTACTS
#define CONTACTS

using namespace std;

class Contact {

private:

	string fName;
	string lName;
	Address address;
	string phoneNum;
	string email;
	string groupName; // this will be used as an alternative way to group contacts

public:
	Contact();

	Contact(string &first, string &last, Address &place, string &pNum , string &eplace);
	Contact(string &first, string &last, Address &place, string &pNum , string &eplace, string &gName);
	Contact(string &first, string &last/*string &place,*/, string &pNum, string &eplace, string &gName);
	Contact(string &pNum);

	//accessor functions
	string getFname() const;
	string getLname() const;
	string getAddress(string part) const;
	string getPhoneNum() const;
	string getEmail() const;
	string getGroup() const;
	Address getFullAddress() const;

	//mod functions
	void modFname(string newF);
	void modLname(string newL);
	void modAddress();
	void modPhoneNum(string newNumb);
	void modEmail(string newEmail);
	void modGroup(string newGroup);

	//others
	bool isCharacter(const char Character) const;
	bool isNumber(const char Character) const;
	bool isValidEmailAddress() const;
	bool isvalidPhoneNumber() const;
	bool isThisvalidPhoneNumber(string pNumb) const;
	bool isThisValidEmailAddress(string yolo) const;
	void inputAllInfo();
	void printAllInfo();
	friend ostream& operator <<(ostream& out, const Contact& guy);
	friend istream& operator >>(istream& in, Contact& guy);
	//for saving
	friend  ofstream& operator << (ofstream& out, const Contact& guy);
	string& saver(string& out);

	bool operator >(const Contact& guy);
	bool operator >=(const Contact& guy);
	bool operator <(const Contact& guy);
	bool operator <=(const Contact& guy);
	bool operator ==(const Contact& guy);
	bool operator !=(const Contact& guy);
	int compare(const Contact& guy); // function behind the comparisons
};

#endif
