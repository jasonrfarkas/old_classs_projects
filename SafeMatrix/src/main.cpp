//============================================================================
// Name        : SafeMatrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//this is a driver for the safeMAtrix class that tests an int and a char version to make sure the template works properly


#include <iostream>
#include "SafeMatrix.h"
#include "SafeMatrix.cpp"


int main() {
//create two different SafeMatrix's, one for ints one for chars
	SafeMatrix<int> tester = SafeMatrix<int>(18,12);
	SafeMatrix<char> tester2 = SafeMatrix<char>(10,26);
//test the length that returns the amount of rows
cout << tester.length() <<endl;
//fill in the char safeMAtrix
	for(int i=0;i<10;i++)
		{

			for(int j=0;j<26;j++)
			{
				tester2[i][j] = 'a'+j ;
			}
			//cout << endl << "colms: " << tester[i].length();
		}

//fill in the int safeMatrix
	for(int i=0;i<18;i++)
	{

		for(int j=0;j<12;j++)
		{
			tester[i][j] = i+j;
		}
		//cout << endl << "colms: " << tester[i].length();
	}

//print out the int safeMatrix
cout<< endl << "for the ints!!!!  "<< endl;
	for(int i=0;i<18;i++)
	{
		for(int j=0;j<12;j++)
		{
			cout << tester[i][j] << ", ";
		}
		cout<< endl << "next:" << endl;
	}
//print out the char safeMatrix
cout<<endl <<endl << "For the Letters!!!!  " << endl;
for(int i=0;i<10;i++)
{
	for(int j=0;j<26;j++)
	{
		cout << tester2[i][j] << ", ";
	}
	cout<< endl << "next:" << endl;
}

	return 0;
}
