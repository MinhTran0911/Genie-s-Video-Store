// class Account: each account is a node in account_list
//
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "rental_list.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
	// account  info
	string id;
	string name;
	string address;
	string phone;
	int num_rented = 0;
	string acc_type;

	// number of borrow + return in 1 session including read file (used for promoting)
	int count_borrow = 0;
	int count_return = 0;

	// linked list of rental item (store item id)
	Rental_list* rental_list;

	// pointer to next node
	Account* next;
public:
	// constructor
	Account();
	Account(string id, string name, string address, string phone);
	Account(string id, string name, string address, string phone, int num_rented, string acc_type);
	// copy constructor
	Account(const Account& acc);
	// destructor
	~Account();

	// getter and setter
	string get_id();
	string get_name();
	string get_address();
	string get_phone();
	int get_numrented();
	string get_acctype();
	Account* get_next();

	int get_count_borrow();
	int get_count_return();

	Rental_list* get_rental_list();

	void set_id(string id);
	void set_name(string name);
	void set_address(string address);
	void set_phone(string phone);
	void set_numrented(int numrented);
	void set_acctype(string acctype);
	void set_next(Account* next);

	// virtual add number of rented item
	virtual void add_numrented();

	// print info of one account
	void print();
	// overloading operator << (used for write file)
	friend ostream& operator<<(ostream& out, Account& obj);

	// virtual function for borrowing
	virtual void borrowing(Item* item);
	// function for borrowing
	void returning(Item* item);

};

#endif