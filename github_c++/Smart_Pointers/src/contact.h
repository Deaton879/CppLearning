/*
 * contact.h
 *
 *  Created on: Jul 1, 2022
 *      Author: Dallas Eaton
 */

#ifndef SRC_CONTACT_H_
#define SRC_CONTACT_H_


#include <string>
using std::string;

namespace smart_pointers {
	class Contact {
		private:
			string address;
			string city;
			string state;
			string zip;
			string phone;
		public:
			Contact();
			~Contact();

			void set_address(string street);
			string get_address();

			void set_city(string new_city);
			string get_city();

			void set_state(string new_state);
			string get_state();

			void set_zip(string zip_code);
			string get_zip();

			void set_phone(string new_number);
			string get_phone();

			void initialize();

			void copy(Contact contact);


	};
}


#endif /* SRC_CONTACT_H_ */
