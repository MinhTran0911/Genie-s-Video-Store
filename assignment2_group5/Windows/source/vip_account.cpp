#include "vip_account.h"

// default constructor
Vip_account::Vip_account()
	: Account()
{
	this->acc_type = "VIP";
}

// parameterized constructor
Vip_account::Vip_account(string id, string name, string address, string phone)
	: Account(id, name, address, phone)
{
	this->acc_type = "VIP";
}

Vip_account::Vip_account(string id, string name, string address, string phone, int num_rented, string acc_type)
	: Account(id, name, address, phone, num_rented, acc_type)
{
	this->acc_type = "VIP";
}

// copy constructor (for promoting)
Vip_account::Vip_account(Account& acc)
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
	this->acc_type = "VIP";
	this->count_borrow = 0;
	this->count_return = 0;
	
}

// destructor
Vip_account::~Vip_account() {};

// overriding add number of rented item 
void Vip_account::add_numrented()
{
	this->num_rented += 1;
	this->count_borrow += 1;
	this->reward_point += 10; // Only for VIP account
}
// overriding borrowing function
void Vip_account::borrowing(Item* item)
{
	if (item->is_available() == false) // if the item is not available (num of copies = 0), print error
	{
		cout << item->get_type() << " '" << item->get_title() << "' is not available currently." << endl;
		return;
	}
	else if (this->get_rental_list()->already_rented(item->get_id())) // if account is holding the same item, print error
	{
		cerr << "Cannot process request! " << this->get_id() << " is borrowing the same item currently."<< endl; 
		return;
	}
	item->borrowing(); // item is set to borrowing
	if (this->reward_point % 100 == 0) // for every 100 points, vip account can rent 1 item for free (limit in 1 session)
	{
		cout << "Notification: " << this->get_id() << " can have this rental for free." << endl;
	}
	this->add_numrented(); // increse num_rented and count_borrow by one
	this->get_rental_list()->append_list(item->get_id()); // add item id to rental list 
	cout << "'" << item->get_title() << "' is rented by " << this->get_id() << " successfully." << endl; // print successful message
	return;
}