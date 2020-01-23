#include "ProviderDB.h"
#include "Provider.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

ProviderDB::ProviderDB()
{

}

ProviderDB::ProviderDB(const char* file)
{
	ifstream inFile;

	inFile.open(file);
	if(!inFile)
	{
		cerr << "Error - Unable to open input file\n";
		exit(1);
	}
	inFile.read((char*) this, sizeof(ProviderDB));

	inFile.close();
}

/***************************************************************
        Function: print

        Use: prints the list in its current form

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void ProviderDB::print() const
{
	cout << "Health Care Provider Listing";
	cout << endl << endl;

	for(int i = 0; i < 41; i++)
	{
	providerObjects[i].print();
	}
}

/***************************************************************
        Function: sortByProviderNumber

        Use: sorts the list by the provider numbers

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void ProviderDB::sortByProviderNumber()
{
	int i, j;
	Provider bucket;

	for (i = 1; i < 41; i++)
	{
	bucket = providerObjects[i];

		for (j = i; (j > 0) && (strcmp(providerObjects[j-1].getProviderNumber(), bucket.getProviderNumber()) > 0); j--)
		{
		providerObjects[j] = providerObjects[j-1];
		}

	providerObjects[j] = bucket;
      	}
}

/***************************************************************
        Function: sortBySpecialty

        Use: sorts the list by its specialty

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/

void ProviderDB::sortBySpecialty()
{
	int i, j;
	Provider bucket;

	for (i = 1; i < 41; i++)
	{
	bucket = providerObjects[i];

		for (j = i; (j > 0) && (strcmp(providerObjects[j-1].getSpecialty(), bucket.getSpecialty()) > 0); j--)
		{
		providerObjects[j] = providerObjects[j-1];
		}

	providerObjects[j] = bucket;
	}

}

/***************************************************************
        Function: sortByName

        Use: sorts the list by the name of the person

        Arguments: none

        Returns: none

        Note:
        ***************************************************************/
void ProviderDB::sortByName()
{
	int i, j;
	Provider bucket;

	for (i = 1; i < 41; i++)
	{
	bucket = providerObjects[i];

		for (j = i; (j > 0) && (strcmp(providerObjects[j-1].getName(), bucket.getName()) > 0); j--)
		{
		providerObjects[j] = providerObjects[j-1];
		}

	providerObjects[j] = bucket;
	}

}

/***************************************************************
        Function: processTransactions

        Use: process the transactions.txt file and the providerdb file

        Arguments: pointer to a constant character

        Returns: none

        Note:
        ***************************************************************/

void ProviderDB::processTransactions(const char* transaction)
{
	ifstream tranFile;

        tranFile.open(transaction);
        if(!tranFile)
        {
                cerr << "Error - Unable to open input file\n";
                exit(1);
        }

	string tranType;
	tranFile >> tranType;

	while(tranFile)
	{
		if(tranType == "all")
		{
			sortByName();
			print();
		}
		else if(tranType == "number")
		{
			string find;
			tranFile >> find;//read the provider number as a string of some kind
			sortByProviderNumber();
			int check = searchForProviderNumber(find.c_str());//not sure if this will work
			if(check > 0)
			{
			providerObjects[check].print();
			}
			else
			{
			cout << "That number is not a valid provider number." << endl << endl;
			}
		}
		else//specialty
		{
			tranFile >> ws;
			string thingy;
			getline(tranFile,thingy);
			sortBySpecialty();
			for(int i = 0; i<41; i++)
			{
				if(thingy == providerObjects[i].getSpecialty())//compare the current special and the one being searched for
				{
				providerObjects[i].print();//print the provider object that matches that specialty
				}
			}
		}
	tranFile>>tranType;
	}

}

/***************************************************************
        Function: searchForProviderNumber

        Use: searches for a provider number

        Arguments: a character array containing the provider number of
		   the Provider to search for

        Returns: the integer of where the provider number is

        Note:
        ***************************************************************/

int ProviderDB::searchForProviderNumber(const char number[])
{
	int low = 0;
	int high = 40;
	int mid;

	while (low <= high)
	{
	mid = (low + high) / 2;

	if (number == providerObjects[mid].getProviderNumber())
		return mid;

	if (number < providerObjects[mid].getProviderNumber())
		high = mid - 1;
	else
		low = mid + 1;
	}

	return -1;
}
