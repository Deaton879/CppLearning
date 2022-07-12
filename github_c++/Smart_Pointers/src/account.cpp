/*
 * account.cpp
 *
 *  Created on: Jun 16, 2022
 *      Author: Dallas Eaton
 */

#include "account.h"
#include "contact.h"
#include <iostream>
#include <iomanip>
#include <string>

using smart_pointers::Account;
using smart_pointers::Contact;

Account::Account(): id(0), balance(0.0), contact_info(nullptr){}

Account::~Account()
{
	cout << "In Account destructor (name is "
			 << Account::get_name()
			 << ")" << endl;
}

void Account::set_id(int aId){
	id = aId;
}

int Account::get_id() {
	return id;
}

void Account::set_name(std::string aName){
	name = aName;
}

std::string Account::get_name() {
	return name;
}

void Account::set_balance(double aBalance) {
	balance = aBalance;
}

float Account::get_balance() {
	return balance;
}

void Account::add_contact()
{
	Account::contact_info = make_shared<Contact>();
	Account::contact_info->initialize();

}

void Account::display()
{
	cout << endl
		 << "Account ID: "
		 << Account::get_id()
		 << " Name: "
		 << Account::get_name()
		 << " Balance: $" << fixed << setprecision(2)
		 << Account::get_balance()
		 << endl;

	if (Account::contact_info != nullptr)
	{
		cout << " + Contact Information:" << endl
			 << "Address: "
			 << Account::contact_info->get_address() << endl
			 << " City: "
			 << Account::contact_info->get_city() << endl
			 << " State: "
			 << Account::contact_info->get_state() << endl
			 << " Zip: "
			 << Account::contact_info->get_zip() << endl
			 << " Phone: "
			 << Account::contact_info->get_phone()
			 << endl;
	}

}
