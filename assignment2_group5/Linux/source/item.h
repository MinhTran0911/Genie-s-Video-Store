// class Item: each account is a node in Item_list
//
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
protected:
    // item info
    string id;
    string title;
    string type;
    string loan_type;
    int copies_num;
    double rental_fee;
    string genre;

    // pointer to next node
    Item* next;
public:
    // constructor
    Item();
    Item(string id, string title, string type, string loan_type, int copies_num, double rental_fee);
    Item(string id, string title, string loan_type, int copies_num, double rental_fee);
    Item(string id, string title, string loan_type, int copies_num, double rental_fee, string genre);
    // destructor
    ~Item();
    // copy constructor 
    Item(const Item& e);

    // getter
    string get_id();
    string get_title();
    string get_type();
    string get_loan_type();
    int get_copies_num();
    double get_rental_fee();
    string get_genre();
    Item* get_next();

    // setter
    void set_id(string id);
    void set_title(string title);
    void set_type(string type);
    void set_loan_type(string loan_type);
    void set_copies_num(int copies_num);
    void set_rental_fee(double rental_fee);
    void set_genre(string genre);
    void set_next(Item* next);

    void set_all(Item* item);

    // bool check the availability for rent
    bool is_available();

    // set item to borrowing and returning process
    bool borrowing();
    bool returning();

    // print info of one item
    void print();
    // overloading operator << (used for write file)
    friend ostream& operator << (ostream& out, Item& obj);
};

#endif