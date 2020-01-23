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
