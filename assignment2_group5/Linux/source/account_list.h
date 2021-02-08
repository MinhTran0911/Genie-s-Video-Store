// Account_list : linked list to store Account 
//
#ifndef ACCOUNT_LIST_H
#define ACCOUNT_LIST_H

#include "account.h"
#include "guest_account.h"
#include "regular_account.h"
#include "vip_account.h"

#include "rental_list.h"
#include "rental_item.h"
#include "item_list.h"

#include <iostream>
#include <string>
using namespace std;

class Account_list
{
private:
	// initialize head node
	Account* head;
public:
	// constructor
	Account_list();
	Account_list(Account* head);
	// destructor
	~Account_list();
	// getter for head node
	Account* get_head();
	
	// CRUD
	void insert_acc(Account* new_acc); // insert account (sorted by id)
	void insert_acc_by_name(Account* new_acc); // insert account (sorted by name)
	void update_acc(Account* update_acc); // update account (by id)
	void delete_acc(string id); // delete account (by id)
	void delete_rental_item(string id); // delete item in rental list of all account

	// promoting account (by id)
	void promote_acc_by_id(string id); 

	// search
	bool exist_account_id(string id);
	Account* search_by_id(string id); // search account by id 
	void search_by_level(string level); // search account by level
	void search_by_name(string name); // search account by name

	// print list
	void print_list(); // print account list (sorted by id)
	void print_list_sort_by_name(); // print account list (sorted by name)
	
	// write account list to file 
	void write_file(string file_acc); 

	// check an item in rental lists(by id)
	bool exist_rental_item(string id);
};

#endif