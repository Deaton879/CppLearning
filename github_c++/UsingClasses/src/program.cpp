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

using namespace std;

int main() {

	using_classes::Account user;
	std::string name;
	float balance;

	int choice;
	float amount;

	cout << "Enter the name: ";
	cin >> name;
	user.set_name(name);

	cout << "Enter the balance: ";
	cin >> balance;
	user.set_balance(balance);

	while (choice != 0){
		cout << endl << "Account Menu:" << endl
			 << "0. Quit Program" << endl
			 << "1. Display Account Information" << endl
			 << "2. Add a deposit to an account" << endl
			 << "3. Withdraw from an account" << endl
			 << "Your choice: ";
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Account ID: " << user.get_id()
					 << "  Name: " << user.get_name()
					 << "  Balance: $" << fixed << setprecision(2) << user.get_balance() << endl;
				break;
			case 2:
				cout << "Amount to deposit: ";
				cin >> amount;
				balance += amount;
				user.set_balance(balance);
				cout << endl;
				break;
			case 3:
				cout << "Amount to withdraw: ";
				cin >> amount;
				balance -= amount;
				user.set_balance(balance);
				cout << endl;
				break;
			default:
				break;
		}
	}
}
