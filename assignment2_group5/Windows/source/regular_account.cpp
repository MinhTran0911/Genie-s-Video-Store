#include "Regular_account.h"

// default constructor
Regular_account::Regular_account()
	: Account()
{
	this->acc_type = "Regular";
}

// parameterized constructor
Regular_account::Regular_account(string id, string name, string address, string phone)
	: Account(id, name, address, phone)
{
	this->acc_type = "Regular";
}

Regular_account::Regular_account(string id, string name, string address, string phone, int num_rented, string acc_type)
	: Account(id, name, address, phone, num_rented, acc_type)
{
	this->acc_type = "Regular";
}

// copy constructor (for promoting)
Regular_account::Regular_account(Account& acc)
{
	// copy previous info 
	this->id = acc.get_id();
	this->name = acc.get_name();
	this->address = acc.get_address();
	this->phone = acc.get_phone();
	this->num_rented = acc.get_numrented();
	this->next = acc.get_next();
	acc.get_rental_list()->copy_list_to(*this->rental_list);
	// promote acc_type and reset count_borrow and count return
	this->acc_type = "Regular";
	this->count_borrow = 0;
	this->count_return = 0;
	
}

// destructor
Regular_account::~Regular_account() {};