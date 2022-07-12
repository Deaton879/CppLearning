/*
 * contact.cpp
 *
 *  Created on: Jul 1, 2022
 *      Author: Dallas Eaton
 */

#include "contact.h"

#include <string>
#include <iostream>


using namespace std;
using smart_pointers::Contact;

Contact::Contact(): address(" "), city(" "), state(" "), zip(" "), phone(" "){}

Contact::~Contact()
{
	cout << "In Contact destructor (address is "
		 << Contact::get_address()
		 << ")" << endl;
}

void Contact::initialize()
{
	cout << endl << "Enter Address: ";
	cin.ignore();
	getline(cin, address);

	cout << "Enter City: ";
	getline(cin, city);

	cout << "Enter State: ";
	getline(cin, state);

	cout << "Enter Zip Code: ";
	getline(cin, zip);

	cout << "Enter Phone Number: ";
	getline(cin, phone);

}

void Contact::set_address(string street)
{
	address = street;
}

string Contact::get_address()
{
	return address;
}

void Contact::set_city(string new_city)
{
	city = new_city;
}

string Contact::get_city()
{
	return city;
}

void Contact::set_state(string new_state)
{
	state = new_state;
}

string Contact::get_state()
{
	return state;
}

void Contact::set_zip(string zip_code)
{
	zip = zip_code;
}

string Contact::get_zip()
{
	return zip;
}

void Contact::set_phone(string number)
{
	phone = number;
}

string Contact::get_phone()
{
	return phone;
}

void copy(Contact contact)
{
	string a = contact.get_address();
	string c = contact.get_city();
	string s = contact.get_state();
	string z = contact.get_zip();
	string p = contact.get_phone();
}




