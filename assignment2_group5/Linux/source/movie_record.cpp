#include "item.h"
#include "movie_record.h"

#include <iostream>
#include <string>

using namespace std;

// default constructor
Movie_record::Movie_record() : Item()
{
	this->genre = "Default genre";
}

// parameterized constructor
Movie_record::Movie_record(string id, string title, string type, string loan_type, int copies_num, double rental_fee, string genre)
	: Item(id, title, type, loan_type, copies_num, rental_fee)
{
	this->genre = genre;
}

// destructor
Movie_record::~Movie_record() {}

// copy constructor
Movie_record::Movie_record(Movie_record& movie)
	: Item(movie) {}
