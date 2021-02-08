#include "Account.h"

// default constructor
Account::Account()
{
	this->id = "C000";
	this->name = "Default";
	this->address = "702 Nguyen Van Linh";
	this->phone = "123456789";
	this->num_rented = 0;
	this->acc_type = "Guest";
	this->next = NULL;
	this->count_borrow = 0;
	this->count_return = 0;
	this->rental_list = new Rental_list();
}

// parameterized constructor (default acc_type is guest)
Account::Account(string id, string name, string address, string phone)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->num_rented = 0;
	this->acc_type = "Guest";
	this->next = NULL;
	this->count_borrow = 0;
	this->count_return = 0;
	this->rental_list = new Rental_list();

}

// parameterized constructor
Account::Account(string id, string name, string address, string phone, int num_rented, string acc_type)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->num_rented = num_rented;
	this->acc_type = acc_type;
	this->next = NULL;
	this->count_borrow = 0;
	this->count_return = 0;
	this->rental_list = new Rental_list();
}

// destructor
Account::~Account()
{
	delete this->rental_list; // delete the rental list in this account when deconstruct
};

// copy constructor (except the rental list)
Account::Account(const Account& acc)
{
	this->id = acc.id;
	this->name = acc.name;
	this->address = acc.address;
	this->phone = acc.phone;
	this->num_rented = acc.num_rented;
	this->acc_type = acc.acc_type;
	this->next = NULL;
	this->count_borrow = 0;
	this->count_return = 0;
	this->rental_list = NULL;
}

// getter

string Account::get_id() { return id; }
string Account::get_name() { return name; }
string Account::get_address() { return address; }
string Account::get_phone() { return phone; }
int Account::get_numrented() { return num_rented; }
string Account::get_acctype() { return acc_type; }
Account* Account::get_next() { return next; }

int  Account::get_count_borrow() { return this->count_borrow; }
int  Account::get_count_return() { return this->count_return; }

Rental_list* Account::get_rental_list() { return this->rental_list; }

// setter
void Account::set_id(string id) { this->id = id; }
void Account::set_name(string name) { this->name = name; }
void Account::set_address(string address) { this->address = address; }
void Account::set_phone(string phone) { this->phone = phone; }
void Account::set_numrented(int numrented) { num_rented = numrented; }
void Account::set_acctype(string acctype) { acc_type = acctype; }
void Account::set_next(Account* next) { this->next = next; }

// add number of rented item
void Account::add_numrented()
{
	this->num_rented += 1; 
	this->count_borrow += 1;
}

// print info of this account 
void Account::print()
{
	cout << this->get_id() << ", ";
	cout << this->get_name() << ", ";
	cout << this->get_address() << ", ";
	cout << this->get_phone() << ", ";
	cout << this->get_numrented() << ", ";
	cout << this->get_acctype();
	cout << endl;
	return;
}

// overloading operator << (used for write account to file)
ostream& operator<<(ostream& stream, Account& obj)
{
	stream << obj.get_id() << ",";
	stream << obj.get_name() << ",";
	stream << obj.get_address() << ",";
	stream << obj.get_phone() << ",";
	stream << obj.get_numrented() << ",";
	stream << obj.get_acctype();
	stream << endl;
	stream << *obj.get_rental_list();
	return stream; // return the stream
}

// default borrowing function
void Account::borrowing(Item* item)
{
	if (item->is_available() == false) // if the item is not available (num of copies = 0), print error
	{
		cerr << item->get_type() << " '" << item->get_title() << "' is not available currently." << endl;
		return;
	}
	else if (this->get_rental_list()->already_rented(item->get_id()))
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

// returning function
void Account::returning(Item* item)
{
	Rental_item* current = this->get_rental_list()->get_head(); // initialize current node
	while (current != NULL) // traverse the rental list of this account
	{
		if (current->get_item_id().compare(item->get_id()) == 0) // check if the account rented the item currently or not
		{
			item->returning(); // item is set to returning
			this->num_rented -= 1; // reduce the num_rented by 1
			this->count_return += 1; // increase count_return by 1
			this->get_rental_list()->delete_item(item->get_id()); // delete item id out of rental list 
			cout << "'" << item->get_title() << "' is returned by " << this->get_id() << " successfully." << endl; // print successful message
			return;
		}
		current = current->get_next(); // move pointer ahead 
	}
	cerr << this->get_id() << " has not rented '" << item->get_id() << "'" << endl; // if item is not found in rental list, print error
	return;
}





