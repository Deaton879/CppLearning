/*
 * account.h
 *
 *  Created on: Jun 16, 2022
 *      Author: Dallas Eaton
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

namespace using_classes {
	class Account {
		private:
			int id;
			std:: string name;
			double balance;
		public:
			Account();
			void set_id(int aId);
			int get_id();
			void set_name(std::string aName);
			std::string get_name();
			void set_balance(double aBalance);
			float get_balance();
	};
}

#endif /* ACCOUNT_H_ */

