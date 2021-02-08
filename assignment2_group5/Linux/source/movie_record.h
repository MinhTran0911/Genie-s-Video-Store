#ifndef MOVIE_RECORD_H
#define MOVIE_RECORD_H

#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class Movie_record : 
    public Item
{
public:
    // constructor
    Movie_record();
    Movie_record(string id, string title, string type, string loan_type, int copies_num, double rental_fee, string genre);

    // destructor
    ~Movie_record();
    // copy constructor
    Movie_record(Movie_record& movie);
};

#endif