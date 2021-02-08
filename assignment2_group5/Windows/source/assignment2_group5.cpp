// assignment2_group5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Account-related file
#include "account.h"
#include "guest_account.h"
#include "regular_account.h"
#include "vip_account.h"
#include "account_list.h"

// Item-related file
#include "item.h"
#include "dvd.h"
#include "movie_record.h"
#include "video_game.h"
#include "item_list.h"

// Other function
#include "io_func.h"
#include "UI.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{   
    if (argc != 3)
    {
        cerr << "Invalid number of arguments!" << endl;
        return -1;
    }

    // Create Linked-list
    Account_list* accList = new Account_list();
    Item_list* vlist = new Item_list();

    // Read file item and account
    read_file_item(argv[1], vlist);
    read_file_acc(argv[2], accList, vlist);

    // Application processing...
    video_store(accList, vlist);

    // Write file item and account
    vlist->write_file(argv[1]);
    accList->write_file(argv[2]);

    // Deconstructor 
    delete accList;
    delete vlist;

    return 0;
}
