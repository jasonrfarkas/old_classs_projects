/*
 * RunBook.cpp
 *
 *  Created on: Mar 23, 2014
 *      Author: SruliF
 *
 *
 *      This file creates an array of 5 contact books, which can be accessed individually, merged, printed as one, and other features,
 *      when close properly it will save the data to a file, when it is opened it will automatically attempt to load previous contacts, and will report an error if it cannot,
 */

#include <iostream>
#include "ContactClassDec.h" /// .h
#include "ContactBook.h"
#include <string>

using namespace std;

bool searchAndSelect();
int saveBooksToFile();
int findbook(string tName);
int loadData();

int numbOfBooks = 0; //stores how many contact books are open
int selectedBook = -1; //stores which book is selected
ContactBook* booklife[5];// This creates an array of pointers to ContactBooks// = ContactBook();

int main()
{
	if(loadData())  //first try to load the data, if you can great
	{
		cout << "Previous contacts have been loaded"<<endl;
	}
	else //if you can't then print an error
	{
		cout << "No previous contacts have been loaded"<<endl;
	}


	int gmenu= 1; //this is a menu for what happens regarding all contact books
	int menu = 1; //this is a menu for a specific contact book


	for(int i=0;i<5;i++)
	{
		ContactBook* booklife[i];
		booklife[i]= NULL;
	}

	/*  //to test all the books with test info
	for(int i=0;i<5; i++) //for every contact book
		{
		(*booklife[i]).createtotest();  // this will create users and print out their info and if they are < or = to the user after themselves.
		}
	*/


	while(gmenu > 0 )
	{
		//create a variable to input user input and then detect what they requested from the menu
		string gCommand= " ";
		cout<< endl <<"MENU:Please enter a command; create, remove, display-all, merge, or select a contact book for further editing, or save and exit program ";
		getline(cin, gCommand);


		if(gCommand == "create")
		{

			// create
			string y= " ";
			string z= " ";
			cout<< endl<< "Who is the owner of this ContactBook? FirstName: ";
			getline(cin, y);
			cout << endl << "LastName: ";
			getline(cin, z);
			booklife[numbOfBooks]= new ContactBook(y, z);
			cout << endl << "added";
			//cin >> (*booklife[numbOfBooks]);


			numbOfBooks+=1;
		}

		if(gCommand == "remove")
		{
			// remove
			if(searchAndSelect())
			{
			cout << endl << "Are you sure you would like to remove this book? ";

			string x = " ";
			getline(cin, x);
			while(x != "yes" && x !="no") // make sure the user say yes or no and repeat until they do.
				{
					cout << endl << "Sorry I did not understand, please try again " ;
					cin >> x;
				}
			if(x=="yes")
			{
			delete (booklife[selectedBook]);
			//have every pointer to a book, that is after the selected book, point to one location earlier.
			for(int i=selectedBook; i < numbOfBooks; i++) //starting from the point that points to nothing
			{
				booklife[i]=booklife[i+1]; //have it point to the space after it,
			}
			booklife[numbOfBooks]=NULL; //prevent dangling pointer
			numbOfBooks-=1; //tell the system the book is gone
			cout << endl << "Contact book has been burnt ";
			}
			}
			else
			{
				cout << endl <<"You need to have a Contact Book first..  ";
			}

		}


		if(gCommand == "display-all")
		{
			// display function
			for(int i=0; i < numbOfBooks; i++) //loop through each book
			{
			cout << endl <<"New Contact Book:" << endl << "Book Owner: " << (*booklife[i]).getOwner()  << (*booklife[i]); //.displayAll();
			}
		}

		if(gCommand == "merge")
		{
			// merge
			cout << endl <<"Please choose the primary book, which will be changed ";
			if( searchAndSelect())
			{// select the first
			//cout << endl << "Now please the secondary book, who contents you would like to copy to the Primary Book ";
			int q = -1;

			while(q < 0)
			{
				cout << endl << "Please select a secondary book to work with by typing the last-name space first-name of the owner ";
				string tName= " ";
				getline(cin, tName);
				q = findbook(tName);
				if (q ==-1)
					cout<< endl << " sorry by that contact book cannot be found...";
			}

			(*booklife[selectedBook]) += (*booklife[q]);
		}
			else
			{
				cout << endl <<"You need to have a Contact Book first..  ";
			}
		}

		if(gCommand == "select")
		{
			 //First let them select a book
			if(searchAndSelect())
			{
			menu = 1 ;
			bool once=false; // this is a bool to keep track of how many times SUBMENU options was displayed. (otherwise it seems to print out twice....)
			//present them with the submenu
			while(menu > 0)// add,delete,display, update, display entire contact list exit
			{

				string command = "" ;
				if(once!=true)
				{
				cout<< endl <<"		SUBMENU:Please enter a command; add, delete, update, or display a contact or display-all, or exit ";
				once=true;
				}
				getline(cin, command);

				if(command == "display-all")
				{
					// display function
					cout << (*booklife[selectedBook]); //.displayAll();
					once=false;
				}

				if(command == "update")
				{
					// update function
					(*booklife[selectedBook]).updateContact();
					once=false;
				}

				if(command == "add")
				{
					// add a contact function
					cin >> (*booklife[selectedBook]);
					once=false;
				}

				if(command == "delete")
				{
					//  delete a contact function
					(*booklife[selectedBook]).deleteContact();
					once=false;
				}

				if(command == "display")
				{
					// display a contact function
					cout<< endl<< "To display all of a contact's info please search for him. ";
					(*booklife[selectedBook]).startSearch(); // within the search it will display the contact
					once=false;
				}

				if(command == "exit")
				{
					//exit from the submenu
					cout << endl <<  " submenu exited ";
					menu = 0 ;
				}

			} //end submenu

			}
			else // if there are no contact books to select
			{
			cout << endl <<"You need to have a Contact Book first..  ";
			}
		} //end select and edit

		if(gCommand == "exit" || gCommand ==  "save" || gCommand ==  "exit and save")
		{
			// save

			if(saveBooksToFile() > 0)
			cout<< endl << "Saved";

			cout<< endl << "Goodbye ";
			//exit
			gmenu = 0 ;
			return 0;
		}

	} //end menu

	return 0;
}

//This searches for a contact book and returns true if it was able to do so
bool searchAndSelect()
{
	if(numbOfBooks >0 ) // there are contact books
	{
		if(selectedBook >= 0)
		{

			cout << "Currently "<< (*booklife[selectedBook]).getOwner() << "'s book is selected. "<< endl << "Would you like to select a different book?";
			string x= " ";
			getline(cin,x);
			while(x!= "yes" && x != "no")// makes sure the user answers one of those
			{
				cout << endl << "Sorry but I didn't understand, please try again ";
				getline(cin,x);
			}
			if(x=="no")
			{
				return true;// they don't want to select a different book and they have a selected book
			}
			if(x=="yes")
			{
				do
				{
					cout << endl <<"Please select a contact book to work with by typing the last-name space first-name of the owner ";
					string tName= " ";
					getline(cin, tName);
					int y= findbook(tName);
					selectedBook= y;

					if(selectedBook < 0)
						cout << endl <<"Sorry but that contact book cannot be found..";
				} while(selectedBook < 0);
				return true;
			}
		}
		//They need to select a contactBook, or want to
		while(selectedBook < 0)
		{
			cout << endl <<"Please select a contact book to work with by typing the last-name space first-name of the owner ";
			string tName= " ";
			getline(cin, tName);
			int y= findbook(tName);
			selectedBook= y;

			if(selectedBook < 0)
				cout << endl <<"Sorry but that contact book cannot be found..";
		}
		return true;
	}
	else // there are no contact books
	{
		cout << endl <<"I'm sorry but you don't seem to have any contact book ";
		return false; // no contact book was selected so it failed
	}
}

//Function that returns the index of the first instance of a contact book with an owner name that matches that of the argument accepted
int findbook(string tName)
{
	for(int i=0; i < numbOfBooks; i++)
	{
		if(tName== (*booklife[i]).getOwner() )
		{
			return i;
		}
	}
	return -1;
}


int saveBooksToFile() //this saves all the contactBooks to a file called contactbooks.txt
{
	ofstream myfile ("contactbooks.txt");
	string n = "";
	cout << "numbBooks: " << numbOfBooks << endl;
	if (myfile.is_open())
	{
		for(int i=0; i < numbOfBooks; i++) //loop through each book
		{
			/*n += "\n"; // << endl;
			//myfile <<
			n += (*booklife[i]).saver(n);
			*/
			myfile << (*booklife[i]);
		}

	//myfile << n;
	  myfile.close();
	  return 1;
	}
	else cout << "Unable to open file";
	return 0;
}

int loadData() //this loads data from the file, it analizes it line by line, it takes the first part of a line differently then the middle parts of a line,
{
	 ifstream myfile ("contactbooks.txt");
	 if (myfile.is_open())
		  {
	  string line; //stores a line of info
	  string info; //stores a piece of info, as determained by finding the things in between ' | '
	   //finds an instance of ' | '
	  int infoL; //the distance between the next ' | ' and found
	  //int addToBookN = 0; // keeps track of which contact book to add to.
	  int onOwnerInfo = 0; //keeps track if this is owner info, there are up to 2 pieces of info
	  int contactInfo =0; //keeps track of a contacts info, there are 11 pieces of info
	  bool switchy =false;

	  // /*strings to hold all info of contact to be initialized at once
	  string oname = "";
	  string oLname = "";
	  //all info for owner above
	  string hm= "";
	  string str= "";
	  string ap= "";
	  string ci= "";
	  string sta= "";
	  string zi= "";
	  string first= "";
	  string last= "";
	  // all info for Address place, above
	  string pNum = "";
	  string eplace= "";
	  string gName= "";
	  //all info for Contact toAdd above

	    while ( getline (myfile,line) ) //gets the entire line of info and starts to break it down
	    {
	    	//cout<< endl << "L: " << line << endl;

	    if(numbOfBooks < 5) //make sure we don't add more then 5 contact books
	    {
	    	//to read to the first ' | '
	    	int found = 0 ;
	    	found=line.find(" | ",found + 3);

    		if(switchy ==true) //this means during the last cycle we reached the end of a line, so this object is at the start of a line, and the contactInfo should account for that
	    	  {
	    		 contactInfo=0;
	    		 switchy =false;
	    	  }

	    	if(found!=std::string::npos) //if there is a ' | ' then
	    	{
	    		info= line.substr( 0,found);

	    		if(line != "" && onOwnerInfo < 1)// see if we already have all the info for the owner we expect, it is set to 1 because we expect only a first name
		    	  {
		    		  oname = info;
		    		  onOwnerInfo++; // tell the computer to expect the next piece of info, aka the last name.
		    	  }
	    		else if(contactInfo==0)
		    	  {
		    		  first= info;
		    		  contactInfo=1;
		    	  }
	    		if(line=="endbook | ")
	    		{
	  	    	  if(numbOfBooks < 5) //don't let too many books be added
	  	    	  {
	  	    		  numbOfBooks++;
	  	    		  onOwnerInfo=0;
	  	    	  }
	    		}
	    	}

	      while (found!=std::string::npos)
	      {
	    	  if(line.find(" | ",found + 3) == std::string::npos)
	    	  {
	    		  infoL = line.size() - found ;
	    		  info= line.substr(found+3,infoL);
	    	  }
	    	  else
	    	  {
	    	  infoL = line.find(" | ",found + 3 ) - found - 3 ;
	    	  info= line.substr(found + 3 ,infoL);
	    	 // cout << infoL << "   l";
	    	  }

	    	  //cout << info << '\n';
	    	  found=line.find(" | ",found + 3); //increase found for the next round

	    	  //addToBookN = 0;
	    	  // the info is now broken up
	    	  //Now based on where we should be regarding the info, we place it into the correct location
	    	  if(line != "" && onOwnerInfo == 1 )// see if we already have all the info for the owner we expect, it is set to 2 because we expect that many pieces of owner info, a first and a last name
	    	  { // the owner first name should have already been added before the while loop
	    		  oLname = info;
	    		  onOwnerInfo++; // If I wanted to add more info about the owner I would just not turn switchy on yet and create some more if statements to decide where to place that info. For example, the way I set up the owner in the contact book is by giving him an actual contact, I would continue to write down all his contact info, and then create a function called exchangeInfo which takes two contact books as arguments and then adds to each a contact based on the owner info of the other contactBook
	    		  //we should have all the info for the contact book owner so make him
	    		  booklife[numbOfBooks]= new ContactBook(oname, oLname); //since we now have our owner info we can initialize a contactbook with that info.
	    		  switchy =true; //since we have finished inputing owner info, set a signal that next round should start contact info.

	    	  }
	    	  else if(info!= "endbook")
	    	  {
	    	  if(contactInfo==0)
	    	  {
	    		  first= info;
	    	  }
	    	  else if(contactInfo==1)
	    	 	  {
	    		  last= info;
	    	 	  }
	    	  else if(contactInfo==2)
	    	 	  {
	    		  pNum= info;
	    	 	  }
	    	  else if(contactInfo==3)
	    	 	  {
	    		  eplace= info;
	    	 	  }
	    	  else if(contactInfo==4)
	    	 	  {
	    		  hm= info;
	    	 	  }
	    	  else if(contactInfo==5)
	    	 	  {
	    		  str= info;
	    	 	  }
	    	  else if(contactInfo==6)
	    	 	  {
	    		  ap= info;
	    	 	  }
	    	  else if(contactInfo==7)
	    	 	  {
	    		  ci= info;
	    	 	  }
	    	  else if(contactInfo==8)
	    	 	  {
	    		  sta = info;
	    	 	  }
	    	  else if(contactInfo==9)
	    	 	  {
	    		  zi= info;
	    	 	  }
	    	  else if(contactInfo==10)
	    	 	  {
	    		  gName= info;
	    		  //all info for Contact added
	    		  //since we now have all the info for a contact we create him
	    		  Address place= Address(hm,  str,  ap,  ci, sta,  zi);
	    		  Contact toAdd= Contact(first, last, place, pNum , eplace, gName);
	    		  (*booklife[numbOfBooks]).addem(toAdd);
	    		  //reset contactInfo==
	    		  switchy =true; // we have finished a contact therefore set this tracker to make the info of next round expect the starting info of a contact
	    	 	  }
	    	  	  contactInfo++;

	    		  } // end the check that makes sure we haven't ended the book
	    	  else //if(info== "endbook") // it must be endbook by default
	    	  	  {
	    		  	  if(numbOfBooks < 5) //don't let too many books be added
	    			  {
	    				  numbOfBooks++; // we finished a book so count that
	    				  onOwnerInfo=0;// expect the next piece of info to be about the owner
	    			  }

	    	  	  }
	      }
	    }
	    }
	    myfile.close();
	    return 1;
	  }

	  else
		  {
		  cout << "Unable to open file";
		  return 0;
		  }
}

