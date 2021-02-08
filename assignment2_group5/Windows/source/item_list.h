// Item_list : linked list to store Item
//
#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include "item.h"
#include "account_list.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item_list
{
private:
	// initialize head node
	Item* head;
public:
	// constructor
	Item_list();
	Item_list(Item* head);
	// destructor
	~Item_list();
	// getter for head node
	Item* get_head();

	// CRUD
	void insert_item(Item* new_item); // insert item (sorted by id)
	void insert_item_by_title(Item* new_item); // insert item (sorted by title)
	void update_item(Item* update_item); // update item (sorted by id)
	void delete_item(string id); // delete item (sorted by id)

	// search
	bool exist_item_id(string id);
	Item* search_by_id(string id); // search item by id
	void search_by_title(string title); // search item by title
	void show_out_of_stock(); // show out of stock item

	// print list 
	void print_list(); // print item list (sorted by id)
	void print_list_sort_by_title(); // print item list (sorted by title)

	// write item list to file 
	void write_file(string file_item);
};

#endif