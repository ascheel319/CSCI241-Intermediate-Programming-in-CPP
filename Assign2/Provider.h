#ifndef PROVIDER_H
   #define PROVIDER_H

   //*****************************************************************
   // FILE:      Provider.h
   // AUTHOR:    Andrew Scheel
   // LOGON ID:  z1790270
   // DUE DATE:  9/26/17
   //
   // PURPOSE:   Declaration for the Provider class, which represents
   //            information about a health care provider.
   //*****************************************************************

   class Provider
      {
      // Data members and method prototypes for the Provider class go here
	char provider_num[7];	//the provider's name
	char specialty[41];	//type of doctor they are
	char name[41];		//the name of the person
	char first_address[41]; //first part of their address
	char second_address[31];//second part of their address
	char city[21];		//city where they live
	char state[3];		//the state where they live
	char zip_code[6];	//the zip code for their home
	char phone_number[15];	//their phone number
public: Provider();
	//Accessor
	void print() const;
	//mutator
	void set_provider_num(const char*);
	void set_specialty(const char*);
	void set_name(const char*);
	void set_first_address(const char*);
	void set_second_address(const char*);
	void set_city(const char*);
	void set_state(const char*);
	void set_zip_code(const char*);
	void set_phone_number(const char*);

	const char* getProviderNumber();
	const char* getSpecialty();
	const char* getName();
	};

   #endif
