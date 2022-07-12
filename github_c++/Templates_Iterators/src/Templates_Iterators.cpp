//============================================================================
// Name        : Program.cpp
// Author      : Dallas Eaton
// Version     :
// Copyright   : Your copyright notice
// Description : Contains the main function for the
//============================================================================

#include "account.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <list>



using namespace std;
using template_iterators::Account;

void display_account(Account account);
list<Account>::iterator find_by_id(list<Account>& account_list, int id);

int main()
{

	Account user;
	string name;
	double balance;
	int id = 0;

	int choice = 1;
	double amount;

	list<Account> accounts;



	while (choice != 0)
	{
		cout << endl << "Account Menu:" << endl
			 << "0. Quit Program" << endl
			 << "1. Display Account Information" << endl
			 << "2. Add a deposit to an account" << endl
			 << "3. Withdraw from an account" << endl
			 << "4. Add new account" << endl
			 << "5. Find account by ID" << endl
			 << "Your choice: ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				{
					for(auto it = accounts.begin(); it != accounts.end(); it++) {
						display_account(*it);
					}
					break;
				}
			case 2:
				{
					int index;
					cout << "Enter the ID of the account to find: ";
					cin >> index;
					list<Account>::iterator it;
					it = find_by_id(accounts, index);

					if (it != accounts.end()) {
						cout << "Found account: ";
						display_account(*it);
					} else {
						cout << "Error: Account does not exist." << endl;
					}

					cout << "Amount to deposit: ";
					cin >> amount;
					balance = it->get_balance();
					it->set_balance((balance + amount));
					cout << endl;
					break;
				}
			case 3:
				{
					int index;
					cout << "Enter the ID of the account to find: ";
					cin >> index;
					list<Account>::iterator it;
					it = find_by_id(accounts, index);

					if (it != accounts.end()) {
						cout << "Found account: ";
						display_account(*it);
					} else {
						cout << "Error: Account does not exist." << endl;
					}

					cout << "Amount to withdraw: ";
					cin >> amount;
					balance = it->get_balance();
					it->set_balance((balance - amount));
					cout << endl;
					break;
				}
			case 4:
				{
					Account newUser;
					cout << "Enter the name: ";
					cin >> name;
					newUser.set_name(name);

					cout << "Enter the balance: ";
					cin >> balance;
					newUser.set_balance(balance);
					newUser.set_id(id);
					id++;
					accounts.insert(accounts.end(), newUser);
					break;
				}
			case 5:
				{
					int index;
					cout << "Enter the ID of the account to find: ";
					cin >> index;

					list<Account>::iterator it;
					it = find_by_id(accounts, index);

					if (it != accounts.end()) {
						cout << "Found account: ";
						display_account(*it);
					} else {
						cout << "Error: Account does not exist." << endl;
					}

					break;
				}
		}
	}
}

void display_account(Account account)
{
	cout << "Account ID: "
		 << account.get_id()
		 << " Name: "
		 << account.get_name()
		 << " Balance: $" << fixed << setprecision(2)
		 << account.get_balance()
		 << endl;
}

list<Account>::iterator find_by_id(list<Account>& account_list, int id)
{
	list<Account>::iterator it;
	for(it = account_list.begin(); it != account_list.end(); it++)
	{
		if(it->get_id() == id) {
			return it;
		}
	}
	return it;
}
