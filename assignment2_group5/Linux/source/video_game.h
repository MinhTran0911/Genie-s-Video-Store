#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class Video_game : 
    public Item
{
protected:

public:
    // constructor
    Video_game();
    Video_game(string id, string title, string type, string loan_type, int copies_num, double rental_fee);
   
    // destructor
    ~Video_game();

    // copy constructor
    Video_game(const Video_game& vdg);
};

#endif