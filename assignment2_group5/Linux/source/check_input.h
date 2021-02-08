#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int input_type(string input);

bool valid_item_ID(string id);
bool valid_account_ID(string id);

bool valid_item_type(string type);
bool valid_acc_type(string type);

bool valid_phone(string phone);
bool valid_fee(string fee);
bool valid_copies(string num);

#endif