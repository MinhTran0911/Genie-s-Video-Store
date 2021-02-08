#ifndef IO_FUNC_H
#define IO_FUNC_H

#include "account.h"
#include "guest_account.h"
#include "regular_account.h"
#include "vip_account.h"
#include "account_list.h"

#include "item.h"
#include "dvd.h"
#include "movie_record.h"
#include "video_game.h"
#include "item_list.h"

#include "check_input.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int count(string s, char c);
void load_item(string line, Item_list* vlist);
string load_acc(string line, Account_list* acclist);
void read_file_item(char* file_name, Item_list* vlist);
void read_file_acc(char* file_name, Account_list* acclist, Item_list* vlist);

#endif
