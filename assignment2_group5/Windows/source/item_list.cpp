#include "item_list.h"
// getter for head node
Item* Item_list::get_head()
{
    return head;
}

// constructor
Item_list::Item_list()
{
    head = NULL;
}

// parameterized constructor
Item_list::Item_list(Item* head)
{
    this->head = head;
}

// destructor
Item_list::~Item_list()
{
    Item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the item list
    {
        Item* next_item = current->get_next(); // store next node
        delete current; // delete the current node
        current = next_item; // move pointer to next node
    }
    head = NULL;
}

// insert item (sorted by id)
void Item_list::insert_item(Item* new_item)
{
    // case 1: empty list 
    if (head == NULL)
    {
        head = new_item;  // set head to new item
        return;
    }
    else
    {
        Item* current = this->get_head(); // initialize current and previous node
        Item* pre = current;
        while (current != NULL) // traverse list to find insert location
        {
            if (current->get_id() >= new_item->get_id()) // if the insert location is found
            {
                // case 2 - insert at head (list not empty)
                if (current == this->get_head())
                {
                    new_item->set_next(current);  // set next of new item to head (current)
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
        // case 4 - insert at tail (current = NULL)
        pre->set_next(new_item); // set next of previous node to new item
        return;
    }
}

// insert item (sorted by title)
void Item_list::insert_item_by_title(Item* new_item)
{
    // case 1: empty list 
    if (head == NULL)
    {
        head = new_item;  // set head to new item
        return;
    }
    else
    {
        Item* current = this->get_head(); // initialize current and previous node
        Item* pre = current;
        while (current != NULL) // traverse list to find insert location
        {
            if (current->get_title() >= new_item->get_title()) // if the insert location is found
            {
                // case 2 - insert at head (list not empty)
                if (current == this->get_head())
                {
                    new_item->set_next(current);  // set next of new item to head (current)
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
        // case 4 - insert at tail (current = NULL)
        pre->set_next(new_item); // set next of previous node to new item
        return;
    }
}

// update item (by id)
void Item_list::update_item(Item* update_item)
{
    string id = update_item->get_id(); // get the id of the update_item
    Item* current = this->get_head();// initialize current node
    while (current != NULL)// traverse the liat to find update node
    {
        if (current->get_id() == id.c_str()) // if id of current =  id of the update_item
        {
            current->set_all(update_item); // update the info correspondingly based on the update_item
            delete update_item; // delete the redundant item
            return;
        };
        current = current->get_next(); // current point to next node
    }
    cerr << "Cannot find item with ID: " << id << endl; // if cannot find item with that id,  print error
    delete update_item; // delete the redundant item
    return;
}

// delete item (by id)
void Item_list::delete_item(string id)
{
    // case 1 - empty list 
    if (head == NULL)
    {
        cerr << "Don't have any items yet." << endl; // if the list is empty, print error
        return;
    }
    else
    {
        Item* current = this->get_head(); // initialize current and previous node
        Item* pre = current;
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
                };
                delete current; // delete the current node
                return;
            }
            // move pointers one position ahead
            pre = current;
            current = current->get_next();
        }
        cerr << "Cannot find item with ID: " << id << endl; // if cannot find item with that id,  print error
        return;
    }
}

// check if item id exists
bool Item_list::exist_item_id(string id)
{
    Item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of item
    {
        if (current->get_id() == id.c_str()) // if found item with matching id
        {
            return true; // return true
        }
        current = current->get_next(); // move pointer one position ahead
    }
    return false; // else return false
}

// search item (by id)
Item* Item_list::search_by_id(string id)
{
    Item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of item
    {
        if (current->get_id() == id.c_str()) // if found item with matching id
        {
            return current; // return item
        }
        current = current->get_next(); // move pointer one position ahead
    }
    cerr << "Cannot find item with ID: " << id << endl; // if cannot find item with that id,  print error
    return NULL; // return NULL
}



// search item (by title)
void Item_list::search_by_title(string title)
{
    int found = 0;
    Item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of item
    {
        if (current->get_title() == title.c_str()) // if found item with matching title
        {
            found += 1; // increase number of found result
            current->print();  // print the item
        }
        current = current->get_next(); // move pointer one position ahead
    }
    if (found == 0)
        cerr << "Cannot find any item with title: " << title << endl; // if cannot find item with that title,  print error
    return;
}

// show out of stock item
void Item_list::show_out_of_stock()
{
    int found = 0;
    Item* current = this->get_head(); // initialize current node
    while (current != NULL) // traverse the list of item
    {
        if (current->get_copies_num() == 0) // if found item with number of copies = 0
        {
            found += 1; // increase number of found result
            current->print();  // print the item
        }
        current = current->get_next(); // move pointer one position ahead
    }
    if (found == 0)
        cerr << "All items are in stock." << endl; // if all item are in stock,  print error
    return;
}

// print item list (sorted by id)
void Item_list::print_list()
{
    Item* current = this->get_head(); // initialize current node
    if (head == NULL) // if the list is NULL, print error 
    {
        cerr << "There is no items to show." << endl;
        return;
    }
    while (current != NULL) // traverse the list of item
    {
        current->print(); // print the item
        current = current->get_next(); // move pointer one position ahead
    }
    cout << endl;
    return;
}

// print item list (sorted by title)
void Item_list::print_list_sort_by_title()
{
    Item_list* new_list = new Item_list(); // create a dummy list 
    Item* current = this->get_head(); // initialize current and temp node
    Item* temp = NULL;
    while (current != NULL) // traverse the list of item
    {
        temp = new Item(*current); // create dummy item from the current node
        new_list->insert_item_by_title(temp); // insert item to new_list (sorted by title)
        current = current->get_next(); // move pointer one position ahead
    }
    new_list->print_list(); // print dummy list
    delete new_list; // delete dummy list 
    return;
}

// write item list to text file 
void Item_list::write_file(string file_item)
{
    ofstream itemfile(file_item, ios::trunc); // open file for writing in truncate mode
    if (itemfile.is_open()) // if file can open
    {
        Item* current = this->get_head(); // initialize current node
        while (current != NULL) // traverse the list of item
        {
            itemfile << *current;  // write current item
            current = current->get_next(); // move pointer one position ahead
        }
        itemfile.close();  // close file
        return;
    }
    else cerr << "Unable to open file" << endl;  // if cannot open file, print error
    return;
}

