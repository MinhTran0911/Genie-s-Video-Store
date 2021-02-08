#ifndef UI_H
#define UI_H

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

#include "io_func.h"
#include "check_input.h"

#include <iostream>
#include <string>
using namespace std;

void video_store(Account_list* acclist, Item_list* vlist);

void main_menu();

void aud_item(Item_list* vlist, Account_list* acclist);

void aud_customer(Account_list* acclist);

void promote(Account_list* acclist);

void add_item(Item_list* list);

void update_item(Item_list* list);

void delete_item(Item_list* vlist, Account_list* acclist);

void update_stock(Item_list* list);

void add_customer(Account_list* acclist);

void update_customer(Account_list* acclist);

void renting(Account_list* acclist, Item_list* vlist);

void returning(Account_list* acclist, Item_list* vlist);

void display_all(Item_list* list);

void display_all(Account_list* list);

void disp_group_menu(Account_list* list);

void search_menu(Account_list* acclist, Item_list* vlist);

void search_id(Account_list* list);

void search_id(Item_list* list);

void search_name(Account_list* list);

void search_name(Item_list* list);

void clear_screen();

void disp_group_info();

#endif
