/*
 * ContactBook.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: SruliF
 *      I want to see comments on every file.
 *      The top should have your information and the goal of that certain file.
 *      Every method should have a least one line above it explaining what it does.
 *       More complicated code should have comments explaining what is going on.
Comments should also say what the expected input and output are of a function


Owner Name: Jason Farkas
File Goal: to define what occurs in the contact book class.
methods: add, delete, update, search, display, choose a contact( for the user to "highlight" a contact, making it the default contact for editing), select a contact(for the program), start search( to take user input and find a contact based off that), and a function which creates contacts to test them.
it also includes some overrides for other types of output and selection of contacts

 */
#include "ContactBook.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <typeinfo>

int convertStoNumb(string Text); // this is not part of the contact class but is a function that may be used in anything that calls the contact class
int convertStoNumb(string Text)
{
	int Result;          //number which will contain the result
	istringstream convert(Text); // stringstream used for the conversion constructed with the contents of 'Text'
	                         // ie: the stream will start containing the characters of 'Text'
		if ( !(convert >> Result) ) //give the value to 'Result' using the characters in the stream
		    Result = 0;             //if that fails set 'Result' to 0
return Result;
}

//function to add a contact via user input
void ContactBook::addContact()
{
	//new code grows the array if it is too small and then adds the contacts
	while (currentCNum+2 >= bookLimit)
	{
		grow();
	}
	//once it is the right size...

	Contact* temp= new Contact;
	(*temp).inputAllInfo(); //have the user input info for the new contact

	currentCNum+=1; // say that the space has been occupied
	delete cBook[currentCNum]; // clear the empty contact there

	bool inserted=false; //once inserted this becomes true and the loop will stop trying to input the new contact

	for(int j=0; inserted==false && j< currentCNum-1; j++) // search to find the location where the new contact is earlier in the alphabet than a contact, then shift that contact and all others over by one location by having the last point until that point point to one before their location, and then have that location point to the added new contact
	{

		if( (*temp) < (*cBook[j])) // if the new contact is greater then that at j,
		{
			for(int q=currentCNum; q > j; q--)
			{
				cBook[q]=cBook[q-1];
			}
			cBook[j]=temp;
			inserted=true;
		}


	}

	if(inserted== false) // aka, it was later in the alphabet then all other choices then add it last,
	{
			cBook[currentCNum-1]=temp; //place it at the open location
			inserted=true;
	}
	temp=NULL;

}

	//same idea as addContact, but uses the overload
	istream& operator >> (istream& in, ContactBook& book) // add a contact into the next avaible space if there is.
	 {
		//new code grows the array if it is too small and then adds the contacts
	while (book.currentCNum +2 >= book.bookLimit)
	{
		book.grow();
	}
	//once it is the right size...
	Contact* temp= new Contact;
	book.cBook[book.currentCNum]= new Contact;
	in >> *temp;
	cout << *temp;

	book.currentCNum = book.currentCNum + 1; // make note that the space has been occupied
	delete book.cBook[book.currentCNum];

	bool inserted=false; //once inserted this becomes true and the loop will stop trying to input the new contact

	//place it into the book at the proper location
	for(int j=0; j< book.currentCNum; j++) // search to find the location where the new contact is earlier in the alphabet than a contact, then shift that contact and all others over by one location by having the last point until that point point to one before their location, and then have that location point to the added new contact
	{
		if(inserted==false)
		{

		if( ((*temp) < (*book.cBook[j])) ) // if the new contact is greater then that at j,
		{
			for(int q=book.currentCNum; q > j; q--)
			{
				book.cBook[q]=book.cBook[q-1];
			}
			book.cBook[j]=temp;
			inserted=true;

		}

		}
	} //the loop has stopped because we have tested to see if where the new contacts belongs and have inserted it, or because it is later in the alphabet then everything else

	if(inserted== false) // aka, it was later in the alphabet then all other choices then add it last,
	{
		book.cBook[book.currentCNum-1]=temp; //place at the open location
		inserted=true;
	}
	temp=NULL;
	return in;

	 }


void ContactBook::deleteContact() //deletes a contact,
{
	if(currentCNum > 0) // if there is a contact
	{
		cout << endl << "In order to update a contact you must first select a contact ";
		chooseAContact();  // let them choose a contact ( sometimes they can go through this function without having a contact chosen still) so...
		while(chosenContact < 0) // where there is no chosen contact then have them choose one, until there is one
		{
		cout << endl << "In order to delete a contact you must first select a contact ";
		chooseAContact();
		}
		cout << endl << "Are you sure that you would like to delete this contact? ";
		string y = " ";
		cin >> y;
		while(y != "yes" && y != "no")
			{
				cout << endl << "Sorry I did not understand, please try again " ;
				cin >> y;
			}
		if(y == "yes")  // if they want to delete then..
		{
			for (int i= chosenContact; i < currentCNum; i++) // start from the chosen contact and make its info the info of the contact after it until the last contact filled in.
			{
				cBook[i] = cBook[i+1];
			}
			delete cBook[chosenContact]; //actually deletes the new contact
			cBook[currentCNum-1]= NULL; // prevents there from being a dangling pointer
			currentCNum= currentCNum - 1; // there is now one less contact
			chosenContact = chosenContact -1; // choose the contact one before the chosen contact to make it easier to delete multiple contacts
			cout << endl << "Mission accomplished, contact has been eliminated. ";
		}
	}

	else // if there are no contacts
	{
		cout << endl << "You need a contact to delete a contact, why don't you go ahead and add one? ";
	}
}


void ContactBook::updateContact() // prompts the user to enter traits to change and then proceeds to let user change those traits
{
	if(currentCNum > 0) // if they have contact then
		{
	string line;
	string x=" ";
	bool stillEditing = true;

	cout << endl << "In order to update a contact you must first select a contact ";
	chooseAContact(); // let them choose a contact
	while(chosenContact < 0) //until there is a chosen contact prompt them to choose one
	{
	cout << endl << "In order to update a contact you must first select a contact ";
	chooseAContact();
	}

	cout << endl << "This is what I know about your contact"; // print out the info so that they can decide what to edit
	(*cBook[chosenContact]).printAllInfo();
	cout << endl;

///edit that info the user inputs...
	while(stillEditing) // until they decide to stop editing
	{
	cout << "What would you like to edit? " << endl;
	cin.ignore(); // clear the input
	getline(cin, line);

	// have a bunch of if statements to check if the user input includes keywords that start the editing process for that trait
	if (( line.find("first") != line.npos || line.find("First") != line.npos ) && (line.find("name") != line.npos || line.find("Name") != line.npos ))
	{
		cout << endl << "ok please tell me the new first name you would like for this contact " << endl ;
		cin >> x;
		(*cBook[chosenContact]).modFname(x);
	}

	if ( (line.find("last") != line.npos  || line.find("Last") != line.npos  ) && (line.find("name") != line.npos  || line.find("Name") != line.npos  ))
		{
			cout << endl << "ok please tell me the new last name you would like for this contact ";
			cin >> x;
			(*cBook[chosenContact]).modLname(x);
		}

	if ( (line.find("address") != line.npos && line.find("address") != (line.find("email") + 6) )  || (line.find("Address") != line.npos && line.find("Address") != (line.find("Email") + 6) )) // I assume if one is capital the other will be as well, but it may not be and a proper code would account for that
		{
			cout << endl << "ok please tell me the new address info you would like for this contact ";
			//cin >> x;
			(*cBook[chosenContact]).modAddress();
		}
	if (line.find("phone") != line.npos  || line.find("Phone") != line.npos )
		{
				string y ="0";
				cout << endl << "ok please tell me the Phone number info you would like for this contact ";
				cin >> y;
				(*cBook[chosenContact]).modPhoneNum(y);
		}
	if (line.find("email") != line.npos  || line.find("Email") != line.npos )
		{
			cout << endl << "ok please tell me the new email info you would like for this contact ";
			cin >> x;
			(*cBook[chosenContact]).modEmail(x);
		}
	if (line.find("group") != line.npos  || line.find("Group") != line.npos )
		{
			cout << endl << "ok please tell me the new group info you would like for this contact ";
			cin >> x;
			(*cBook[chosenContact]).modGroup(x);
		}

	cout << "Would you like to update any other info? ";
	cin >> x;
	while(x != "yes" && x != "no")
		{
			cout << endl << "Sorry I did not understand, please try again " ;
			cin >> x;
		}
	if (x == "no")
		{
			stillEditing = false; // take them out of the editing loop
		}

	}// end while still editing
		}// end if no contacts
	else  // if there are no contacts
	{
		cout<< endl << "You need to have contacts before I can update them. Why not add one? ";
	}


}

void ContactBook::searchContacts(string &cName)// searches the contacts for one with a particular name and prints all matches, it then enables the user to select from matches to save that contact and make it eaiser for further editing( such as delete and or update)
{
	int indexNum[10]= {0}; // create an array to hold the indexes of the contacts that we will find.  This is to account for multiple contacts with the same name
	int matchesFound=0;
	for(int i=0; i < currentCNum; i++ )
		{
			if(cName==(*cBook[i]).getFname()) // if there name that is being searched is equal to the name of contact i
			{
				cout << endl << "That is the name of contact number " << i << endl;
				if(matchesFound < 10)
				{
					indexNum[matchesFound]= i; // the first match is at index zero
					matchesFound = matchesFound+1 ;// now we are up to the second match
					if(matchesFound > 1) // if this is the second (or more ) match found
					{
						cout<<"This is the " << matchesFound << " person with that name " << endl;
					}
					(*cBook[i]).printAllInfo();
				}
				else // if 10 or more matches are found
				{
					cout << endl << "dude you have more then ten people who match that name... sorry but I can't remember more... ";
				}

			}
		}
	if(matchesFound <= 0) // no matches found
		{
			cout << endl << "I'm sorry but you don't seem to have a contact with that name ";
		}

	else if(matchesFound == 1) // only one match found, enable them to select this contact
	{
		cout <<endl << "Would you like to select this contact's for editing? ";
		string y = " ";
		cin >> y;
			while(y != "yes" && y != "no")
				{
					cout << endl << "Sorry I did not understand, please try again " ;
					cin >> y;
				}
			if (y == "yes" || y == "select")
				{
				chosenContact = indexNum[0];
				}
	}
	else if (matchesFound > 1) // if there are multiple matches, enable them to choose which of them to select
	{
	cout <<endl << "Would you like to select one of these contact's for editing? ";
	string x = " ";
	cin >> x;
	while(x != "yes" && x != "no")
		{
			cout << endl << "Sorry I did not understand, please try again " ;
			cin >> x;
		}
	if (x == "yes" || x == "select") // choose which match to select
		{
			cout << endl << "Please tell me the nth (1,2...) match, and I will select it for you ";

			string inputField= "Blank input"; // to hold user input
			int inputInt = 1; //convertStoNumb(inputField); // a number which the user entered or 0 if it contains non-numerical characters

			cin >> inputField; // accepts any character from user
			inputInt = convertStoNumb(inputField); //if string only contains numerical characters it  converts them to an int

			while (inputInt <= 0 || inputInt > matchesFound) // checks that number is within specified range
			{
				cout << endl << "I'm sorry, but there is no such match for your search" << endl << "Please tell me the nth (1,2...) match, and I will select it for you "; //prompts user to enter a number
				cin >> inputField; // accepts any character from user
				inputInt = convertStoNumb(inputField); //if string only contains numerical characters it  converts them to an int
			}
			chosenContact = indexNum[inputInt-1];
		}

	}

}

//search via the last name
void ContactBook::searchContactsByLastName(string &theLName)
{

int indexNum[10]= {0}; // create an array to hold the indexes of the contacts that we will find.  This is to account for multiple contacts with the same name
int matchesFound=0;
for(int i=0; i < currentCNum; i++ )
	{
		if(theLName==(*cBook[i]).getLname()) // if there name that is being searched is equal to the name of contact i
		{
			cout << endl << (*cBook[i]).getFname() << " " << (*cBook[i]).getLname() <<", contact number " << i << ", has that last name" << endl;
			if(matchesFound < 10)
			{
				indexNum[matchesFound]= i; // the first match is at index zero
				matchesFound = matchesFound+1 ;// now we are up to the second match
				if(matchesFound > 1) // if this is the second (or more ) match found
				{
					cout<<"This is the " << matchesFound << " person with that last name. " << endl;
				}
				(*cBook[i]).printAllInfo();
			}
			else // if 10 or more matches are found
			{
				cout << endl << "dude you have more then ten people who are in that group... sorry but I can't remember more... ";
			}

		}
	}
if(matchesFound <= 0) // no matches found
	{
		cout << endl << "I'm sorry but you don't seem to have a contacts in that group";
	}

else if(matchesFound == 1) // only one match found, enable them to select this contact
{
	cout <<endl << "Would you like to select this contact's for editing? ";
	string y = " ";
	cin >> y;
		while(y != "yes" && y != "no")
			{
				cout << endl << "Sorry I did not understand, please try again " ;
				cin >> y;
			}
		if (y == "yes" || y == "select")
			{
			chosenContact = indexNum[0];
			}
}
else if (matchesFound > 1) // if there are multiple matches, enable them to choose which of them to select
{
cout <<endl << "Would you like to select one of these contact's for editing? ";
string x = " ";
cin >> x;
while(x != "yes" && x != "no")
	{
		cout << endl << "Sorry I did not understand, please try again " ;
		cin >> x;
	}
if (x == "yes" || x == "select") // choose which match to select
	{
		cout << endl << "Please tell me the nth (1,2...) match, and I will select it for you ";

		string inputField= "Blank input"; // to hold user input
		int inputInt = 1; //convertStoNumb(inputField); // a number which the user entered or 0 if it contains non-numerical characters

		cin >> inputField; // accepts any character from user
		inputInt = convertStoNumb(inputField); //if string only contains numerical characters it  converts them to an int

		while (inputInt <= 0 || inputInt > matchesFound) // checks that number is within specified range
		{
			cout << endl << "I'm sorry, but there is no such match for your search" << endl << "Please tell me the nth (1,2...) match, and I will select it for you "; //prompts user to enter a number
			cin >> inputField; // accepts any character from user
			inputInt = convertStoNumb(inputField); //if string only contains numerical characters it  converts them to an int
		}
		//
		chosenContact = indexNum[inputInt-1];
	}
}
}

//Search via group name
void ContactBook::searchContactsByGroup(string &gName)// searches the contacts for one with a particular name and prints all matches, it then enables the user to select from matches to save that contact and make it eaiser for further editing( such as delete and or update)
{
	int indexNum[10]= {0}; // create an array to hold the indexes of the contacts that we will find.  This is to account for multiple contacts with the same name
	int matchesFound=0;
	for(int i=0; i < currentCNum; i++ )
		{
			if(gName==(*cBook[i]).getGroup()) // if there name that is being searched is equal to the name of contact i
			{
				cout << endl << (*cBook[i]).getFname() << " " << (*cBook[i]).getLname() <<", contact number " << i << ", and is the in that group" << endl;
				if(matchesFound < 10)
				{
					indexNum[matchesFound]= i; // the first match is at index zero
					matchesFound = matchesFound+1 ;// now we are up to the second match
					if(matchesFound > 1) // if this is the second (or more ) match found
					{
						cout<<"This is the " << matchesFound << " person in that group. " << endl;
					}
					(*cBook[i]).printAllInfo();
				}
				else // if 10 or more matches are found
				{
					cout << endl << "dude you have more then ten people who are in that group... sorry but I can't remember more... ";
				}

			}
		}
	if(matchesFound <= 0) // no matches found
		{
			cout << endl << "I'm sorry but you don't seem to have a contacts in that group";
		}

	else if(matchesFound == 1) // only one match found, enable them to select this contact
	{
		cout <<endl << "Would you like to select this contact's for editing? ";
		string y = " ";
		cin >> y;
			while(y != "yes" && y != "no")
				{
					cout << endl << "Sorry I did not understand, please try again " ;
					cin >> y;
				}
			if (y == "yes" || y == "select")
				{
				chosenContact = indexNum[0];
				}
	}
	else if (matchesFound > 1) // if there are multiple matches, enable them to choose which of them to select
	{
	cout <<endl << "Would you like to select one of these contact's for editing? ";
	string x = " ";
	cin >> x;
	while(x != "yes" && x != "no")
		{
			cout << endl << "Sorry I did not understand, please try again " ;
			cin >> x;
		}
	if (x == "yes" || x == "select") // choose which match to select
		{
			cout << endl << "Please tell me the nth (1,2...) match, and I will select it for you ";

			string inputField= "Blank input"; // to hold user input
			int inputInt = 1; //convertStoNumb(inputField); // a number which the user entered or 0 if it contains non-numerical characters

			cin >> inputField; // accepts any character from user
			inputInt = convertStoNumb(inputField); //if string only contains numerical characters it  converts them to an int

			while (inputInt <= 0 || inputInt > matchesFound) // checks that number is within specified range
			{
				cout << endl << "I'm sorry, but there is no such match for your search" << endl << "Please tell me the nth (1,2...) match, and I will select it for you "; //prompts user to enter a number
				cin >> inputField; // accepts any character from user
				inputInt = convertStoNumb(inputField); //if string only contains numerical characters it  converts them to an int
			}
			//
			chosenContact = indexNum[inputInt-1];
		}
	}
}
//

//this function enables the user to search by using the group name, or last name,
bool ContactBook::advancedStartSearch(int criteria) // if criteria is 1, search by fname, 2 lname, 3 group
{
	if(criteria==0) //this is default and enables a user to choose the criterion and based on that recalls this function with that criterion
	{
		int cc=999;
		do
		{
		string c= "";
		cout << endl << "Please choose a valid search criterion: First-name, Last-name, Group-name";
		cin >> c;
			if(c=="First-name")
			{
				cc=1;
			}
			else if (c=="Last-name")
			{
				cc=2;
			}
			else if (c=="Group-name")
			{
				cc=3;
			}

		}while(!advancedStartSearch(cc)); //This will call advanced search and if cc is not a preset number aka 999, it will return false and have the user enter a valid criteria
	}
	else if(criteria==1) //this is search by name feature
	{
		startSearch();//
		return true;
	}
	else if(criteria==2) //this is search by last name feature
	{
		string theLName;
		cout << "Please enter a last name to search " << endl;
		cin >> theLName;
		searchContactsByLastName(theLName);
		return true;
	}
	else if(criteria==3) //this is search by group name feature
	{
		string theGName;
		cout << "Please enter a group name to search " << endl;
		cin >> theGName;
		searchContactsByGroup(theGName);
		return true;
	}
	else
	{
		return false; // because no search was performed
	}
	return false;
}

void ContactBook::startSearch() //prompts the user to search for a user name
{
	string theName;
	cout << "Please enter a first name to search " << endl;
	cin >> theName;
	searchContacts(theName);
}

ostream& operator << (ostream& out, const ContactBook& book)
{
	 string oStream= "os";
	 string fStream= "St14basic_ofstreamIcSt11char_traitsIcEE";
	 if(typeid(out).name() == oStream)
	 {
	if(book.currentCNum > 0) // if there is a contact or more
		{
		int i=0;
		while(i < book.currentCNum)
		{

			out << endl << (*book.cBook[i])  << endl;;
			i++;

		}
		out << endl;
		//cout << endl<<  book.currentCNum << "  contacts" ; // Display the number of contacts as well
		}
	else
		{
			out << endl << "I'm sorry but you don't yet have any contacts to display";
		}
	 }
	 else if(typeid(out).name() == fStream)
	 {
		out << book.oName << " | " << book.oLName; //currently does not save the full contact info of the owner
		if(book.currentCNum > 0) // if there is a contact or more
		{
			int i=0;
			while(i < book.currentCNum)
			{
				out << endl << (*book.cBook[i]);
				i++;
			}
		}

		out << endl<< "endbook | " << endl;
	 }
	 else
	 {
		 if(book.currentCNum > 0) // if there is a contact or more
		{
		int i=0;
		while(i < book.currentCNum)
		{

			out << endl << (*book.cBook[i]);
			i++;

		}
		out << endl;
		//cout << endl<<  book.currentCNum << "  contacts" ; // Display the number of contacts as well
		}
	else
		{
			out << endl << "I'm sorry but you don't yet have any contacts to display" << endl;
		}

	 }
	return(out);
}

void ContactBook::displayAll()
{
	if(currentCNum > 0) // if there are contacts to display
	{
	for(int i=0; i < currentCNum; i++)
	{
		cout<< endl;
		(*cBook[i]).printAllInfo();
	}
	}
	else
	{
		cout << endl << "I'm sorry but you don't yet have any contacts to display" << endl;
	}
}

void ContactBook::selectContact(int toSelect)// sets the chosen contact the the index to be selected
{
	chosenContact = toSelect;
}

void ContactBook::chooseAContact() //function to have  a user " highlight a new contact if desired
{

	if(chosenContact > -1) // if there is already a contact chosen
	{

		cout << endl << "Currently " << (*cBook[chosenContact]).getFname() + " " + (*cBook[chosenContact]).getLname() << " is selected";
		cout << endl << "Would you like to select a different contact? ";
		string x = " ";
		cin >> x;
		while(x != "yes" && x !="no") // make sure the user say yes or no and repeat until they do.
			{
				cout << endl << "Sorry I did not understand, please try again " ;
				cin >> x;
			}
		if (x == "no") // if they like the contact that they chose then end the function because they don't need to chooe a contact
			{
				return;
			}
	}
	// in order to choose a new contact


		string inputField= "Blank input"; // to hold user input
		int inputInt = -3; // convertStoNumb(inputField); // a number which the user entered or 0 if it contains non-numerical characters

		while (inputInt < -2 || inputInt >= currentCNum) // until a proper contact is chosen
			{
				cout << endl << "Please select a contact by index number, or choose to search and select a contact by name by typing -1, or more advanced options with -2 ";
				cin >> inputField;
				inputInt = convertStoNumb(inputField);
				if (inputInt < -2 || inputInt >= currentCNum)
				{
					cout << endl << "You don't have such a contact ";
				}
			}
		if (inputInt == -1) // select a contact by name
			{
			startSearch(); // selects a contact by name
			return;
			}
		else if (inputInt == -2) // select a contact by another criteria
			{
			advancedStartSearch(0);
			return;
			}

		else  // choose a contact based on the index number provided
			{
			chosenContact = inputInt;
			}
		cout << endl << "You selected " << (*cBook[currentCNum]).getFname() << " " << (*cBook[currentCNum]).getLname();

}
//default constructor
ContactBook::ContactBook()
{
	bookLimit= 10;
	cBook= new Contact*[bookLimit];
	currentCNum = 0;
	chosenContact = -1;

	Address blankP= Address();
	oName= " ";
	oLName= " ";
	string tNumb="0000000000";
	string tmail= "none@none.com";
	string groupy= "Me";
	owner= Contact(oName, oLName, blankP, tNumb , tmail, groupy);

}

ContactBook::ContactBook(int limit)
{

	bookLimit= limit;
	cBook= new Contact*[bookLimit];
	currentCNum = 0;
	chosenContact = -1;

	Address blankP= Address();
	oName= " ";
	oLName= " ";
	string tNumb="0000000000";
	string tmail= "none@none.com";
	string groupy= "Me";
	owner= Contact(oName, oLName, blankP, tNumb , tmail, groupy);
}
ContactBook::ContactBook(string oname){
	//constructor that set the owner name
	bookLimit= 10;
	cBook= new Contact*[bookLimit];
	currentCNum = 0;
	chosenContact = -1;

	Address blankP= Address();
	oName= oname;
	oLName=" ";
	string tNumb="0000000000";
	string tmail= "none@none.com";
	string groupy= "Me";
	owner= Contact(oName, oLName, blankP, tNumb , tmail, groupy);
}

ContactBook::ContactBook(string oname, int limit){
	//constructor that set the owner name and set the limit to a different number

	bookLimit= limit;
	cBook= new Contact*[bookLimit];
	currentCNum = 0;
	chosenContact = -1;

	Address blankP= Address();
	oName= oname;
	oLName= " ";
	string tNumb="0000000000";
	string tmail= "none@none.com";
	string groupy= "Me";
	owner= Contact(oName, oLName, blankP, tNumb , tmail, groupy);
}

ContactBook::ContactBook(string oname, string oLname, int limit)
{

	bookLimit= limit;
	cBook= new Contact*[bookLimit];
	currentCNum = 0;
	chosenContact = -1;

	Address blankP= Address();
	oName= oname;
	oLName=oLname;
	string tNumb="0000000000";
	string tmail= "none@none.com";
	string groupy= "Me";
	owner= Contact(oName, oLName, blankP, tNumb , tmail, groupy);
}

ContactBook::ContactBook(string oname, string oLname)
{

	bookLimit= 10;
	cBook= new Contact*[bookLimit];
	currentCNum = 0;
	chosenContact = -1;

	Address blankP= Address();
	oName= oname;
	oLName=oLname;
	string tNumb="0000000000";
	string tmail= "none@none.com";
	string groupy= "Me";
	owner= Contact(oName, oLName, blankP, tNumb , tmail, groupy);
}


Contact& ContactBook::operator [] (int n)  // select a contact with the  [ ]
{
	if (n < currentCNum)
	{
	return (*cBook[n]);

	}
	else
	{
		exit(0); // until error handleing is established
	}
}


void ContactBook::createtotest()
{

	string userIN= " ";
	string userINf= "john";
	string userINl= "alpha";
	string userNumb= "2010000191";
	//cBook))= new Contact; cout << "hi";
	cBook[1]= new Contact (userINf, userINl, userNumb, userIN, userIN);

	currentCNum += 1;

	string userINfb= "b";
	string userINlb= "beta";
	cBook[0]= new Contact (userINfb, userINlb, userNumb, userIN, userIN);
	currentCNum += 1;

	string userINfc= "a";
	string userINlc= "beta";
	cBook[7]= new Contact (userINfc, userINlc, userNumb, userIN, userIN);
	currentCNum += 1;

	string userINfd= "b";
	string userINld= "alpha";
	cBook[2]= new Contact (userINfd, userINld, userNumb, userIN, userIN);
	currentCNum += 1;

	string userINfe= "b";
	string userINle= "alpha";
	cBook[6]= new Contact (userINfe, userINle, userNumb, userIN, userIN);
	currentCNum += 1;

	cBook[3]= new Contact (userINf, userINl, userNumb, userIN, userIN);
		currentCNum += 1;
		cBook[5]= new Contact (userINf, userINl, userNumb, userIN, userIN);
			currentCNum += 1;
			cBook[8]= new Contact (userINf, userINl, userNumb, userIN, userIN);
				currentCNum += 1;
				cBook[4]= new Contact (userINf, userINl, userNumb, userIN, userIN);
					currentCNum += 1;

				sort(); //organizes those contacts via alphabetical order


/*
	cout<< endl;
	for (int i =0; i < currentCNum-1; i++)
	{
		if(cBook[i] < cBook[i+1])
		{
			cout << endl << cBook[i] << endl << "Is earlier then" << cBook[i+1];
		}

		if(cBook[i] == cBook[i+1])
		{
			cout << endl << cBook[i] << endl << "Is = to" << cBook[i+1];
		}

		if(cBook[i] != cBook[i+1])
		{
			cout << endl << cBook[i] << endl << "Is not = to " << cBook[i+1];
		}
	}
*/
}
///big three
ContactBook::ContactBook(const ContactBook &otherBook)
{
	//copy constructor
	bookLimit = otherBook.bookLimit;
	cBook= new Contact*[bookLimit];
	currentCNum = otherBook.currentCNum;
	chosenContact = -1; // does not copy over the selected contact info
	for(int i=0; i < currentCNum; i++)
	{
		*cBook[i] = *otherBook.cBook[i];
	}

}
ContactBook::~ContactBook()
	{
		//destructor
		//cBook= new Contact[bookLimit];
		for(int i=0; i < currentCNum; i++)
		{
			delete cBook[i];  //deletes the new contacts
			cBook[i]= NULL;  //makes the pointers that pointed to them under control
		}

		delete[] cBook; //deletes the pointers that pointed to the contacts
		cBook= NULL; //prevents the top level pointer from dangling
	}

ContactBook ContactBook::operator = (const ContactBook &otherBook)
{
	// assignment overload
	if(this != &otherBook) // if the object is not itself, clear it, and then remake all values equal to those of bookToBe
	{
		for(int i=0; i < currentCNum; i++)
			{
				delete cBook[i]; //deletes the new contacts
				cBook[i]= NULL; //makes the pointers that pointed to them under control
			}
			delete[] cBook; //deletes the pointers that pointed to the contacts
			cBook= NULL; //prevents the top level pointer from dangling

			bookLimit = otherBook.bookLimit; //copies the limit
			cBook= new Contact*[bookLimit];  //create a dynamic array of pointers to contacts
			currentCNum = otherBook.currentCNum; // set equal the amount of current contacts
			chosenContact = -1; // does not copy over the selected contact info

	for(int i=0; i < currentCNum; i++)
		{
			*cBook[i] = *otherBook.cBook[i];
		}
	}

	return *this;
}

int ContactBook::numbOfContacts() //returns the current number of contacts
		{
	return currentCNum;
		}
int ContactBook::currentCompacity() //returns the current number of contacts that can be stored, assuming grow is not called.
{
	return bookLimit;
}

string ContactBook::getOwner() //returns the LastName, FirstName of the owner
{
	string send=   oLName + " "+ oName;
	return send;
}

string  ContactBook::getOwnerFF()//returns the FirstName, LastName of the owner
{
	string send=  oName+ " "+ oLName;
	return send;
}

Contact ContactBook::ownerInfo() //returns the LastName, FirstName of the owner
{
	return owner;
}

void ContactBook::grow() //this function grows the amount of contacts the owner can holds, it creates a new temp pointer of pointers with a larger limit then the previous one and fills in all the info to match the current array, then it deletes the old info and has cBook point to the new array
{

	int newLimit =bookLimit*2+1;

	Contact ** tBook = new Contact*[newLimit];

	for(int i=0; i< currentCNum; i++)
	{
		tBook[i] = cBook[i];
	}

	for(int i =currentCNum; i< bookLimit; i++)
	{
		delete cBook[i];
		cBook[i] = NULL;
	}

	delete [] cBook;

	bookLimit=newLimit;
	cBook=tBook;
	tBook= NULL;

}


void ContactBook::addem(Contact& toAdd)
{
	// adds a parsed contact into sorted location
	while (currentCNum+2 >= bookLimit)
		{
			grow();
		}

	Contact* temp= new Contact;
	*temp= toAdd;

	currentCNum+=1;
	delete cBook[currentCNum]; // clear the empty contact there
	bool inserted=false; //once inserted this becomes true and the loop will stop trying to input the new contact

	for(int j=0; inserted==false && j< currentCNum-1; j++) // search to find the location where the new contact is earlier in the alphabet than a contact, then shift that contact and all others over by one location by having the last point until that point point to one before their location, and then have that location point to the added new contact
	{

		if( toAdd < (*cBook[j])) // if the new contact is greater then that at j,
		{
			for(int q=currentCNum; q > j; q--)
			{
				cBook[q]=cBook[q-1];
			}
			cBook[j]=temp;
			inserted=true;
		}

	}
	if(inserted== false) // aka, it was later in the alphabet then all other choices then add it last,
		{
				cBook[currentCNum-1]=temp; //place it at the open location
				inserted=true;
		}
		temp=NULL;
		//*/
}

void ContactBook::sort() //this function sorts the array so that contacts with a last name ( and then first name) closer to the start of the alphabet are first
{
	// sorts the contacts;
	Contact* temp; //temp to hold the data that will be switched

	for(int i=0; i < currentCNum; i++ )
	{
		int indexOfSmallest= i;

		for(int j=0; j< currentCNum; j++)
		{

			if((*cBook[j]) > (*cBook[indexOfSmallest])) // if the contact at i is greater then that at j,
			{
				cout << endl << *cBook[j] << endl << "is later than" << endl << *cBook[indexOfSmallest];
				indexOfSmallest=j;
			}///*
			//switch the location of the smallest in the set and the original fist in the set, ir locations so that (a,b) a will be first
			temp=cBook[i];
			cBook[i]=cBook[indexOfSmallest];
			cBook[indexOfSmallest]= temp;
			//*/
		}

	}

	temp=NULL; // make sure that temp is not a dangling pointer

}

ContactBook ContactBook::rmerge(const ContactBook& first, const ContactBook& second)
{
	//returns a contact book created by merging two contact books
	ContactBook nBook = first; //this is a new contact book that will hold all the contacts of both books, it starts as the first book
	nBook.oName=first.oLName;
	nBook.oLName=first.oLName;
	nBook.owner=first.owner;

	for(int i=0; i < second.currentCNum; i++) //for every contact in the second book filled in
		{
			nBook.addem(*second.cBook[i]); //add that contact to nBook
		}

	return nBook;
}

ContactBook ContactBook::merge(const ContactBook& other)
{
	//causes the caller to add all to itself all the contacts of the second without changing it.

	for(int i=0; i < other.currentCNum; i++) //for every contact in the other book filled in
	{
		addem(*other.cBook[i]); //add that contact to nBook
	}

	return *this;
}

ContactBook ContactBook::operator += (const ContactBook &other) // assignment overload that works the same as merge
{
	for(int i=0; i < other.currentCNum; i++) //for every contact in the other book filled in
		{
			addem(*other.cBook[i]); //add that contact to nBook
		}

	return *this;
}

ContactBook ContactBook::operator + (const ContactBook& other) // does the same as rmerge
{
	//returns a contact book created by merging two contact books
	ContactBook nBook = (*this); //this is a new contact book that will hold all the contacts of both books, it starts as the first book
	nBook.oName=(*this).oLName;
	nBook.oLName=(*this).oLName;
	nBook.owner=(*this).owner;

	for(int i=0; i < other.currentCNum; i++) //for every contact in the second book filled in
		{
			nBook.addem(*other.cBook[i]); //add that contact to nBook
		}

	return nBook;
}

//for saving, but is later not used
ofstream& operator << (ofstream& out, ContactBook& book)
{

	out << book.oName << " | " << book.oLName; //currently does not save the full contact info of the owner
	if(book.currentCNum > 0) // if there is a contact or more
	{
		int i=0;
		while(i < book.currentCNum)
		{
			out << endl << (*book.cBook[i]);
			i++;
		}
	}

	out << endl<< "endbook | " << endl;

	return(out);
}

//for saving, but is later not used
string& ContactBook::saver(string& outi)
{
	string l="";
	//passes back info to be saved,
	outi +=  oName + " | " + oLName; //currently does not save the full contact info of the owner
	if(currentCNum > 0) // if there is a contact or more
	{
		cout<<"Cout: "<< currentCNum;
		int i=0;
		while(i < currentCNum)
		{
			l +=  "\n";
			l += (*cBook[i]).saver(l);
			i++;
		}
	}

	outi += l +  "\n" ;
	outi+=  "endbook | ";
	outi+= "/n" ;;

	return(outi);
}



