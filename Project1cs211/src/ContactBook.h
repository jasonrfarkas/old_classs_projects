/*
 * ContactBook.h
 *
 *  Created on: Mar 19, 2014
 *      Author: SruliF
 *
Owner Name: Jason Farkas
File Goal: to declare what occurs in the contact book class.
methods: add, delete, update, search, display, choose a contact( for the user to "highlight" a contact, making it the default contact for editing), select a contact(for the program), start search( to take user input and find a contact based off that), and a function which creates contacts to test them.
it also includes some overrides for other types of output and selection of contacts
Variables: one array to hold all the contacts, a const int to limit the size of that array, int to track current amount of contacts, and an int to hold the "highlighted"/ "selected" contact
 *
 */

#ifndef CONTACTBOOK_H_
#define CONTACTBOOK_H_

#include "ContactClassDec.h"
#include <fstream>

class ContactBook{

private:
	int bookLimit;
	Contact ** cBook;
	int currentCNum; ///= 0;
	int chosenContact; // = -1;

	string oName; // stores owner first name ->b.c assignment mentions only by name, not as a contact
	string oLName; //stores owner last name ->b.c assignment mentions only by name, not as a contact
	void grow(); // enables an array to increase in size
	Contact owner; // stores owner info in the form of a contact, where all other fields are initialized to none or the equivalent, or to the owner name, currently those fields can't be changed from outside the class
	// default compacity can be a macro

public:
	//add new, delete, update, search, display  -> as member functions
	//size of contacts, get a contact at an index location.. anything else
	Contact ownerInfo(); //returns the info of the owner in the form of a contact
	string getOwner(); //returns the LastName, FirstName of the owner
	string getOwnerFF(); //returns the FirstName, LastName, of the owner
	int numbOfContacts(); // returns the number of contacts, aka CNum
	int currentCompacity();//returns the current compacity of the list
	void addContact(); // adds a contact // can be changed so this can also return a bool to see if successful
	void deleteContact();// deletes a contact  //can be changed so this can also return a bool to see if successful
	void updateContact(); // updates a contact  // can be changed to give a bool as well.
	void searchContacts(string &cName); // searches contacts // this can be changed to return an index
	void searchContactsByGroup(string &gName);//searches contacts by group
	void searchContactsByLastName(string &theLName);//searches contacts by last name
	void displayAll(); // displays all contacts
	friend  ostream& operator << (ostream& out, const ContactBook& book); // prints out all contacts when the contact book is prefaces by a cout <<
	friend  istream& operator >> (istream& in, ContactBook& book); // prompts user to enter in a contact info when contact book is preface by cin>>
	void chooseAContact(); // this prompts the user to choose a contact, which can then be edited or delete and so on.
	void selectContact(int toSelect); // this takes an argument of a contact and sets the variable chosen contact to be the index of the selected contact.To enable other functions to work with the contact that is now accessible via that variable
	void startSearch();  // prompts the user to find a contact.
	bool advancedStartSearch(int criteria); // prompts the user to search from another criteria, such as group name. It returns a bool if the function was called properly
	void createtotest();// create contacts to test other functions
    Contact& operator [] (int n); // //void printAllInfo();

	ContactBook(); // default constructor
	ContactBook(string oname);//constructor that set the owner first name
	ContactBook(string oname, string oLname);//constructor that set the owner first name and last name
	ContactBook(int limit);//constructor that set the limit to a different number
	ContactBook(string oname, int limit); //constructor that set the owner first name and set the limit to a different number
	ContactBook(string oname, string oLname, int limit); //constructor that set the owner first name,last name, and sets the limit to a different number
	//ContactBook(string oname, string oLname);

	//big three
	ContactBook(const ContactBook  &otherBook); //copy constructor
	~ContactBook(); //destructor
	ContactBook operator = (const ContactBook &otherBook); // assignment overload

	void addem(Contact& toAdd); // adds a parsed contact into sorted location
	void sort(); // sorts the contacts;
	ContactBook rmerge(const ContactBook& first, const ContactBook& second); //returns a contact book created by merging two contact books
	ContactBook merge(const ContactBook& other);//causes the caller to add all to itself all the contacts of the second without changing it.
	ContactBook operator += (const ContactBook &other); // assignment overload that performs the same as merge
	ContactBook operator + (const ContactBook& other); //should be the same as rmerge, just with an overload

	// for file saving
	friend  ofstream& operator << (ofstream& out,  ContactBook& book);
	string& saver(string& out); //passes back info to be saved,
};



#endif /* CONTACTBOOK_H_ */
