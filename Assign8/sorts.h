#ifndef SORTS_H
#define SORTS_H

//*****************************************************************
// FILE:      sorts.h
// AUTHOR:    Andrew Scheel
// LOGON ID:  z1790270
// DUE DATE:  11/29/17
//
// PURPOSE:   Declaration for the sorts functions
//*****************************************************************

#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//prototypes
//template <class T>
//void buildList(vector<T>& set, const char* fileName);
//template <class T>
//void printList(const vector<T>& set, int itemWidth, int numPerLine);
//template <class T>
//void printList(const vector<T>& set, int itemWidth, int numPerLine);
//template <class T>
//bool lessThan(const T& item1, const T& item2);
//template <class T>
//bool greaterThan(const T& item1, const T& item2);


//Name:		buildList
//Use:		puts the list together
//Parameters:	a vector and a file name
//Returns:	none
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
	T item;
	ifstream inFile(fileName);

	if(inFile.fail())
	{
		cout << "Could not open file " << fileName;
		exit(-1);
	}

	inFile >> item;

	while(!(inFile.eof()))//test for end of file
	{
		//put the item into the vector
		set.push_back(item);
		inFile >> item;
	}

	inFile.close();
}

//Name:		printList
//Use:		printing the list that is made by buildList
//Parameters:	a vector, an int of width and an int of how many per line
//Returns:	none
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{

	for(int i = 0; i < (int)set.size(); i++)
	{
		cout << setw(itemWidth) << set[i] << ' ';

		if((i + 1) % numPerLine == 0)
			cout << endl;
	}
}

//Name:		lessThan
//Use:		tells you if one is less than the other
//Parameters:	2 items
//Returns:	true if item1 is less than item2 and false if not
template <class T>
bool lessThan(const T& item1, const T& item2)
{
	return item1 < item2;
}

//Name:		greaterThan
//Use:		tells you if one is greater than the other
//Parameters:	2 items to be compared
//Returns:	true if item1 is more than item2 and false if not
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
	return item1 > item2;
}

#endif
