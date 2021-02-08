#include "item.h"

// default constructor
Item::Item()
{
    this->id = "I000-0000";
    this->title = "Default title";
    this->type = "DVD";
    this->loan_type = "1-week";
    this->copies_num = 1;
    this->rental_fee = 0;
    this->genre = "";
    this->next = NULL;
}

// parameterized constructor
Item::Item(string id, string title, string loan_type, int copies_num, double rental_fee)
{
    this->id = id;
    this->title = title;
    this->type = "";
    this->loan_type = loan_type;
    this->copies_num = copies_num;
    this->rental_fee = rental_fee;
    this->genre = "";
    this->next = NULL;
}

Item::Item(string id, string title, string loan_type, int copies_num, double rental_fee, string genre)
{
    this->id = id;
    this->title = title;
    this->type = "";
    this->loan_type = loan_type;
    this->copies_num = copies_num;
    this->rental_fee = rental_fee;
    this->genre = genre;
    this->next = NULL;
}

Item::Item(string id, string title, string type, string loan_type, int copies_num, double rental_fee)
{
    this->id = id;
    this->title = title;
    this->type = type;
    this->loan_type = loan_type;
    this->copies_num = copies_num;
    this->rental_fee = rental_fee;
    this->genre = "";
    this->next = NULL;
}

// destructor
Item::~Item() {}

// copy constructor 
Item::Item(const Item& itm)
{
    id = itm.id;
    title = itm.title;
    type = itm.type;
    loan_type = itm.loan_type;
    copies_num = itm.copies_num;
    rental_fee = itm.rental_fee;
    genre = itm.genre;
    next = NULL;
}

// getter
string Item::get_id() { return this->id; }
string Item::get_title() { return this->title; }
string Item::get_type() { return this->type; }
string Item::get_loan_type() { return this->loan_type; };
int Item::get_copies_num() { return this->copies_num; };
double Item::get_rental_fee() { return this->rental_fee; }
string Item::get_genre() { return this->genre; }
Item* Item::get_next() { return this->next; }

// setter
void Item::set_id(string id) { this->id = id; }
void Item::set_title(string title) { this->title = title; }
void Item::set_type(string type) { this->type = type; }
void Item::set_loan_type(string loan_type) { this->loan_type = loan_type; }
void Item::set_copies_num(int copies_num) { this->copies_num = copies_num; };
void Item::set_rental_fee(double rental_fee) { this->rental_fee = rental_fee; }
void Item::set_genre(string genre) { this->genre = genre; }
void Item::set_next(Item* next) { this->next = next; }

// setter for all info (used for update)
void Item::set_all(Item* item)
{
    this->title = item->get_title();
    this->loan_type = item->get_loan_type();
    this->copies_num = item->get_copies_num();
    this->rental_fee = item->get_rental_fee();
    this->genre = item->get_genre();
}

// bool check the availability for rent
bool Item::is_available()
{
    if (copies_num > 0) // if the number of copies larger than 0, item is available
        return true;
    else return false;
}

// set item to borrowing process
bool Item::borrowing()
{
    if (this->is_available() == true) // if item is available
    {
        this->copies_num -= 1; // number of copies reduce by 1 
        return true;
    }
    else return false;

}

// set item toreturning process
bool Item::returning()
{
    this->copies_num += 1; // number of copies increase by 1 
    return true;
}

// print info of this item
void Item::print()
{
    cout<< this->get_id() << ", ";
    cout << this->get_title() << ", ";
    cout << this->get_type() << ", ";
    cout << this->get_loan_type() << ", ";
    cout << this->get_copies_num() << ", ";
    cout << this->get_rental_fee() << ", ";
    if (this->get_genre() != "") // if genre not null, print genre
        cout << this->get_genre() << ", ";
    if (this->is_available() == true) // print the availability for rent
        cout << "Available" << ".";
    else cout << "Borrowed" << ".";
    cout << endl;
    return;
}
// overloading operator << (used for write file)
ostream& operator<<(ostream& stream, Item& obj)
{
    stream << obj.get_id() << ",";
    stream << obj.get_title() << ",";
    stream << obj.get_type() << ",";
    stream << obj.get_loan_type() << ",";
    stream << obj.get_copies_num() << ",";
    stream << obj.get_rental_fee();
    if (obj.get_genre() != "")
        stream << "," << obj.get_genre();
    stream << endl;
    return stream; // return the stream
}