/***********************************************************
CSCI 241 - Assignment  - Fall 2017

Progammer: Andrew Scheel
Z-ID: z1790270
Section: 2
TA: Mohammed Abdul Hafeez Khan
Date Due: 10/10/17

Purpose: This assignment introduces searching using the binary
	search algorithm.

************************************************************/

#include "Provider.h"
#include "ProviderDB.h"

int main()
{
	ProviderDB thing = ProviderDB("providerdb");

	thing.processTransactions("transactions.txt");

return 0;
}
