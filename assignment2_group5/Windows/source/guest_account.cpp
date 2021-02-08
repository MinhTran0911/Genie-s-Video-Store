#include "Guest_account.h"
// default constructor
Guest_account::Guest_account() : Account() {};

// parameterized constructor
Guest_account::Guest_account(string id, string name, string address, string phone)
	: Account(id, name, address, phone) {};

Guest_account::Guest_account(string id, string name, string address, string phone, int num_rented, string acc_type)
	: Account(id, name, address, phone, num_rented, acc_type) {};

// destructor
Guest_account::~Guest_account() {};

// bool check if account reach the max rental
bool Guest_account::can_borrow()
{
	if (num_rented < MAXRENT)
		return true;
	else return false;
}

// overriding borrowing function
void Guest_account::borrowing(Item* item)
{
	if (this->can_borrow() == true) // if the account is eligible to borrow
	{  
		if (item->is_available() == false) // if the item is not available (num of copies = 0), print error
		{
			cerr << item->get_type() << " '" << item->get_title() << "' is not available currently." << endl;
			return;
		}
		else if (item->get_loan_type() == "2-day") // if the item have "2-day" type, print error
		{
			cerr << this->get_id() << " as a Guest cannot borrow 2-day video." << endl;
			return;
		}
		else if(this->get_rental_list()->already_rented(item->get_id()))
		{
			cerr << "Cannot process request! " << this->get_id() << " is borrowing the same item currently." << endl; // print error
			return;
		}
		item->borrowing(); // item is set to borrowing
		this->add_numrented(); // increse num_rented and count_borrow by one
		this->get_rental_list()->append_list(item->get_id()); // add item id to rental list 
		cout << "'" << item->get_title() << "' is rented by " << this->get_id() << " successfully." << endl; // print successful message
		return;		
	}
	else
	{
		cerr << this->get_id() << " has reached the maximun number of rentals." << endl; // if the account is not eligible, print error
		return;
	}
}
