/*********************************************************************
   FILE:       mergesort.h
   PROGRAMMER: Andrew Scheel
   LOGON ID:   z1790270
   DUE DATE:   11/29/17

   FUNCTION:   This file has all the merge sort stuff
*********************************************************************/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//prototypes
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&));
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&));
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&));

//Name:		mergeSort
//Use:		calls the other mergeSort function
//Parameters:	a vector, a boolean
//Returns:	none
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
	mergeSort(set, 0, set.size()-1, compare);
}
//Name:		mergeSort
//Use:		divides the list into small versions of it and calls merge
//Parameters:	a vector, a low integer, a high integer, a boolean
//Returns:	none
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		// Divide and conquer
		mergeSort(set, low, mid, compare);
		mergeSort(set, mid+1, high, compare);

		// Combine
		merge(set, low, mid, high, compare);
	}
}

//Name:		merge
//Use:		sorting everything and putting it all together
//Parameters:	a vector, a low int, a high int, and a boolean
//Returns:	none
template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
	// Create temporary vector to hold merged subvectors
	vector<T> temp(high - low + 1);

	int i = low;      // Subscript for start of left sorted subvector
	int j = mid+1;    // Subscript for start of right sorted subvector
	int k = 0;        // Subscript for start of merged vector

	// While not at the end of either subvector
	while (i <= mid && j <= high)
	{
		if (compare(set[j], set[i]))
		{
//			Copy element j of set into element k of temp
			temp[k] = set[j];
//			Add one to j
			j = j + 1;
//			Add one to k
			k = k + 1;
		}
		else
		{
//			Copy element i of set into element k of temp
			temp[k] = set[i];
//			Add one to i
			i = i + 1;
//			Add one to k
			k = k + 1;
		}
	}

	// Copy over any remaining elements of left subvector
	while (i <= mid)
	{
//		Copy element i of set into element k of temp
		temp[k] = set[i];
//		Add one to i
		i = i + 1;
//		Add one to k
		k = k + 1;
	}

	// Copy over any remaining elements of right subvector
	while (j <= high)
	{
//		Copy element j of set into element k of temp
		temp[k] = set[j];
//		Add one to j
		j = j + 1;
//		Add one to k
		k = k + 1;
	}

	// Copy merged elements back into original vector
	for (i = 0, j = low; j <= high; i++, j++)
//		Copy element i of temp into element j of set
		set[j] = temp[i];
}


#endif
