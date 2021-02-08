#ifndef VIP_ACCOUNT_H
#define VIP_ACCOUNT_H

#include "account.h"
class Vip_account :
    public Account
{
private:
    // initialize variable to store reward point
    int reward_point;
public:
    // constructor
    Vip_account();
    Vip_account(string id, string name, string address, string phone);
    Vip_account(string id, string name, string address, string phone, int num_rented, string acc_type);
    
    // copy constructor for promoting
    Vip_account(Account& acc);
    // destrcutor
    ~Vip_account();
    // overriding add number of rented item
    void add_numrented();
    // overriding borrowing function
    void borrowing(Item* item);
};

#endif