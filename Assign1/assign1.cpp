/***********************************************************
CSCI 241 - Assignment 1 - Fall 2017

Progammer: Andrew Scheel
Z-ID: z1790270
Section: 2
TA: Mohammed Abdul Hafeez Khan
Date Due: September 14, 2017

Purpose: This assignment is an exercise in writing, compiling, 
		and executing a C++ program on the departmental UNIX system. 
		It also covers the basics of object-oriented programming and 
		the manipulation of C and C++ strings.
************************************************************/ 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

class Provider
{
	private:
		char provider_num[7];		//the provider's name
		char specialty[41];			//type of doctor they are
		char name[41];				//the name of the person
		char first_address[41]; 	//first part of their address
		char second_address[31];	//second part of their address
		char city[21];			//city where they live
		char state[3];			//the state where they live
		char zip_code[6];		//the zip code for their home
		char phone_number[15];		//their phone number
			
	public:
		//Constructors
		Provider();
		Provider(const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*);

		//Accessor methods
		void print();
		//mutator methods
		void set_provider_num(const char*);
		void set_specialty(const char*);
		void set_name(const char*);
		void set_first_address(const char*);
		void set_second_address(const char*);
		void set_city(const char*);
		void set_state(const char*);
		void set_zip_code(const char*);
		void set_phone_number(const char*);
};

//function prototypes
int buildProviderArray(Provider []);
void printProviderArray(Provider[], int);

int main()
{
	Provider providerArray[35];
	int count;

	count = buildProviderArray(providerArray);

	printProviderArray(providerArray, count);

	return 0;
}

/***************************************************************
	Function: buildProviderArray

	Use: to fill an array with the provider information

	Arguments: the array that needs to be built

	Returns: the size of the array

	Note:
	***************************************************************/

int buildProviderArray(Provider providerArray[])
{
	ifstream inFile;
	string firstName, lastName, name, mName, provider_num, specialty, title, firstAdd, secondAdd, city, state, zip, phone;
	int count = 0;

	//open file and test for failure
	inFile.open("providers.csv");
	if(!inFile)
	{
		cerr << "Error - Unable to open input file\n";
		exit(1);
	}

	getline(inFile, provider_num, ',');
	while (inFile)
	{
		getline(inFile, specialty, ',');
		getline(inFile, lastName, ',');
		getline(inFile, firstName, ',');
		getline(inFile, mName, ',');
		getline(inFile, title, ',');
		getline(inFile, firstAdd, ',');
		getline(inFile, secondAdd, ',');
		getline(inFile, city, ',');
		getline(inFile, state, ',');
		getline(inFile, zip, ',');
		getline(inFile, phone);

		name = lastName + ", " + firstName + " " + mName + ", " + title;

		providerArray[count].set_provider_num(provider_num.c_str());
		providerArray[count].set_name(name.c_str());
		providerArray[count].set_specialty(specialty.c_str());
		providerArray[count].set_first_address(firstAdd.c_str());
		providerArray[count].set_second_address(secondAdd.c_str());
		providerArray[count].set_city(city.c_str());
		providerArray[count].set_state(state.c_str());
		providerArray[count].set_zip_code(zip.c_str());
		providerArray[count].set_phone_number(phone.c_str());

		count++;

		getline(inFile, provider_num, ',');
	}
	inFile.close();

	return count;
}

/***************************************************************
	Function: printProviderArray

	Use: prints out the array that is passed in

	Arguments: an array to be printed and the size of the array

	Returns: none

	Note:
	***************************************************************/

void printProviderArray(Provider providerArray[], int size)
{
	cout << fixed << setprecision(2);

	for(int i = 0; i < size; i++)
	{
		providerArray[i].print();
		cout << endl << endl;
	}
}

//Provider constructors
//default
Provider::Provider()
{
	set_provider_num("");
	set_specialty("");
	set_name("");
	set_first_address("");
	set_second_address("");
	set_city("");
	set_state("");
	set_zip_code("");
	set_phone_number("");
}

//alternate
Provider::Provider(const char* new_provider, const char* new_special, const char* new_name, const char* new_first, const char* new_second, const char* new_city, const char* new_state, const char* new_zip, const char* new_phone)
{
	set_provider_num(new_provider);
	set_specialty(new_special);
	set_name(new_name);
	set_first_address(new_first);
	set_second_address(new_second);
	set_city(new_city);
	set_state(new_state);
	set_zip_code(new_zip);
	set_phone_number(new_phone);
}

//Provider mutator methods

/***************************************************************
	Function: set_provider_num

	Use: sets the new provider number

	Arguments: the new provider number

	Returns: none

	Note:
	***************************************************************/
void Provider::set_provider_num(const char* new_num)
{
	strcpy(provider_num, new_num);
}

/***************************************************************
	Function: set_specialty

	Use: changes the specialty of the doctor to the new one

	Arguments: the new specialty

	Returns: none

	Note:
	***************************************************************/
void Provider::set_specialty(const char* new_special)
{
	strcpy(specialty, new_special);
}

/***************************************************************
	Function: set_name

	Use: sets the name of the person to the new name

	Arguments: the new name

	Returns: none

	Note:
	***************************************************************/
void Provider::set_name(const char* new_name)
{
	strcpy(name, new_name);
}

/***************************************************************
	Function: set_first_address

	Use: sets the first part of the address to the new one

	Arguments: the new first part of the address

	Returns: none

	Note:
	***************************************************************/
void Provider::set_first_address(const char* new_first)
{
	strcpy(first_address, new_first);
}

/***************************************************************
	Function: set_second_address

	Use: sets the second part of the address to the new one

	Arguments: the new second part of the address

	Returns: none

	Note:
	***************************************************************/
void Provider::set_second_address(const char* new_second)
{
	strcpy(second_address, new_second);
}

/***************************************************************
	Function: set_city

	Use: changes the city to the new city name

	Arguments: the new city name

	Returns: none

	Note:
	***************************************************************/
void Provider::set_city(const char* new_city)
{
	strcpy(city, new_city);
}

/***************************************************************
	Function: set_state

	Use: sets the state to the new one

	Arguments: the new state

	Returns: none

	Note:
	***************************************************************/
void Provider::set_state(const char* new_state)
{
	strcpy(state, new_state);
}

/***************************************************************
	Function: set_zip_code

	Use: sets the zip code to the new zip code

	Arguments: the new zip code

	Returns: none

	Note:
	***************************************************************/
void Provider::set_zip_code(const char* new_zip)
{
	strcpy(zip_code, new_zip);
}

/***************************************************************
	Function: set_phone_number

	Use: sets the phone number to the new number

	Arguments: the new phone number

	Returns: none

	Note:
	***************************************************************/
void Provider::set_phone_number(const char* new_phone)
{
	strcpy(phone_number, new_phone);
}

/***************************************************************
	Function: print

	Use: prints out all the information of the person

	Arguments: none

	Returns: none

	Note:
	***************************************************************/
void Provider::print()
{
	cout << "#" << provider_num << endl
		 << name << endl
		 << specialty << endl
		 << first_address << endl
		 << second_address << endl
		 << city << ", " << state << " " << zip_code << endl
		 << phone_number;
}
