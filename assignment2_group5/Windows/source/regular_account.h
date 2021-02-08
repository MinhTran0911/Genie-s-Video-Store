#ifndef REGULAR_ACCOUNT_H
#define REGULAR_ACCOUNT_H

#include "account.h"
class Regular_account :
    public Account
{
private:
public:
    // constructor
    Regular_account();
    Regular_account(string id, string name, string address, string phone);
    Regular_account(string id, string name, string address, string phone, int num_rented, string acc_type);
    // copy constructor (for promoting)
    Regular_account(Account& acc);
    // destructor
    ~Regular_account();
};

#endif