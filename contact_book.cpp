#include <iostream>
using namespace std;

struct contact__book
{
    string name;
    string number;
};

contact__book contact[100];
int total = 0;

void add_contact()
{
    if(total >= 100){
        cout<<"Contact book is full\n";
        return;
    }
    
    cout << "Enter the contact name: ";
    cin >> contact[total].name;

    cout << "Enter the contact  number: ";
    cin >> contact[total].number;

    total++;
    cout << "contact added successfully" << endl;
    return;
}

void view_contact()
{
    for (int i = 0; i < total; i++)
    {
        cout << "Name: " << contact[i].name << endl;
        cout << "Contact: " << contact[i].number << endl;
    }
}

void find_number()
{
    string user_name;
    cout << "Enter name to find the contact number: ";
    cin >> user_name;
    for (int i = 0; i < total; i++)
    {
        if (contact[i].name == user_name)
        {
            cout << "Number: " << contact[i].number << endl;
            return;
        }
    }
    cout << "user not found in contact book";
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1:Add contact \n 2:view Contact\n 3: Find Contact \n 4:Exit\n";

        cin >> choice;

        if (choice == 1)
        {
            add_contact();
        }
        else if (choice == 2)
        {
            view_contact();
        }
        else if (choice == 3)
        {
            find_number();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice";
        }
    }
}
