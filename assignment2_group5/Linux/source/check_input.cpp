#include "check_input.h"

// This function check for user input and return the corresponding value for menus
int input_type(string input)
{   
    // If input is equal to 1-10, return the corresponding integer
    if (input.compare("1") == 0) return 1;
    else if (input.compare("2") == 0) return 2;
    else if (input.compare("3") == 0) return 3;
    else if (input.compare("4") == 0) return 4;
    else if (input.compare("5") == 0) return 5;
    else if (input.compare("6") == 0) return 6;
    else if (input.compare("7") == 0) return 7;
    else if (input.compare("8") == 0) return 8;
    else if (input.compare("9") == 0) return 9;
    else if (input.compare("10") == 0) return 10;
    // If input is equal to the word Exit, return 0
    else if (input.compare("Exit") == 0 || input.compare("exit") == 0) return 0;
    else return -1; // Otherwise, return -1, indicate invalid input
}

// This function check an item ID validity
bool valid_item_ID(string ID)
{
    // return false if ID length is not 9 characters
    if (ID.length() != 9) return false;

    // return false if string first character is not I
    if (ID.at(0) != 'I') return false;

    // return false if the unique code (next 3 character after I) is not a number
    for (int i = 1; i < 4; i++)
    {
        if (ID.at(i) < '0'  || ID.at(i) > '9') return false;
    }

    // return false if unique code and year is not seperated by a hyphen 
    if (ID.at(4) != '-') return false;

    //  return false if the year (next 4 characters after hyphen) is not a number
    for (int i = 5; i < 9; i++)
    {
        if (ID.at(i) < '0' || ID.at(i) > '9') return false;
    }

    // else this is a valid ID
    return true;
}

// This function check an account ID validity
bool valid_account_ID(string ID)
{
    // return false if ID length is not 4
    if (ID.length() != 4) return false;
    // return false if the first character is not C
    if (ID.at(0) != 'C') return false; 
    //  return false if the unique code (next 3 character) is not number
    for (int i = 1; i < 4; i++)
    {
        if (ID.at(i) < '0' || ID.at(i) > '9') return false;  
    }
    // else this is a valid ID
    return true;
}

// This function check an item type validity
bool valid_item_type(string type)
{   
    // If item type is not DVD, Record, or Game, then the type is invalid
    if (type.compare("DVD") != 0)
    {
        if (type.compare("Record") != 0)
        {
            if (type.compare("Game") != 0) return false;
        }
    }

    return true;
}

// This function check an account type validity
bool valid_acc_type(string type)
{   
    // Account type can only be Guest, Regular, or VIP
    if (type.compare("Guest") != 0)
    {
        if (type.compare("Regular") != 0)
        {
            if (type.compare("VIP") != 0) return false;
        }
    }
    return true;
}

// This function check a phone number validity
bool valid_phone(string phone)
{   
    // If the phone contains anything that is not a number, return false
    for (int i = 0; i < phone.length(); i++)
    {
        if (phone.at(i) < '0' || phone.at(i) > '9') return false;
    }

    return true;
}

// This function check a rental fee validity
bool valid_fee(string fee)
{   

    int dot_count = 0; // Variable use to count the number of dot in the number

    for (int i = 0; i < fee.length(); i++)
    {   
        // If any character in the fee is not a number or a dot, return false
        if ((fee.at(i) < '0' || fee.at(i) > '9') && fee.at(i) != '.') return false;
        else if (fee.at(i) == '.')
        {
            dot_count += 1;
            if (dot_count > 1) return false; // If there are more than 1 dot in the number, return false
        }
    }
    return true;
}

// This function check a number of copies validity
bool valid_copies(string num)
{   
    // If the number of copies is not a valid integer, return false
    for (int i = 0; i < num.length(); i++)
    {
        if (num.at(i) < '0' || num.at(i) > '9') return false;
    }

    return true;
}
