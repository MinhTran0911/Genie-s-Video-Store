// Rental_list : linked list to store rental id in each account 
//
#ifndef RENTAL_LIST_H
#define RENTAL_LIST_H

#include "rental_item.h"

#include <iostream>
#include <string>
using namespace std;

class Rental_list
{
private:
    // initialize head node
    Rental_item* head; 
public:
    // constructor
    Rental_list();
    Rental_list(Rental_item* head);
    // destructor
    ~Rental_list();
    // getter for head node 
    Rental_item* get_head();
    
    // append and delete item in list 
    void append_list(string id);
    void delete_item(string id);
    
    // print list (sorted by id)
    void print_list();
    // overloading operator << (used for write rental list to file)
    friend ostream& operator << (ostream& out, Rental_list& obj);

    // copy list of item to other list (used for promoting)
    void copy_list_to(Rental_list& list);

    bool already_rented(string id);
};

#endif