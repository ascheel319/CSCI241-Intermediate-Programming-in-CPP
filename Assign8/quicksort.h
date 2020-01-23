/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Andrew Scheel
   LOGON ID:   z1790270
   DUE DATE:   11/29/17

   FUNCTION:   This file quickly sorts the list
*********************************************************************/


#ifndef QUICKSORT_H
#define QUICKSORT_H


#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

//prototypes
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&));
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&));

//Name:		partition
//Use:		swaps stuff around
//Parameters:	a vector, a starting int, an ending int, a boolean
//Returns:	pivotIndex
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
        int pivotIndex, mid;
        T pivotValue;

        mid = (start + end) / 2;

        //Swap elements start and mid of the vector
        swap(set[start], set[mid]);

        pivotIndex = start;
        pivotValue = set[start];

        for (int scan = start + 1; scan <= end; scan++)
        {
                if (compare(set[scan], pivotValue))
                {
                        pivotIndex++;
        		//Swap elements pivotIndex and scan of the vector
                        swap(set[pivotIndex], set[scan]);
                }
        }

        //Swap elements start and pivotIndex of the vector
        swap(set[start], set[pivotIndex]);

        return pivotIndex;
}

//Name:		quickSort
//Use:		quickly sorts the list
//Parameters:	a vector, a starting int, an ending int, and a boolean
//Returns:	none
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
	int pivotPoint;

	if (start < end)
	{
		pivotPoint = partition(set, start, end, compare);// Get the pivot point
		quickSort(set, start, pivotPoint - 1, compare);// Sort first sublist
		quickSort(set, pivotPoint + 1, end, compare);// Sort second sublist
	}
}

//Name:		quickSort
//Use:		calls the other quicksort
//Parameters:	a vector boolean
//Returns:	none
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
        quickSort(set, 0, set.size()-1, compare);
}

#endif
