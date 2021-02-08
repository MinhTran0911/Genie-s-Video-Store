#include "item.h"
#include "video_game.h"

#include <iostream>
#include <string>

using namespace std;

// default constructor
Video_game::Video_game() : Item() {}

// parameterized constructor
Video_game::Video_game(string id, string title, string type, string loan_type, int copies_num, double rental_fee)
	: Item(id, title, type, loan_type, copies_num, rental_fee) {}

// destructor
Video_game::~Video_game() {}

// copy constructor
Video_game::Video_game(const Video_game& vdg) : Item(vdg) {}