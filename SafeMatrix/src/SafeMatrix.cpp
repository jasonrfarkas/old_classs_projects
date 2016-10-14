/*
 * SafeMatrix.cpp
 *
 *  Created on: May 5, 2014
 *      Author: SruliF
 *
 *      This is for a class SafeMatrix who's goal is to create a safeArray of SafeArrays of whatever type the user desires,
 *      this creates a two dimensional safe array, that checks the bounds when it's elements are accessed and returns an error message if it is out of bounds,
 */

#include "SafeMatrix.h"
#include <iostream>


template <class T>
SafeMatrix<T>::SafeMatrix() {
    row=0; // keeps track of [row] in [row][column]
    twoD = new SafeArray< SafeArray<T> >(row);
}

template <class T>
SafeMatrix<T>::SafeMatrix(int ro, int co)
{
	 row=ro; // keeps track of [row] in [row][column]
	 twoD = SafeArray< SafeArray<T> >(ro);

for(int i=0; i < row; i++) // for every element in the row initialize it into its own safe array so it is a column
{
	twoD[i]=SafeArray<T>(co);
}

}

template <class T>
SafeArray<T>& SafeMatrix<T>::operator [] (int index)
{
   if (index < 0 || index >= row)
   {
	  cout << "Index: " << index << " of rows is out of bounds." << endl;
      exit(1);
   }
   return twoD[index];
}

template <class T>
int SafeMatrix<T>::length() const
{
	return row;
}
