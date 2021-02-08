#include "rental_item.h"

// constructor
Rental_item::Rental_item(string item_id) {
	this->item_id = item_id;
	this->next = NULL;
}

// getter
string Rental_item::get_item_id() { return this->item_id; }
Rental_item* Rental_item::get_next() { return this->next; }

// setter 
void Rental_item::set_item_id(string item_id) { this->item_id = item_id; }
void Rental_item::set_next(Rental_item* next) { this->next = next; }

// destructor
Rental_item::~Rental_item() {}

// overloading operator << (for write file)
ostream& operator<<(ostream& out, Rental_item& obj)
{
	out << obj.get_item_id() << endl;
	return out;
}
