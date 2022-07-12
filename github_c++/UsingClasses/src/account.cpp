/*
 * account.cpp
 *
 *  Created on: Jun 16, 2022
 *      Author: Dallas Eaton
 */

#include "account.h"

#include <string>

using using_classes::Account;

Account::Account(): id(0), balance(0.0){}

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

