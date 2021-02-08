// class Rental_item: each rental item is a node of rental list
//
#ifndef RENTAL_ITEM_H
#define RENTAL_ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Rental_item
{
private:
    string item_id; // variable to store rented item id
    Rental_item* next; //pointer to the next node.
public:
    // constructor 
    Rental_item(string item_id);

    // getter
    string get_item_id();
    Rental_item* get_next();

    // setter
    void set_item_id(string item_id);
    void set_next(Rental_item* next);
    
    // destructor
    ~Rental_item();

    // overloading operator << (for write file)
    friend ostream& operator << (ostream& out, Rental_item& obj);
};

#endif