#include "Provider.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//default Contructor
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
/***************************************************************
	Function: print

	Use: prints out all the information of the person

	Arguments: none

	Returns: none

	Note:
	***************************************************************/
void Provider::print() const
{
	cout << "#" << provider_num << endl
		 << name << endl
		 << specialty << endl
		 << first_address << endl
		 << second_address << endl
		 << city << ", " << state << " " << zip_code << endl
		 << phone_number << endl << endl;
}

/***************************************************************
	Function: getProviderNumber

	Use: returns the provider number

	Arguments: none

	Returns: the provider number

	Note:
	***************************************************************/
const char* Provider::getProviderNumber()
{
	return provider_num;
}

/***************************************************************
        Function: getSpecialty

        Use: returns the specialty

        Arguments: none

        Returns: the specialty

        Note:
        ***************************************************************/

const char* Provider::getSpecialty()
{
	return specialty;
}

/***************************************************************
        Function: getName

        Use: returns the name

        Arguments: none

        Returns: the name

        Note:
        ***************************************************************/

const char* Provider::getName()
{
	return name;
}

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
