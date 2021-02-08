#ifndef DVD_H
#define DVD_H

#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class DVD : 
    public Item 
{
public:
    // constructor
    DVD();
    DVD(string id, string title, string type, string loan_type, int copies_num, double rental_fee, string genre);

    // destructor
    ~DVD();

    // copy constructor
    DVD(const DVD& dvd);
};

#endif