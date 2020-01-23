#ifndef PROVIDERDB_H
#define PROVIDERDB_H
#include "Provider.h"

   //*****************************************************************
   // FILE:      ProviderDB.h
   // AUTHOR:    Andrew Scheel
   // LOGON ID:  z1790270
   // DUE DATE:  10/10/17
   //
   // PURPOSE:   Declaration for the Provider class, which represents
   //            information about a health care provider.
   //*****************************************************************

   class ProviderDB
	{
      // Data members and method prototypes for the Provider class go here
	Provider providerObjects[41];
	int i = 40;
	//constructors
	public:
	ProviderDB();
	ProviderDB(const char*);

	//methods
	void print() const;
	void sortByProviderNumber();
	void sortBySpecialty();
	void sortByName();

	//assign 3
	void processTransactions(const char*);
	int searchForProviderNumber(const char[]);
};

#endif
