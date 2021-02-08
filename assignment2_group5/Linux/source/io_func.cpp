#include "io_func.h"

int count(string s, char c)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == c)
            res++;
    return res;
}

// load item from reading line
void load_item(string line, Item_list* vlist)
{
    // initialize variables to store info of item
    string id;
    string title;
    string type;
    string loan_type;
    int copies_num;
    double rental_fee;
    string genre;
    // number of comma in 1 line
    int count_comma = count(line, ',');

    // split line string by comma to get info
    // get id 
    int prev = 0; // initialize previous from the beginning 
    int pos = line.find(",", prev); // position of 1st comma
    string temp = line.substr(prev, pos - prev); // get substring 
    id = temp.c_str(); // get id     
    if (!valid_item_ID(id)) // if id is invalid, return
        return;

    // get title 
    prev = pos + 1;
    pos = line.find(",", prev); // position of 2nd comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    title = temp.c_str(); // get title 

    // get type
    prev = pos + 1;
    pos = line.find(",", prev); // position of 3rd comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    type = temp.c_str(); // get type

    // get loan_type
    prev = pos + 1;
    pos = line.find(",", prev); // position of 4th comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    loan_type = temp.c_str(); // get loan_type

    // get number of copies 
    prev = pos + 1;
    pos = line.find(",", prev); // position of 5th comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    copies_num = atoi(temp.c_str()); // get copies_num

    if (count_comma == 6) // if line have 6 commas, it has 'genre' field.
    {
        // get rental fee
        char* endptr;
        prev = pos + 1;
        pos = line.find(",", prev); // position of 6th comma
        temp = line.substr(prev, pos - prev); // get substring between 2 commas 
        rental_fee = strtod(temp.c_str(), &endptr); // get rental_fee (return 0 when temp is not number)
        if (rental_fee == 0) // if rental_fee = 0, return
            return;

        // get genre
        prev = pos + 1;
        temp = line.substr(prev, line.length()); // get the last substring 
        genre = temp.c_str(); // get genre

        // check type, create orresponding item and insert to item list
        if (type.compare("DVD") == 0)
        {
            DVD* new_item = new DVD(id, title, type, loan_type, copies_num, rental_fee, genre); 
            vlist->insert_item(new_item);
        }
        else if (type.compare("Record") == 0)
        {
            Movie_record* new_item = new Movie_record(id, title, type, loan_type, copies_num, rental_fee, genre);
            vlist->insert_item(new_item);
        }
        else return;
    }
    else if (count_comma == 5) // if line have 6 commas, it doesn't has 'genre' field.
    {
        char* endptr;
        prev = pos + 1;
        temp = line.substr(prev, line.length()); // get the last substring 
        rental_fee = strtod(temp.c_str(), &endptr); // get rental_fee (return 0 when temp is not number)
        if (rental_fee == 0) // if rental_fee = 0, return
            return;

        // check type and insert to corresponding item
        if (type.compare("Game") == 0)
        {
            Video_game* new_item = new Video_game(id, title, type, loan_type, copies_num, rental_fee);
            vlist->insert_item(new_item);
        }
        else return;
    }
    return;
}

// load account from reading line 
string load_acc(string line, Account_list* acclist)
{
    // initialize variables to store info of account 
    string id;
    string name;
    string address;
    string phone;
    int num_rented = 0;
    string acc_type;

    // split line string by comma to get info
    // get id
    int prev = 0; // initialize previous from the beginning 
    int pos = line.find(",", prev); // position of 1st comma
    string temp = line.substr(prev, pos - prev); // get substring
    id = temp.c_str(); // get id
    if (!valid_account_ID(id)) // if id is invalid, return empty string
        return "";

    // get name
    prev = pos + 1;
    pos = line.find(",", prev); // position of 2nd comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    name = temp.c_str(); // get name

    // get address
    prev = pos + 1;
    pos = line.find(",", prev); // position of 3rd comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    address = temp.c_str(); // get address

    // get phone
    prev = pos + 1;
    pos = line.find(",", prev); // position of 4th comma
    temp = line.substr(prev, pos - prev); // get substring between 2 commas 
    phone = temp.c_str(); // get phone

    // skip number of rented item 
    prev = pos + 1;
    pos = line.find(",", prev); // position of 5th comma

    // get account type
    prev = pos + 1; // position of 6th comma
    temp = line.substr(prev, line.length()); // get substring between 2 commas 
    acc_type = temp.c_str(); // get acc_type
   
    // check account type, create corresponding account and insert to account list
    if (acc_type.compare("Guest") == 0) 
    {
        Account* new_acc = new Guest_account(id, name, address, phone, 0, acc_type);
        acclist->insert_acc(new_acc);
        return id; // return id when success 
    }
    else if (acc_type.compare("Regular") == 0)
    {
        Account* new_acc = new Regular_account(id, name, address, phone, 0, acc_type);
        acclist->insert_acc(new_acc);
        return id; // return id when success 
    }
    else if (acc_type.compare("VIP") == 0)
    {
        Account* new_acc = new Vip_account(id, name, address, phone, 0, acc_type);
        acclist->insert_acc(new_acc);
        return id; // return id when success 
    }
    else return ""; 
}

// read file item 
void read_file_item(char* file_name, Item_list* vlist)
{   
    string line;  // initialize string to store line
    ifstream myfile; // open file in read mode 
    myfile.open(file_name);
    if (!myfile) // if file cannot open 
    {
        cerr << "Cannot open " << file_name << "!" << endl;
        return;
    }

    while (getline(myfile, line)) // get each line 
    {
        if (line[0] == 'I') // if line start with I, pass line to load item fucntion 
            load_item(line, vlist);
    }
    myfile.close(); // close file 
    return;
}

void read_file_acc(char* file_name, Account_list* acclist, Item_list* vlist)
{   
    string id; // initialize string to store id
    string line; // initialize string to store line
    ifstream myfile; // open file in read mode 
    myfile.open(file_name);
    if (!myfile) // if file cannot open
    {
        cerr << "Cannot open " << file_name << "!" << endl;
        return;
    }
    while (getline(myfile, line)) // get each line 
    {
        if (line[0] == 'C') // if line start with C, pass line to load item fucntion 
            id = load_acc(line, acclist); // get id when successfully insert 
        if (line[0] == 'I') // if line start with I, add to rental list of account 
        {
            if (id != "") // if insert account in previous line successfully 
            {
                if (valid_item_ID(line)) // if the id of item is valid 
                {
                    if (vlist->search_by_id(line) != NULL) // if item list has this item 
                    {
                        acclist->search_by_id(id)->get_rental_list()->append_list(line); // add to rental list of account 
                        acclist->search_by_id(id)->add_numrented(); // inscrease corresponding number of rented
                    }
                    else continue;
                }
                else continue;
            }
            else continue;
        }
    }
    myfile.close(); // close file 
    return;
}