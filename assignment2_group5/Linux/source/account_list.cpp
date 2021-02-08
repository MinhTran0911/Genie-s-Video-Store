#include "account_list.h"

// getter for head node
Account* Account_list::get_head()
{
    return head;
}

// constructor
Account_list::Account_list()
{
    head = NULL;
};

// parameterized constructor
Account_list::Account_list(Account* head)
{
    this->head = head;
};

// destructor
Account_list::~Account_list()
{
    Account* current = this->get_head(); // initialize current node
    while (current != NULL)  // traverse the account list
    {
        Account* next_acc = current->get_next(); // store next node
        delete current; // delete the current node
        current = next_acc; // move pointer to next node
    }
    head = NULL;
}

// insert account (sorted by id)
void Account_list::insert_acc(Account* new_acc)
{
    // case 1 - empty list 
    if (head == NULL)
    {
        head = new_acc; // set head to new account
        return;
    }
    else
    {
        Account* current = this->get_head(); // initialize current and previous node
        Account* pre = current;
        while (current != NULL) // traverse list to find insert location
        {
            if (current->get_id() >= new_acc->get_id()) // if the insert location is found
            {
                // case 2 - insert at head (list not empty)
                if (current == this->get_head())
                {
                    new_acc->set_next(current); // set next of new account to head (current)
                    head = new_acc; // set head to new account
                }
                // case 3 - insert at intermediate location
                else
                {
                    new_acc->set_next(current); // set next of new account to current node
                    pre->set_next(new_acc); // set next of previous node to new account
                };
                return;
            }
            // move pointers one position ahead
            pre = current;
            current = current->get_next();
        }
        // case 4 - insert at tail (current = NULL)
        pre->set_next(new_acc); // set next of previous node to new account
        return;
    }
}

// insert account (sorted by name)
void Account_list::insert_acc_by_name(Account* new_acc)
{
    // case 1 - empty list 
    if (head == NULL)
    {
        head = new_acc; // set head to new account
        return;
    }
    else
    {
        Account* current = this->get_head(); // initialize current and previous node
        Account* pre = current;
        while (current != NULL) // traverse list to find insert location
        {
            if (current->get_name() >= new_acc->get_name()) // if the insert location is found
            {
                // case 2 - insert at head (list not empty)
                if (current == this->get_head())
                {
                    new_acc->set_next(current); // set next of new account to head (current)
                    head = new_acc; // set head to new account
                }
                // case 3 - insert at intermediate location
                else
                {
                    new_acc->set_next(current); // set next of new account to current node
                    pre->set_next(new_acc); // set next of previous node to new account
                }
                return;
            }
            // move pointer one position ahead
            pre = current;
            current = current->get_next();
        }
        // case 4 - insert at tail (current = NULL)
        pre->set_next(new_acc); // set next of previous node to new account
        return;
    }
}

// update account (by id)
void Account_list::update_acc(Account* update_acc)
{
    string id = update_acc->get_id(); // get the id of the update_acc
    Account* current = this->get_head(); // initialize current node = head
    while (current != NULL) // traverse the list to find update node
    {
        if (current->get_id() == id.c_str()) // if id of current == id of the update_acc
        {
            current->set_name(update_acc->get_name()); // update the info correspondingly based on the update_acc
            current->set_address(update_acc->get_address());
            current->set_phone(update_acc->get_phone());
            delete update_acc; // delete the redundant account
            return;
        }
        current = current->get_next(); // move pointer one position ahead
    }
    cerr << "Cannot find any account with ID: " << id << endl; // if cannot find account with that id,  print error
    delete update_acc; // delete the redundant account
    return;
};

// delete account (by id)
void Account_list::delete_acc(string id)
{
    // case 1 - empty list 
    if (head == NULL)
    {
        cerr << "Don't have any account yet." << endl; // if the list is empty, print error
        return;
    }
    else
    {
        // initialize current and previous node
        Account* current = this->get_head();
        Account* pre = current;
        while (current != NULL) // traverse list to find delete node
        {
            if (current->get_id() == id.c_str()) // if delete node is found
            {
                // case 2 - delete head node 
                if (current == this->get_head())
                {
                    head = head->get_next(); // set head to next node 
                }
                // case 3 - delete node after head
                else
                {
                    pre->set_next(current->get_next()); // set next of previous node to next of current 
                }
                delete current; // delete the current node
                return;
            }
            // move pointers one position ahead
            pre = current; 
            current = current->get_next();
        }
        cout << "Cannot find any account with ID: " << id << endl; // if cannot find account with that id,  print error
        return;
    }
};

// delete an item in rental lists (by id)
void Account_list::delete_rental_item(string id)
{
    Account* current = this->get_head(); // initialize current node
    // traverse the list of account to delete all matching item in rental lists
    while (current != NULL)
    {
        current->get_rental_list()->delete_item(id); // delete item with matching id in rental list 
        current = current->get_next(); // move pointers one position ahead
    }
    return;
};

// promoting account (by id)
void Account_list::promote_acc_by_id(string id)
{
    // initialize current and previous node
    Account* current = this->get_head();
    Account* pre = current;
    // traverse the list of account 
    while (current != NULL) 
    {
        if (current->get_id() == id.c_str()) // if found account with matching id
        {
            if (current->get_acctype().compare("Guest") == 0) // if the account is a guest acc
            {
                if (current->get_count_borrow() >= 3 && current->get_count_return() >= 3) // if the account is eligible to promote
                {
                    Regular_account* new_acc = new Regular_account(*current); // copy info of current to new regular account
                    // case 1 - promote the account at head 
                    if (current == this->get_head()) 
                    {
                        head = new_acc; // set head to new account  
                    }
                    // case 2 - promote the account at other position
                    else
                    {
                        pre->set_next(new_acc); // set next of previous node to new account
                    };
                    delete current; // delete the redundant account
                    cout << "Successfully promoting account with ID " << id << " to Regular account." << endl; // print successful message
                    return;
                }
                cerr << "Account " << id << " is not eligible to promote." << endl; // if the account is not eligible, print error
                return;
            }
            else if (current->get_acctype().compare("Regular") == 0) // if the account is a regular acc
            {
                if (current->get_count_borrow() >= 3 && current->get_count_return() >= 3) // if the account is eligible to promote
                {
                    Vip_account* new_acc = new Vip_account(*current); // copy info of current to new vip account
                    // case 1 - promote the account at head 
                    if (current == this->get_head())
                    {
                        head = new_acc; // set head to new account  
                    }
                    // case 2 - promote the account at other position
                    else
                    {
                        pre->set_next(new_acc); // set next of previous node to new account
                    };
                    delete current; // delete the redundant account 
                    cout << "Successfully promoting account with ID " << id << " to VIP account." << endl; // print successful message
                    return;
                }
                cerr << "Account " << id << " is not eligible to promote." << endl; // if the account is not eligible, print error
                return;
            }
            else // if the account is a VIP acc, print error
            {
                cerr << "Account " << id << " is aldready a VIP account." << endl; 
                return;
            }
        }
        // move pointers one position ahead
        pre = current;
        current = current->get_next();
    }
    cerr << "Cannot find any account with ID: " << id << endl; // if cannot find account with that id,  print error
    return;
}

// check account id exist
bool Account_list::exist_account_id(string id)
{
    Account* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of account 
    {
        if (current->get_id() == id.c_str())  // if found account with matching id
        {
            return true; // return true
        }
        current = current->get_next(); // move pointer one position ahead
    }
    return false; // return false
}

// search account (by id)
Account* Account_list::search_by_id(string id)
{
    Account* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of account 
    {
        if (current->get_id() == id.c_str())  // if found account with matching id
        {
            return current; // return account
        }
        current = current->get_next(); // move pointer one position ahead
    }
    cerr << "Cannot find any account with ID: " << id << endl; // if cannot find account with that id,  print error
    return NULL; // return null
}

// search account (by level)
void Account_list::search_by_level(string level)
{
    int found = 0;
    Account* current = this->get_head(); // initialize current node
    if (level != "Guest" && level != "Regular" && level != "VIP") // if invalid input
    {
        cerr << "Please enter a valid level: Guest, Regular or VIP." << endl; // print error
        return;
    }
    while (current != NULL) // traverse the list of account 
    {
        if (current->get_acctype() == level.c_str()) // if found account with matching level
        {
            found += 1; // increase number of found result
            current->print(); // print the account
        }        
        current = current->get_next(); // move pointer one position ahead
    }
    if (found == 0) // if cannot find any account with that level,  print error
        cerr << "Cannot find any account with level: " << level << endl;
    return;
}

// search account (by name)
void Account_list::search_by_name(string name)
{
    int found = 0;
    Account* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of account
    {
        if (current->get_name() == name.c_str()) // if found account with matching name
        {
            found += 1; // increase number of found result
            current->print(); // print the account
        }
        current = current->get_next();  // move pointer one position ahead
    }
    if (found == 0) // if cannot find any account with that name,  print error
        cerr << "Cannot find any account with name: " << name << endl;
    return;
}

// print account list (sorted by id)
void Account_list::print_list()
{
    Account* current = this->get_head(); // initialize current node
    if (head == NULL) // if the list is NULL, print error 
    {
        cerr << "There is no accounts to show." << endl;
        return;
    }       
    while (current != NULL) // traverse the list of account
    {
        current->print(); // print the account
        current = current->get_next(); // move pointer one position ahead
    }
    cout << endl;
    return;
}

// print account list (sorted by name)
void Account_list::print_list_sort_by_name()
{
    Account_list* new_list = new Account_list(); // create a dummy list 
    Account* current = this->get_head(); // initialize current and temp node
    Account* temp = NULL;
    while (current != NULL) // traverse the list of account
    {
        temp = new Account(*current); // create dummy account from the current node
        new_list->insert_acc_by_name(temp); // insert acc to new_list (sorted by name)
        current = current->get_next(); // move pointer one position ahead
    }
    new_list->print_list(); // print dummy list
    delete new_list; // delete dummy list 
    return;
}

// write account list to text file 
void Account_list::write_file(string file_acc)
{
    ofstream accfile(file_acc, ios::trunc); // open file for writing in truncate mode
    if (accfile.is_open()) // if file can open
    {
        Account* current = this->get_head(); // initialize current node
        while (current != NULL) // traverse the list of account
        {
            accfile << *current; // write current account 
            current = current->get_next(); // move pointer one position ahead
        }
        accfile.close(); // close file
        return;
    }
    else cerr << "Unable to open file." << endl; // if cannot open file, print error
    return;
}

// check an item in rental lists (by id)
bool Account_list::exist_rental_item(string id)
{
    int found = 0;
    Account* current = this->get_head(); // initialize current node
    // traverse the list of account to find matching item in rental lists
    while (current != NULL)
    {
        if (current->get_rental_list()->already_rented(id))
        {
            found += 1;
        }
        current = current->get_next(); // move pointers one position ahead
    }
    if (found == 0) return false; // if cannot found return false
    return true; // if found return true
}



