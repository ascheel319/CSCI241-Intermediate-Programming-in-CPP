/***********************************************************
CSCI 241 - Assignment  - Fall 2017

Progammer: Andrew Scheel
Z-ID: z1790270
Section: 2
TA: Mohammed Abdul Hafeez Khan
Date Due: 9/27/17

Purpose: This assignment reviews object-oriented programming
	concepts such as classes, methods, constructors, accessor
	methods, and access modifiers. It makes use of an array of
	objects as a class data member, and introduces the concept
	of object serialization or "binary I/O".

************************************************************/

#include "Provider.h"
#include "ProviderDB.h"

int main()
{
	ProviderDB thing = ProviderDB("providerdb");

	thing.print();			//prints the normal list

	thing.sortByProviderNumber();
	thing.print();			//prints the sorted by provider number list

	thing.sortBySpecialty();
	thing.print();			//prints the sorted by specialty list

	thing.sortByName();
	thing.print();			//prints the sorted by name list

return 0;
}
