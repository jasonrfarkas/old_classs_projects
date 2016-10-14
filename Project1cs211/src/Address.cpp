/*
 * Address.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: SruliF
 */
// Address.cpp

/**
 * Defenition of class Address. It is used to store and retrieve
 * information on Address such as home number, street, apt#, city,
 * state, and zip.
 *
 * Author: Yosef Alayev

 */


#include "Address.h"
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

Address::Address() : home(""),
                     street(""),
                     apt("none"),
                     city(""),
                     state(""),
                     zip("")
{
   // empty
}

Address::Address(string hm, string str, string ap, string ci, string sta, string zi): home(hm),
        street(str),
        apt(ap),
        city(ci),
        state(sta),
        zip(zi)
{

}

string Address::getHome() const
{
   return home;
}

string Address::getStreet() const
{
   return street;
}

string Address::getApt() const
{
   return apt;
}

string Address::getCity() const
{
   return city;
}

string Address::getState() const
{
   return state;
}

string Address::getZip() const
{
   return zip;
}

void Address::output() const
{
   cout << home << " " << street;
   if (apt != "none" && apt != "-none-")
      cout << ", Apt# " << apt;
   cout << endl;
   cout << city << ", " << state << " " << zip;
}

//This is an overload of the << operator for ostream class, it also performs a check to see if it is of subtype fstream class, depending on if it is, it will return the infomation in a different format
ostream& operator << (ostream& out, const Address& place)
	 {
	 string oStream= "os";
	 string fStream= "St14basic_ofstreamIcSt11char_traitsIcEE";
	 if(typeid(out).name() == oStream)
	 {
		cout << place.home << " " << place.street;
	   if (place.apt != "none" && place.apt != "-none-")
	      cout << ", Apt# " << place.apt;
		 out << endl << place.city << ", " << place.state << " " << place.zip << endl;
	 }
	 else if(typeid(out).name() == fStream)
	 {
		 out << place.home << " | "  << place.street;
	   if (place.apt != "none" && place.apt != "-none-")
	      out << " | "  << place.apt;
	   else
		   out << " | -none-" ;
		 out << " | " << place.city << " | "  << place.state << " | "  << place.zip;
//home|street|apt|city|state|zip
	 }
	 else
	 {
		cout << place.home << " " << place.street;
	 if (place.apt != "none" && place.apt != "-none-")
		cout << ", Apt# " << place.apt;
		 out << endl << place.city << ", " << place.state << " " << place.zip;
	 }
		 return(out);
	 }

// this is an overload of the fsteam class, but because we already overloaded the ostream it is basically irrelevant, unless
ofstream& operator << (ofstream& out, Address& place) // this returns the Address in the form of // home|street|apt|city|state|zip
	 {
		out << place.home << " | "  << place.street;
	   if (place.apt != "none")
	      out << " | "  << place.apt;
	   else
		   out << " | none" ;
		 out << " | " << place.city << " | "  << place.state << " | "  << place.zip;
//home|street|apt|city|state|zip
		 return(out);
	 }


string& Address::saver(string& out)
{

	out = out + home + " | " +  street;
   if (apt != "none")
      out +=  " | "  +  apt;
   else
	   out +=  " | -none-" ;
	 out = out +  " | " +  city + " | "  +  state +  " | "  +  zip;
//home|street|apt|city|state|zip

	 return(out);
}

 istream& operator >> (istream& in, Address& place)
{
	   char choice;
	   cout << "Apartment or House (a/h):> ";
	   in >> choice;
	   cout << endl;

	   in.ignore(10, '\n');
	   cout << "Enter home number (EX: 141-92)___: ";
	   getline(in, place.home);
	   cout << "Enter street number (EX: 70th RD): ";
	   getline(in, place.street);

	   if (choice == 'a')
	   {
	      cout << "Enter Apartment Number: (EX: 1A)_: ";
	      getline(in, place.apt);
	   }
	   else
		   place.apt = "none";

	   cout << "Enter city (Ex: Flushing)________: ";
	   getline(in, place.city);

	   cout << "Enter state (EX: NY)_____________: ";
	   getline(in, place.state);

	   cout << "Enter zip code (EX: 11367)_______: ";
	   getline(in, place.zip);

	   return(in);
}
void Address::input()
{
   char choice;
   cout << "Apartment or House (a/h):> ";
   cin >> choice;
   cout << endl;

   cin.ignore(10, '\n');
   cout << "Enter home number (EX: 141-92)___: ";
   getline(cin, home);
   cout << "Enter street number (EX: 70th RD): ";
   getline(cin, street);

   if (choice == 'a')
   {
      cout << "Enter Apartment Number: (EX: 1A)_: ";
      getline(cin, apt);
   }
   else
      apt = "none";

   cout << "Enter city (Ex: Flushing)________: ";
   getline(cin, city);

   cout << "Enter state (EX: NY)_____________: ";
   getline(cin, state);

   cout << "Enter zip code (EX: 11367)_______: ";
   getline(cin, zip);
}



