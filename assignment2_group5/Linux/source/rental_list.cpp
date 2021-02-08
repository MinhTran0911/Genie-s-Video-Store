#include "rental_list.h"

// getter for head node
Rental_item* Rental_list::get_head() 
{ 
    return this->head; 
}

// constructor 
Rental_list::Rental_list()
{
    head = NULL;
}

// parameterized constructor
Rental_list::Rental_list(Rental_item* head) 
{
    this->head = head;
}

// destructor
Rental_list::~Rental_list()
{
    Rental_item* current = this->get_head();
    while (current != NULL)
    {
        Rental_item* next_item = current->get_next();
        delete current;
        current = next_item;
    }
    head = NULL;
}

// insert new item to list 
void Rental_list::append_list(string id)
{
    Rental_item* new_item = new Rental_item(id); // create rental_item node
    // case 1: empty list 
    if (head == NULL)
    {
        head = new_item; // set head to new item
        return;
    }
    else
    {
        Rental_item* current = this->get_head(); // initialize current and previous node
        Rental_item* pre = current;
        while (current != NULL) // traverse list to find insert location
        {
            if (current->get_item_id() >= new_item->get_item_id()) // if the insert location is found
            {
                // case 2 - insert at head (list not empty)
                if (current == this->get_head())
                {
                    new_item->set_next(current); // set next of new item to head (current)
                    head = new_item; // set head to new item
                }
                // case 3 - insert at intermediate location
                else
                {
                    new_item->set_next(current); // set next of new item to current node
                    pre->set_next(new_item); // set next of previous node to new item
                };
                return;
            }
            // move pointers one position ahead
            pre = current; 
            current = current->get_next();
        }
        // case 4 - insert at tail 
        pre->set_next(new_item); // set next of previous node to new item
        return;
    }
}

void Rental_list::delete_item(string id)
{
    // case 1 - empty list 
    if (head == NULL)
    {
        return; // if the list is empty, return
    }
    else
    {
        // initialize current and previous node
        Rental_item* current = this->get_head();
        Rental_item* pre = current;
        while (current != NULL) // traverse list to find delete node 
        {
            if (current->get_item_id() == id.c_str()) // if delete node is found
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
                };
                delete current; // delete the current node
                return;
            };
            // move pointers one position ahead
            pre = current;
            current = current->get_next();
        }
        return; // if cannot find item with that id, return
    }
}

// print list (sorted by id)
void Rental_list::print_list()
{
    Rental_item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list 
    {
        cout << *current; // print rental_item id
        current = current->get_next(); // move pointer ahead
    }
    cout << endl;
    return;
}

// overloading operator << (used for write rental list to file)
ostream& operator<<(ostream& out, Rental_list& obj)
{
    Rental_item* current = obj.get_head(); // initialize current node
    while (current != NULL) // traverse the list 
    {
        out << *current; // add current item to out stream 
        current = current->get_next(); // move pointer ahead
    }
    return out;
}

// copy list of item to other list (used for promoting)
void Rental_list::copy_list_to(Rental_list& list)
{
    Rental_item* current = this->get_head(); // initialize current node
    // case 1 - list is empty 
    if (head == NULL) 
    {
        list.head = NULL; // set new list head null
        return;
    }
    // case 2 - list is not empty
    else
    {
        while (current != NULL) // traverse the list
        {
            list.append_list(current->get_item_id()); // add item in this list to new list 
            current = current->get_next(); // move pointer ahead
        }
        return;
    }   
}

bool Rental_list::already_rented(string id)
{
    Rental_item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list 
    {
        if (current->get_item_id() == id.c_str())  // if found account with matching id
        {
            return true; // return true
        }
        current = current->get_next(); // move pointer ahead
    }
    return false;
}