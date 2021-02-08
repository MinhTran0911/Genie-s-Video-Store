#ifndef GUEST_ACCOUNT_H
#define GUEST_ACCOUNT_H

#include "account.h"

#define MAXRENT 2

class Guest_account :
    public Account
{
private:
public:
    // constructor
    Guest_account();
    Guest_account(string id, string name, string address, string phone);
    Guest_account(string id, string name, string address, string phone, int num_rented, string acc_type);
    
    // destructor
    ~Guest_account();

    // bool check if account reach the max rental
    bool can_borrow();

    // overriding borrowing function
    void borrowing(Item* item);
};

#endif