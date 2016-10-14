/*
 * SafeMatrix.h
 *
 *  Created on: May 5, 2014
 *      Author: SruliF
 *
 *      This is for a class SafeMatrix who's goal is to create a safeArray of SafeArrays of whatever type the user desires,
 *      this creates a two dimensional safe array, that checks the bounds when it's elements are accessed and returns an error message if it is out of bounds,
  it contains an int to keep track of the rows, and a safeArray of SafeArrays, that itself tracks the cols
 */


#ifndef SAFEMATRIX_H_
#define SAFEMATRIX_H_

#include "SafeArray.h"
#include "SafeArray.cpp"

template <class T>
class SafeMatrix{

private:
	SafeArray<SafeArray<T> > twoD; // This means we have a SafeArray of Safe Arrays, aka an array of arrays, or a 2 dimentional array
	int row; // keeps track of [row] in [row][column]
    //int column; // keeps track of [column] in [row][column] // This is not needed as the safe array keeps tracks of columns for you


public:
	SafeMatrix(); //default constructor
	SafeMatrix(int ro, int co);//constructor that takes a value for the amount of rows and the amount of cols
	//Big three are not needed as the SafeMatrix class in on the stack, and although it contains a Safe Array which points to Safe Arrays on the heap, Those safe arrays clean their contents up, and twoD the safe array that contains them cleans them up, twoD does not require a manual clean up because it is on the stack.

    int length() const; //returns the amount of rows, aka row
    SafeArray<T>& operator [] (int index); //returns the contents of the matrix, aka, the SafeArray at row [index], the contents of that safeArray can be accessed via a second [] as defined int the safeArray class
};

#endif /* SAFEMATRIX_H_ */
