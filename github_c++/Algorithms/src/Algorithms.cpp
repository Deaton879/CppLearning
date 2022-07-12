//============================================================================
// Name        : Algorithms.cpp
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
#include <algorithm>
#include <numeric>



using namespace std;
using algorithms::Account;

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
			 << "6. Remove account" << endl
			 << "7. Show total balance for all accounts" << endl
			 << "8. Add a dividend to all accounts" << endl
			 << "Your choice: ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				{
//					for(auto it = accounts.begin(); it != accounts.end(); it++) {
//						display_account(*it);
//					}

//					USE FOR EACH INSTEAD OF ITERATORS
					for_each(accounts.begin(), accounts.end(),
							[](auto& account) {
								display_account(account);
						}
					);
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
			case 6:
				{
					int id;
					cout << "Enter account ID to remove: ";
					cin >> id;

					auto new_end = remove_if(accounts.begin(), accounts.end(),
						[id](Account& account) {
							return id == account.get_id();
						}
					);
					accounts.erase(new_end, accounts.end());
					break;
				}
			case 7:
				{
					float total = accumulate(accounts.begin(), accounts.end(), 0.0f,
						[](auto accumulator, auto& account){
							return accumulator + account.get_balance();
						}
					);
					cout << "Total in all accounts: $" << fixed << setprecision(2) << total << endl;
					break;
				}
			case 8:
				{
					float increment;
					cout << "Enter the dividend as a percentage: ";
					cin >> increment;
					float percent = increment / 100;

					transform(accounts.begin(), accounts.end(), accounts.begin(),
						[percent](Account& account) {
							int balance = account.get_balance();
							account.set_balance(balance += (percent * balance ));
							return account;
						}
					);
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
