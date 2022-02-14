#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

// Global variables
string fname, lname, phone_num;


// Functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_numbers(string);


int main()
{
	short int choice;
    system("cls");
    system("color 0A");
    cout << "\t\tContact Management" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1. Add Contact " << endl;
    cout << "2. Search Contact " << endl;
    cout << "3. Help" << endl;
    cout << "4. Exit" << endl;
    cout << ">";
    cin >> choice; 
    
    switch(choice)
    {
    	case 1:
    		addContact();
    		break;
    	case 2:
    		searchContact();
    		break;
    	case 3:
    		help();
    		break;
    	case 4:
    		self_exit();
    		break;
    	default:
    		cout << "Invalid Input!" << endl;
    		cout << "Press Any Key To Continue..." << endl;
    		getch();
    		main();
	
	}
       
    return 0;
	
}
	
void self_exit()
{
	system("cls");
	cout << "Thank you for using!" << endl;
	exit(1);	
}	


void help()
{
	cout << "This displays help" << endl;	
}


void addContact()
{
	ofstream phone("number.txt", ios::app);
	system("cls");
	cout << "Enter first name: " << endl;
	cin >> fname;
	cout << "Enter last name: " << endl;
	cin >> lname;
	cout << "Enter 10-digit phone number: " << endl;
	cin >> phone_num;
	
	if(check_digits(phone_num) == true)
	{
		if(check_numbers(phone_num) == true)
		{
			if(phone.is_open())
			{
				phone << fname << " " << lname << " " << phone_num << endl;
				cout << "Contact saved successfully!" << endl;
			}
			else
			{
				cout << "Error opening file!" << endl;
			}
			
		}
		
	}
	else 
	{
		cout << "A phone number must contain 10 digits!" << endl;	
	}
	phone.close();
	
	
}


void searchContact()
{
	bool found = false;
	ifstream myfile("number.txt");
	string keyword;
	cout << "Enter name to search: " << endl;
	cin >> keyword;
	while(myfile >> fname >> lname >> phone_num)
	{
		if(keyword == fname || keyword == lname)
		{
			system("cls");
			cout << "Contact details..." << endl;
			cout << "First Name: " << fname << endl;
			cout << "Last Name: " << lname << endl;
			cout << "Phone Number: " << phone_num << endl;
			found = true;
			break;
		}
		
	}
	if(found == false) 
	cout << "No such contact found!" << endl;
	
}

bool check_digits(string x)
{
	if(x.length() == 10)
	return true;
	else
	return false;
}


bool check_numbers(string x)
{
	bool check = true;
	
	for(int i=0; i < x.length(); i++)
	{
		if(!(int(x[i])) >= 48 && int(x[i]) <= 57)
		{
			check= false;
			break;
		}
	}
	
	if(check == true)
	return true;
	if(check == false)
	return false;
	
	
}
	

    