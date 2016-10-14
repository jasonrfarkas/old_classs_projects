/*
 * ContactClassDefine.cpp
 *
 *  Created on: Mar 25, 2014
 *      Author: SruliF
 *    Owner Name: Jason Farkas
File Goal: to define what occurs in the contact class.
Variables: it holds name information( first and last), address info, contact info ( email and phone), and a group association ( for further recognition searching and categorization)
 Methods: includes accesssors and mutators for all variables, functions to determine if parts of a string are a character or a number, a function that uses that info to determine if an input is a valid phone number or email,
 also includes the ability for user to input or print all info and the ability to compare different contacts, with overloaded operators to make life better
 *
 */

//constructors

#include "ContactClassDec.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include "Address.h"

    Contact::Contact()
    {
    	fName= " ";
    	lName = " ";
    	address = Address();
    	phoneNum = "0000000000";
    	email = "none@none.com";
    	groupName = " ";
    }

     Contact::Contact(string &first, string &last, Address &place, string &pNum , string &eplace)
    {
    fName= first;
	lName = last;
	address = place;
	if (isThisvalidPhoneNumber(pNum))
		{
		phoneNum = pNum;
		}
	else
	{
		phoneNum = "0000000000";
	}
	if (isThisValidEmailAddress(eplace))
		{
			email = eplace;
		}
		else
		{
			email = "none@none.none";
		}
	groupName = " ";
    }
    Contact::Contact(string &first, string &last, Address &place, string &pNum , string &eplace, string &gName)
    {
    fName= first;
	lName = last;
	address = place;
	if (isThisvalidPhoneNumber(pNum))
			{
			phoneNum = pNum;
			}
		else
		{
			phoneNum = "0000000000";
		}
	if (isThisValidEmailAddress(eplace))
			{
				email = eplace;
			}
			else
			{
				email = "none@none.none";
			}
	groupName = gName;
    }
     Contact::Contact(string &first, string &last, /*string &place,*/ string &pNum , string &eplace, string &gName)
    {
    	fName= first;
    	lName = last;
    	address = Address();
    	if (isThisvalidPhoneNumber(pNum))
    		{
    			phoneNum = pNum;
    		}
    		else
    		{
    			phoneNum = "0000000000";
    		}
    	if (isThisValidEmailAddress(eplace))
    			{
    				email = eplace;
    			}
    			else
    			{
    				email = "none@none.none";
    			}
    	phoneNum = pNum;
    	groupName= gName;
    }
	Contact::Contact(string &pNum)
	{
	fName= " ";
	lName = " ";
	email = "none@none.com";
	groupName = " ";
	if (isThisvalidPhoneNumber(pNum))
		{
			phoneNum = pNum;
		}
		else
		{
			phoneNum = "0000000000";
		}
	}


// accessers
	string Contact::getFname() const
	{
		return(fName);
	}
	string Contact::getLname() const
	{
			return(lName);
	}
	string Contact::getAddress(string part) const
	{
		if(part=="home")
		{
		return address.getHome();
		}
		if(part=="street")
		{
		return address.getStreet();
		}
		if(part=="number")
		{
		return address.getApt();
		}
		if(part=="city")
		{
		return address.getCity();
		}
		if(part=="state")
		{
		return address.getState() ;
		}
		if(part=="zip")
		{
		return address.getZip();
		}
		if(part=="full")
		{
			string fullAdd = " ";
			fullAdd = address.getHome() + "\n" +  address.getStreet() +  "\n" + address.getApt() +  "\n" + address.getCity() +
					"\n" + address.getState() +  "\n" + address.getZip();
			return fullAdd;
		}
			return" ";
	}

	Address Contact::getFullAddress() const
	{
	return(address);
	}
	string Contact::getPhoneNum() const
	{
			return(phoneNum);
	}
	string Contact::getEmail() const
	{
			return(email);
	}
	string Contact::getGroup() const
	{
			return(groupName);
	}

//mods

	void Contact::modFname(string newF)
	{
fName= newF;
	}

	void Contact::modLname(string newL)
	{
lName= newL;
	}

	void Contact::modAddress()
	{
address.input();
	}

	void Contact::modPhoneNum(string newNum)
	{
while (!isThisvalidPhoneNumber(newNum))
	{
		cout<< endl <<"Please a valid Phone Number" ;
		cin >> newNum;
	}
phoneNum = newNum;

	}

	void Contact::modEmail(string newEmail)
	{

		while (!isThisValidEmailAddress(newEmail))
		{
		cout<< endl <<"Please a valid Email" ;
		cin >> newEmail;
		}

		email= newEmail;
	}


	  bool Contact::isCharacter(const char Character) const
	{


		return ( (Character >= 'a' && Character <= 'z') || (Character >= 'A' && Character <= 'Z'));
		//Checks if a Character is a Valid A-Z, a-z Character, based on the ascii value
	}
	bool Contact::isNumber(const char Character) const
	{

		return ( Character >= '0' && Character <= '9');
		//Checks if a Character is a Valid 0-9 Number, based on the ascii value
	}

	bool Contact::isValidEmailAddress() const
	{
		string yolo = getEmail();
		const char *EmailAddress = yolo.c_str();
		if(!EmailAddress) // If cannot read the Email Address...
		return 0;


		int section =0;
		bool itsallgood = true;
		int Length = strlen(EmailAddress); // Length = StringLength of EmailAddress

		for(int i = 0; i < Length; i++)
		{

			if (EmailAddress[i] == '@')
			{
				if (section > 1)
				{
					itsallgood=false;
					cout << endl << "Emails must have only one '@' symbol, and only after the first character, please retry";
					return(itsallgood);
				}
				else
				{
					section = 2;
				}
			}
			else if(EmailAddress[i] == '.')
			{
				if(section != 3) // currently only allows 1 ' . '  // it should really check to make sure there is at least one dot after the @ symbol
				{
					itsallgood=false;
					cout << endl << "Your '.' is misplaced, only one is allowed, please retry";
					return(itsallgood);
				}
				else
				{
					section=4;
				}
			}
			else if(isCharacter(EmailAddress[i]))
			{
				if (section != 1 && section != 3 &&  section != 5)
					{
					section+=1; // section =0, now =1, if =2 now =3, if = 4 now = 5
					}
			}
			else if(isNumber(EmailAddress[i]))
			{
				if(section==0)
				{
					itsallgood=false;
					cout << "Email's don't begin with numbers, retry";
					return(itsallgood);
				 //if = 0 error, otherwise if =2 now =3,
				}
			}

		}
		if(section != 5)
		{
		itsallgood=false;
		}
		return(itsallgood);
	}

bool Contact::isThisValidEmailAddress(string yolo) const
	{

		const char *EmailAddress = yolo.c_str();
		if(!EmailAddress) // If cannot read the Email Address...
		return 0;

		int section =0;
		bool itsallgood = true;
		int Length = strlen(EmailAddress); // Length = StringLength of EmailAddress

		for(int i = 0; i < Length; i++)
		{
			if (EmailAddress[i] == '@')
			{
				if (section > 1)
				{
					itsallgood=false;
					cout << endl << "Emails must have only one '@' symbol, and only after the first character, please retry";
					return(itsallgood);
				}
				else
				{
					section = 2;
				}
			}
			else if(EmailAddress[i] == '.')
			{
				if(section != 3)
				{
					itsallgood=false;
					cout << endl << "Your '.' is misplaced, only one is allowed, please retry";
					return(itsallgood);
				}
				else
				{
					section=4;
				}
			}
			else if(isCharacter(EmailAddress[i]))
			{
				if (section != 1 && section != 3 &&  section != 5)
					{
					section+=1; // section =0, now =1, if =2 now =3, if = 4 now = 5
					}
			}
			else if(isNumber(EmailAddress[i]))
			{
				if(section==0)
				{
					itsallgood=false;
					cout << "Email's don't begin with numbers, retry";
					return(itsallgood);
				 //if = 0 error, otherwise if =2 now =3,
				}
			}

		}
		if(section != 5)
		{
		itsallgood=false;
		}

		return(itsallgood);
	}

	void Contact::modGroup(string newGroup)
	{
groupName = newGroup;
	}

			bool  Contact::isThisvalidPhoneNumber(string theNumb) const  //need to declare still
	{

		const char *pNumb = theNumb.c_str();
		if(!pNumb) // If cannot read the phone number...
		return 0;

		for (int i=0; i < 10; i++)
		{
			if(!isNumber(pNumb[i]))
			{

				cout << endl <<  "The phone number is not valid, please retry";
				return 0;
			}
		}

		if(pNumb[10])
		{

		cout << endl <<  "The phone number is not valid, please retry";
		return 0;
		}

		else
		{
		return 1;
		}

	}


	bool  Contact::isvalidPhoneNumber() const // version for a string type
	{

		const char *pNumb = phoneNum.c_str();
		if(!pNumb) // If cannot read the phone number...
		return 0;

		for (int i=0; i < 10; i++)
		{
		if(!isNumber(pNumb[i]))
		{
		cout << endl <<  "The phone number is not valid, please retry";
		return 0;
		}
		}

		if(pNumb[10])
		{
		cout << endl <<  "The phone number is not valid, please retry";
		return 0;
		}

		else
		{
		return 1;
		}
	}



	 ostream& operator << (ostream& out, const Contact& guy)
	 {
		 string oStream= "os";
		 string fStream= "St14basic_ofstreamIcSt11char_traitsIcEE";
		 if(typeid(out).name() == oStream)
		 {
		 out << endl << guy.fName << " " << guy.lName << endl << guy.address << guy.phoneNum << endl << guy.email << endl << guy.groupName ;
		 }
		 else if(typeid(out).name() == fStream)
		 {
		out << endl << guy.fName << " | " << guy.lName << " | " << guy.phoneNum << " | " << guy.email << " | " << guy.address << " | "  << guy.groupName ;
		 }
		 //cout << typeid(out).name();
		 else
		 {
		out << endl << guy.fName << " " << guy.lName << endl << guy.address << guy.phoneNum << endl << guy.email << endl << guy.groupName ;
		 }
		 return(out);
	 }

	ofstream& operator << (ofstream& out, const Contact& guy)
	 {
		// this returns the contact in the form of //first-name|last-name|phone|email|home|street|apt|city|state|zip
		out << endl << guy.fName << " | " << guy.lName << " | " << guy.phoneNum << " | " << guy.email << " | " << guy.address << " | "  << guy.groupName ;
		return(out);
	 }

	string& Contact::saver(string& out)
	{

		// this returns the contact in the form of //first-name|last-name|phone|email|home|street|apt|city|state|zip
		out += "\n" +  fName + " | " +  lName + " | " + phoneNum +  " | " +  email + " | " ;
		out +=  address.saver(out);
		out +=  " | "  +  groupName ;


		return(out);
	}


	 istream& operator >> (istream& in, Contact& guy)
	 {
		 	 	string x = "";

		 		cout<< endl << "Please enter your contact's first name" ;
		 		in >> x;
		 		guy.modFname(x);


		 		cout<<endl <<"Please enter your contact's last name" ;
		 		in >> x;
		 		guy.modLname(x);

		 		in >> guy.address;

		 		cout<< endl <<"Please enter your contact's Phone Number" ;
		 		in >> x;

		 		guy.modPhoneNum(x);

		 		while (!guy.isvalidPhoneNumber())
		 		{
		 		cout<< endl <<"Please enter your contact's Phone Number " ;
		 		in >> x;
		 		guy.modPhoneNum(x);
		 		}

		 		cout<< endl <<"Please enter your contact's email " ;
		 		in >> x;
		 		guy.modEmail(x);

		 		while(!guy.isValidEmailAddress())
		 		{
		 		cout<< endl <<"Please enter your contact's email " ;
		 		in >> x;
		 		guy.modEmail(x);
		 		}

		 		cout<< endl <<"Please enter your contact's group association " ;
		 		in >> x;
		 		guy.modGroup(x);

		 		return(in);

	 }

	 bool Contact::operator > (const Contact& guy) // should return + int if caller is later in alphabet
	 {
		//call compare and if < 0 return 1 else, return 0,
		if ( compare(guy) < 0)// compare guys says returns + if b is larger, and negative if a is larger
			return true;
		else
			return false;

		// return t;
	 }

	 bool Contact::operator >= (const Contact& guy)
	{
		 if ( compare(guy) <= 0 )// compare guys says returns + if b is larger, and negative if a is larger
		 			return true;
		 		else
		 			return false;
	}

	 bool Contact::operator <  (const Contact& guy)
 	{
 		if ( compare(guy) > 0 )// compare guys says returns + if b is larger, and negative if a is larger
 				 			return true;
 				 		else
 				 			return false;
 	}

	 bool Contact::operator <=  (const Contact& guy)
	{
		if ( compare(guy) >= 0 )// compare guys says returns + if b is larger, and negative if a is larger
	 			return true;
	 		else
	 			return false;
	}

	 bool Contact::operator == (const Contact& guy)
	{
	 	if ( compare(guy) == 0 )// compare guys says returns + if b is larger, and negative if a is larger
	 		return true;
 		else
			return false;
		}

	 bool Contact::operator != (const Contact& guy)
		{
	 	if ( compare(guy) != 0 )// compare guys says returns + if b is larger, and negative if a is larger
		 	return true;
	 	else
	 		return false;
	}

	 int Contact::compare(const Contact& guy) // should return + int if (in class) is closer to a, via last name first.
	 {

			int t=0;
			bool sameLname= false;
			string fnamea = fName;
			int gafl = fnamea.length();
			string fnameb = guy.fName;
			int gbfl = fnameb.length();

			string lnamea = lName;
			int gall = lnamea.length();
			string lnameb = guy.lName;
			int gbll = lnameb.length();

			for(int i=0; (i < gall && i < gbll && t==0); i++) // will run until they are not comparable or it has been determained which has a greater last name
			{
				int diff = lnameb[i] - lnamea[i]; // if b is later in abc then return + int, calling this a letter weight comparison, if b is heaver return +
				t+=diff;
			}

			if(t==0)
			{
				int ldiff = gbll - gall; // if last name of b is longer return + int
				t += ldiff;

				if(t==0) // no diff in LName letter weight or size
				{
					sameLname=true;
					for(int i=0; (i < gafl && i < gbfl && t==0); i++)
					{
						int diff = fnameb[i]- fnamea[i]; // if b is heavier return + int
						t+=diff;
					}

					if(t==0)// weights are the same for first name and last names are the same,
					{
							int ldiff = gbfl - gafl; // if b's first name is longer then return +
							t += ldiff;
					}
				}
			}
			 return t;
	 }

	 //inputs all the info of a contact via user input
	void Contact::inputAllInfo()
	{
		string x = "";
		string w = "";

		cout<< endl << "Please enter your contact's first name" ;
		cin >> x;
		modFname(x);


		cout<<endl <<"Please enter your contact's last name" ;
		cin >> x;
		modLname(x);

		cin >> address;

		cout<< endl <<"Please enter your contact's Phone Number" ;
		cin >> x;

		modPhoneNum(x);

		while (!isvalidPhoneNumber())
		{
		cout<< endl <<"Please enter your contact's Phone Number " ;
		cin >> x;
		modPhoneNum(x);
		}

		cout<< endl <<"Please enter your contact's email " ;
		cin >> x;
		modEmail(x);

		while(!isValidEmailAddress())
		{
		cout<< endl <<"Please enter your contact's email " ;
		cin >> x;
		modEmail(x);
		}

		cout<< endl <<"Please enter your contact's group association " ;
		cin >> x;
		modGroup(x);



	}

	//prints out all the info of a contact,
	void Contact::printAllInfo()
	{
		cout << endl << fName << " " << lName << endl;
		address.output();
		cout << endl << phoneNum << endl << email << endl << groupName ;

	}



