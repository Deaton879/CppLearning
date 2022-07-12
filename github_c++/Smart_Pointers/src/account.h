/*
 * account.h
 *
 *  Created on: Jun 16, 2022
 *      Author: Dallas Eaton
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include "contact.h"
#include <memory>

using namespace std;

namespace smart_pointers {
	class Account {
		private:
			int id;
			string name;
			double balance;
			shared_ptr<Contact> contact_info;
		public:
			Account();
			~Account();
			void set_id(int aId);
			int get_id();
			void set_name(string aName);
			string get_name();
			void set_balance(double aBalance);
			float get_balance();
			void add_contact();
			void display();
	};
}

#endif /* ACCOUNT_H_ */

