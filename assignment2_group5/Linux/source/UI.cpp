#include "UI.h"

// This function runs the video store
void video_store(Account_list* acclist, Item_list* vlist)
{
	string input;

	// Program runs infinitely until user enter "Exit" or "exit"
	while (true)
	{	
		main_menu(); // Display main menu
		cin >> input;
		cin.ignore();

		switch (input_type(input)) // Check user input and open corresponding menus
		{
		case 0: // Exit program when enter "Exit" or "exit"
			clear_screen(); 
			disp_group_info(); // Display group information upon quitting
			return;
		case 1:
			clear_screen();
			aud_item(vlist, acclist); // Open add, update, delete item menu
			break;
		case 2:
			clear_screen();
			aud_customer(acclist); // Open add, update, delete customer menu
			break;
		case 3:
			clear_screen();
			promote(acclist); // Open promote customer menu
			break;
		case 4:
			clear_screen();
			renting(acclist, vlist); // Open rent menu
			break;
		case 5:
			clear_screen();
			returning(acclist, vlist); // Open return menu
			break;
		case 6:
			clear_screen();
			display_all(vlist); // Open options to display all items
			break;
		case 7:
			clear_screen();
			vlist->show_out_of_stock(); // Show out-of-stock items
			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 8:
			clear_screen();
			display_all(acclist); // Open options to display all accounts
			break;
		case 9:
			clear_screen();
			disp_group_menu(acclist); // Open customer groups menu
			break;
		case 10:
			clear_screen();
			search_menu(acclist, vlist); // Open search menu
			break;
		default: // If input is incorrect
			cerr << "Invalid input!" << endl; // Display error message
		}
	clear_screen();
	}
}

// This function show the main menu
void main_menu()
{	
	cout << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Welcome to Genie's video store" << endl;
	cout << "1.  Add a new item, update or delete an existing item" << endl;
	cout << "2.  Add a new customer, update an existing customer" << endl;
	cout << "3.  Promote an existing customer" << endl;
	cout << "4.  Rent an item" << endl;
	cout << "5.  Return an item" << endl;
	cout << "6.  Display all items" << endl;
	cout << "7.  Display out-of-stock items" << endl;
	cout << "8.  Display all customers" << endl;
	cout << "9.  Display group of customers" << endl;
	cout << "10. Search items or customers" << endl;
	cout << "Exit." << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;
}

// This function shows add, update, delete items menu
void aud_item(Item_list* list, Account_list* acclist)
{
	string input;
	bool valid = true;

	cout << "Add, update, delete Items" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1.  Add a new item" << endl;
	cout << "2.  Update an existing item" << endl;
	cout << "3.  Delete an existing item" << endl;
	cout << "4.  Update number in stock of an item" << endl;
	cout << "5.  Back to previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;

	do
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input)) // Check for user input and open corresponding menus
		{
		case 1:
			clear_screen();
			add_item(list);
			break;
		case 2:
			clear_screen();
			update_item(list);
			break;
		case 3:
			clear_screen();
			delete_item(list, acclist);
			break;
		case 4:
			clear_screen();
			update_stock(list);
			break;
		case 5:
			clear_screen();
			return;
		default:
			valid = false;
			cerr << "Invalid input!" << endl; // If input is invalid, ask user to re-enter
		}
	} while (!valid);
}

// This function add one item to the store
void add_item(Item_list* list)
{
	string id;
	string title;
	string type;
	string loan_type;
	int copies_num = 0;
	double rental_fee = 0;
	string genre;
	string input;
	bool valid = true;
	do // Ask for new item ID until the new ID is valid
	{
		cout << "Enter a new item ID: ";
		cin >> id;
		cin.ignore();

		if (!valid_item_ID(id)) // Show error when ID is not valid
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (list->exist_item_id(id)) // Show error when ID already exists
		{
			cerr << "This ID already exists! Please enter another ID." << endl;
		}
	} while (!valid_item_ID(id) || list->exist_item_id(id)); 

	cout << "Choose 1 item type below:" << endl;
	cout << "1. Record" << endl;
	cout << "2. DVD" << endl;
	cout << "3. Game" << endl;
	do // Choose the type of item
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input))
		{
		case 1:
			type = "Record";
			break;
		case 2:
			type = "DVD";
			break;
		case 3:
			type = "Game";
			break;
		default: // If input is invalid, ask user to re-enter
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);

	cout << "Enter a new item title: " << endl;
	getline(cin, title);

	cout << "Choose item loan type:" << endl;
	cout << "1. 2-day loan" << endl;
	cout << "2. 1-week loan" << endl;
	do // Choose the type of loan
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input))
		{
		case 1:
			loan_type = "2-day";
			break;
		case 2:
			loan_type = "1-week";
			break;
		default: // If input is invalid, ask user to re-enter
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);
	
	// Ask for number of copies held in stock
	cout << "Enter the number of copies held in stock:" << endl;
	do
	{
		cin >> input;
		cin.ignore();

		if (!valid_copies(input)) cerr << "Invalid number of copies! Please try again." << endl;
		else copies_num = stoi(input);

	} while (!valid_copies(input)); // If no. of copies is invalid, ask user to re-enter

	// Ask for rental fee
	cout << "Enter the rental fee for this item: " << endl;
	do
	{
		cin >> input;
		cin.ignore();

		if (!valid_fee(input)) cerr << "Invalid rental fee! Please try again." << endl;
		else rental_fee = stod(input);
	} while (!valid_fee(input)); // If rental fee is invalid, ask user to re-enter

	if (type.compare("Game") == 0)
	{	
		// Create new object and add to item list
		Video_game* new_item = new Video_game(id, title, type, loan_type, copies_num, rental_fee);
		list->insert_item(new_item);
		cout << "New item successfully added!" << endl;
		new_item->print();

		cout << "\nPress any key to continue..." << endl;
		cin.ignore();
		return;
	} 
	else // If item type is DVD or Movie Record, ask for genre
	{
		cout << "Choose item genre:" << endl;
		cout << "1. Action" << endl;
		cout << "2. Horror" << endl;
		cout << "3. Drama" << endl;
		cout << "4. Comedy" << endl;
		do
		{
			valid = true;
			cin >> input;
			cin.ignore();

			switch (input_type(input))
			{
			case 1:
				genre = "Action";
				break;
			case 2:
				genre = "Horror";
				break;
			case 3:
				genre = "Drama";
				break;
			case 4:
				genre = "Comedy";
				break;
			default:
				valid = false;
				cerr << "Invalid input! Please try again." << endl;
			}
		} while (!valid);
		if (type.compare("Record") == 0)
		{	// Create new object and add to item list
			Movie_record* new_item = new Movie_record(id, title, type, loan_type, (int)copies_num, (double)rental_fee, genre);
			list->insert_item(new_item);
			cout << "New item successfully added!" << endl;
			new_item->print();

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			return;
		}
		else if (type.compare("DVD") == 0)
		{	
			// Create new object and add to item list
			DVD* new_item = new DVD(id, title, type, loan_type, (int)copies_num, (double)rental_fee, genre);
			list->insert_item(new_item);
			cout << "New item successfully added!" << endl;
			new_item->print();

			cout << "\nPress any key to continue." << endl;
			cin.ignore();
			return;
		}
	}
}

// This function update an existing item
void update_item(Item_list* list)
{
	string id;
	string title;
	string loan_type;
	int copies_num = 0;
	double rental_fee = 0;
	string genre;
	string input;
	bool valid = true;
	do // Ask for an item ID to update
	{
		cout << "Enter an item ID to update: ";
		cin >> id;
		cin.ignore();

		if (!valid_item_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!list->exist_item_id(id))
		{
			cerr << "This item ID does not exist! Please try again." << endl;
		}
		// If ID is not valid, ask user to re-enter
	} while (!valid_item_ID(id) || !list->exist_item_id(id));

	cout << "Enter a new item title: "; // Ask for new title input
	getline(cin, title);

	// Ask user to choose new item loan type
	cout << "Choose item loan type:" << endl;
	cout << "1. 2-day loan" << endl;
	cout << "2. 1-week loan" << endl;
	do
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input))
		{
		case 1:
			loan_type = "2-day";
			break;
		case 2:
			loan_type = "1-week";
			break;
		default:
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);

	// Ask for the number of copies held in stock
	cout << "Enter the number of copies held in stock:" << endl;
	do
	{
		cin >> input;
		cin.ignore();

		if (!valid_copies(input)) cerr << "Invalid number of copies! Please try again." << endl;
		else copies_num = stoi(input);
	} while (!valid_copies(input)); // If the entered number is invalid, prompt to re-enter

	cout << "Enter the rental fee for this item: " << endl;
	do
	{
		cin >> input;
		cin.ignore();

		if (!valid_fee(input)) cerr << "Invalid rental fee! Please try again." << endl;
		else rental_fee = stod(input);
	} while (!valid_fee(input));
	genre = "";
	if (list->search_by_id(id)->get_type().compare("Game") != 0)
	{
		cout << "Choose item genre:" << endl;
		cout << "1. Action" << endl;
		cout << "2. Horror" << endl;
		cout << "3. Drama" << endl;
		cout << "4. Comedy" << endl;
		do
		{
			valid = true;
			cin >> input;
			cin.ignore();

			switch (input_type(input))
			{
			case 1:
				genre = "Action";
				break;
			case 2:
				genre = "Horror";
				break;
			case 3:
				genre = "Drama";
				break;
			case 4:
				genre = "Comedy";
				break;
			default:
				valid = false;
				cerr << "Invalid input! Please try again." << endl;
			}
		} while (!valid);
	}	
	Item* update_item = new Item(id, title, loan_type, (int)copies_num, (double)rental_fee, genre);
	list->update_item(update_item);
	cout << "Successfully updated!" << endl;
	list->search_by_id(id)->print();

	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function update an existing item available stock no.
void update_stock(Item_list* list)
{
	string id, input;
	int copies = 0;
	// Ask for ID to update the no. in stock until the ID is a valid one
	do
	{
		cout << "Enter an item ID to update: ";
		cin >> id;
		cin.ignore();

		if (!valid_item_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!list->exist_item_id(id))
		{
			cerr << "This item ID does not exist! Please try again." << endl;
		}
	} while (!valid_item_ID(id) || !list->exist_item_id(id));

	do
	{
		cout << "Enter the number of copies of " << id << " in stock:";
		cin >> input;
		cin.ignore();

		if (!valid_copies(input)) cerr << "Invalid number of copies! Please try again." << endl;
		else copies = stoi(input);
	} while (!valid_copies(input));

	list->search_by_id(id)->set_copies_num((int)copies);
	cout << "Successfully updated!" << endl;

	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function delete an existing item
void delete_item(Item_list* list, Account_list* acclist)
{
	string id;
	do
	{
		cout << "Enter an item ID to delete: ";
		cin >> id;
		if (!valid_item_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!list->exist_item_id(id))
		{
			cerr << "This item ID does not exist! Please try again." << endl;
		}
	} while (!valid_item_ID(id) || !list->exist_item_id(id));
	if (acclist->exist_rental_item(id))
	{
		cerr << "Cannot delete item with ID " << id << "! Someone is borrowing it currently." << endl;
		return;
	}
	list->delete_item(id);
	cout << "Successfully deleted!" << endl;

	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function show the add, update, delete customer menu
void aud_customer(Account_list* list)
{
	string input;
	bool valid = true;

	cout << "Add, update, delete Customers" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1.  Add a new customer" << endl;
	cout << "2.  Update an existing customer" << endl;
	cout << "3.  Back to previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;

	do
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input))
		{
		case 1:
			clear_screen();
			add_customer(list);
			break;
		case 2:
			clear_screen();
			update_customer(list);
			break;
		case 3:
			clear_screen();
			return;
		default:
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);
}

// This function operate the account promotion
void promote(Account_list* list)
{
	string id;
	// Ask user for a valid customer ID to promote
	do
	{
		cout << "Enter a customer ID to promote: ";
		cin >> id;
		cin.ignore();

		if (!valid_account_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!list->exist_account_id(id))
		{
			cerr << "This account ID does not exist! Please try again." << endl;
		}
	} while (!valid_account_ID(id) || !list->exist_account_id(id));
	list->promote_acc_by_id(id);

	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function add a new customer to the list
void add_customer(Account_list* list)
{
	string id, name, address, phone, acc_type, input;
	bool valid = true;
	// Ask for a valid and non-existent customer ID to add
	do
	{
		cout << "Enter a new customer ID: ";
		cin >> id;
		cin.ignore();

		if (!valid_account_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (list->exist_account_id(id))
		{
			cerr << "This ID already in used! Please enter another ID." << endl;
		}
	} while (!valid_account_ID(id) || list->exist_account_id(id));

	// Ask for the customer info
	cout << "Enter the customer's name:" << endl;
	getline(cin, name);

	cout << "Enter the customer's address:" << endl;
	getline(cin, address);
	
	do
	{
		cout << "Enter the customer's phone number:" << endl;
		cin >> phone;
		cin.ignore();
		if (!valid_phone(phone)) cerr << "Invalid phone number! Please try again." << endl;
	} while (!valid_phone(phone));
	
	cout << "Choose the customer account type:" << endl;
	cout << "1. Guest Account" << endl;
	cout << "2. Regular Account" << endl;
	cout << "3. VIP account" << endl;
	do
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input))
		{
		case 1:
			acc_type = "Guest";
			break;
		case 2:
			acc_type = "Regular";
			break;
		case 3:
			acc_type = "VIP";
			break;
		default:
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);

	// check account type, create corresponding account and insert to account list
	if (acc_type.compare("Guest") == 0)
	{
		Account* new_acc = new Guest_account(id, name, address, phone, 0, acc_type);
		list->insert_acc(new_acc);
		cout << "New account successfully added!" << endl;
		new_acc->print();

		cout << "\nPress any key to continue..." << endl;
		cin.ignore();
		return; 
	}
	else if (acc_type.compare("Regular") == 0)
	{
		Account* new_acc = new Regular_account(id, name, address, phone, 0, acc_type);
		list->insert_acc(new_acc);
		cout << "New account successfully added!" << endl;
		new_acc->print();

		cout << "\nPress any key to continue..." << endl;
		cin.ignore();
		return; 
	}
	else if (acc_type.compare("VIP") == 0)
	{
		Account* new_acc = new Vip_account(id, name, address, phone, 0, acc_type);
		list->insert_acc(new_acc);
		cout << "New account successfully added!" << endl;
		new_acc->print();

		cout << "\nPress any key to continue..." << endl;
		cin.ignore();
		return ;
	}
}

// This function update an existing customer
void update_customer(Account_list* list)
{
	string id, name, phone, address;
	// Ask for a valid customer ID to update
	do
	{
		cout << "Enter a customer ID to update: ";
		cin >> id;
		cin.ignore();

		if (!valid_account_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!list->exist_account_id(id))
		{
			cerr << "This account ID does not exist! Please try again." << endl;
		}
	} while (!valid_account_ID(id) || !list->exist_account_id(id));

	// Ask for customer new info to update
	cout << "Enter the customer's name:" << endl;
	getline(cin, name);

	cout << "Enter the customer's address:" << endl;
	getline(cin, address);

	do
	{
		cout << "Enter the customer's phone number:" << endl;
		cin >> phone;
		cin.ignore();
		if (!valid_phone(phone)) cerr << "Invalid phone number!" << endl;
	} while (!valid_phone(phone));

	Account* update_acc = new Account(id, name, address, phone);
	list->update_acc(update_acc);
	cout << "Successfully updated!" << endl;
	list->search_by_id(id)->print();

	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function operate renting
void renting(Account_list* acclist, Item_list* vlist)
{
	string item_id;
	string acc_id;
	// Ask for a valid customer ID and item ID to perform renting
	do
	{
		cout << "Enter a customer ID to rent: ";
		cin >> acc_id;
		cin.ignore();

		if (!valid_account_ID(acc_id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!acclist->exist_account_id(acc_id))
		{
			cerr << "This account ID does not exist! Please try again." << endl;
		}
	} while (!valid_account_ID(acc_id) || !acclist->exist_account_id(acc_id));
	do
	{
		cout << "Enter an item ID to rent: ";
		cin >> item_id;
		cin.ignore();
		if (!valid_item_ID(item_id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!vlist->exist_item_id(item_id))
		{
			cerr << "This item ID does not exist! Please try again." << endl;
		}
	} while (!valid_item_ID(item_id) || !vlist->exist_item_id(item_id));

	// Perform Borrowing
	acclist->search_by_id(acc_id)->borrowing(vlist->search_by_id(item_id));
	
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function operate returning
void returning(Account_list* acclist, Item_list* vlist)
{
	string item_id;
	string acc_id;
	// Ask for a valid customer ID and item ID to perform returning
	do
	{
		cout << "Enter a customer ID to return: ";
		cin >> acc_id;
		cin.ignore();
		if (!valid_account_ID(acc_id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!acclist->exist_account_id(acc_id))
		{
			cerr << "This account ID does not exist! Please try again." << endl;
		}
	} while (!valid_account_ID(acc_id) || !acclist->exist_account_id(acc_id));
	do
	{
		cout << "Enter an item ID to return: ";
		cin >> item_id;
		cin.ignore();
		if (!valid_item_ID(item_id))
		{
			cerr << "Invalid ID! Please try again." << endl;
			continue;
		}
		if (!vlist->exist_item_id(item_id))
		{
			cerr << "This item ID does not exist! Please try again." << endl;
		}
	} while (!valid_item_ID(item_id) || !vlist->exist_item_id(item_id));

	//Perform returning
	acclist->search_by_id(acc_id)->returning(vlist->search_by_id(item_id));
	
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function display all items sorted by title or ID
void display_all(Item_list* list)
{
	string input;
	bool valid = true;
	
	cout << "Display Items" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1.  Sort by ID" << endl;
	cout << "2.  Sort by title" << endl;
	cout << "3.  Back to previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;
	do
	{
		valid = true;
		cin >> input;
		cin.ignore();
		switch (input_type(input))
		{
		case 1:
			clear_screen();
			list->print_list();

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 2:
			clear_screen();
			list->print_list_sort_by_title();

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 3:
			return;
		default:
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);
}

// This function display all accounts sorted by title or ID
void display_all(Account_list* list)
{
	string input;
	bool valid = true;

	cout << "Display Customers" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "1.  Sort by ID" << endl;
	cout << "2.  Sort by name" << endl;
	cout << "3.  Back to previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;

	do
	{
		valid = true;
		cin >> input;
		cin.ignore();
		switch (input_type(input))
		{
		case 1:
			clear_screen();
			list->print_list();

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 2:
			clear_screen();
			list->print_list_sort_by_name();

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 3:
			return;
		default:
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);
}

// This function display accounts sorted by groups
void disp_group_menu(Account_list* list)
{
	string input;
	bool valid = true;

	cout << "1.  Display Guest accounts" << endl;
	cout <<	"2.  Display Regular accounts" << endl;
	cout << "3.  Display VIP accounts" << endl;
	cout << "4.  Back to previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;

	do
	{
		valid = true;
		cin >> input;
		cin.ignore();
		switch (input_type(input))
		{
		case 1:
			clear_screen();
			cout << "Guest Accounts" << endl;
			cout << "----------------" << endl;
			list->search_by_level("Guest");

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 2:
			clear_screen();
			cout << "Regular Accounts" << endl;
			cout << "----------------" << endl;
			list->search_by_level("Regular");

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 3:
			clear_screen();
			cout << "VIP accounts" << endl;
			cout << "----------------" << endl;
			list->search_by_level("VIP");

			cout << "\nPress any key to continue..." << endl;
			cin.ignore();
			break;
		case 4:
			return;
		default:
			valid = false;
			cerr << "Invalid input! Please try again." << endl;
		}
	} while (!valid);
}

// This function show the search menu
void search_menu(Account_list* acclist, Item_list* vlist)
{
	string input;
	bool valid = true;

	cout << "1.  Search customer by ID" << endl;
	cout << "2.  Search customer by name" << endl;
	cout << "3.  Search item by ID" << endl;
	cout << "4.  Search item by title" << endl;
	cout << "5.  Back to previous menu" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Enter an option below: " << endl;

	do
	{
		valid = true;
		cin >> input;
		cin.ignore();

		switch (input_type(input))
		{
		case 1:
			clear_screen();
			search_id(acclist);
			break;
		case 2:
			clear_screen();
			search_name(acclist);
			break;
		case 3:
			clear_screen();
			search_id(vlist);
			break;
		case 4:
			clear_screen();
			search_name(vlist);
		case 5:
			return;
		default:
			valid = false;
			cerr << "Invalid input!" << endl;
		}
	} while (!valid);
}

// This function search for an account using ID
void search_id(Account_list* list)
{
	string id;
	// Ask for a valid ID to search
	do
	{
		cout << "Enter a account ID to search: ";
		cin >> id;
		cin.ignore();
		if (!valid_account_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
		}
	} while (!valid_account_ID(id));
	if (list->search_by_id(id) != NULL)
		list->search_by_id(id)->print();
	
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function search for an item using ID
void search_id(Item_list* list)
{
	string id;
	// Ask for a valid ID to search
	do
	{
		cout << "Enter a item ID to search: ";
		cin >> id;
		cin.ignore();
		if (!valid_item_ID(id))
		{
			cerr << "Invalid ID! Please try again." << endl;
		}
	} while (!valid_item_ID(id));
	if (list->search_by_id(id) != NULL)
		list->search_by_id(id)->print();
	
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function search for an account using name
void search_name(Account_list* list)
{
	string name;
	// Ask for a name to search
	cout << "Enter a account name to search : ";
	getline(cin, name);
	list->search_by_name(name);
	
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function search for an item using title
void search_name(Item_list* list)
{
	string name;
	// Ask for a title to search
	cout << "Enter a item title to search: ";
	getline(cin, name);
	list->search_by_title(name);
	
	cout << "\nPress any key to continue..." << endl;
	cin.ignore();
	return;
}

// This function clear the console
void clear_screen()
{	
	// Clear the console
	system("clear");
}

// This function display the group info
void disp_group_info()
{
	cout << endl;
	cout << "ASSIGNMENT 2 GROUP 05" << endl;
	cout << "s3740805, s3740805@rmit.edu.vn, Linh Nguyen" << endl;
	cout << "s3818343, s3818343@rmit.edu.vn, Minh Tran" << endl;
	cout << "s3804791, s3804791@rmit.edu.vn, Thinh Nguyen" << endl;
	cout << "s3777214, s3777214@rmit.edu.vn, Chau Nguyen" << endl;
}