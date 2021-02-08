#include "item.h"
#include "dvd.h"

#include <iostream>
#include <string>

using namespace std;

// default constructor
DVD::DVD() : Item()
{
	this->genre = "Default genre";
}

// parameterized constructor
DVD::DVD(string id, string title, string type, string loan_type, int copies_num, double rental_fee, string genre)
	: Item(id, title, type, loan_type, copies_num, rental_fee)
{
	this->genre = genre;
}

// copy constructor
DVD::DVD(const DVD& dvd) : Item(dvd) {}

// destructor
DVD::~DVD() {}