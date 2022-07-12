//============================================================================
// Name        : First.cpp
// Author      : Dallas Eaton
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	int id = 0;
	string account_holder = "name";
	double balance = 0.0;
	int choice;
	double amount;

	cout << "Enter the name: ";
	cin >> account_holder;

	cout << "Enter the balance: ";
	cin >> balance;

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
				cout << "Account ID: " << id
				     << "  Name: " << account_holder
					 << "  Balance: $" << balance << endl;
				break;
			case 2:
				cout << "Amount to deposit: ";
				cin >> amount;
				balance += amount;
				cout << endl;
				break;
			case 3:
				cout << "Amount to withdraw: ";
				cin >> amount;
				balance -= amount;
				cout << endl;
				break;
			default:
				break;
		}
	}

}
