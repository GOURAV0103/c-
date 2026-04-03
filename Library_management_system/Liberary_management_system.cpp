#include <iostream>
using namespace std;

struct Book
{
    int id;
    string name;
    string author;
    bool issued;
};

Book bk[1000];
int quantity = 0;

bool idExists(int ids)
{
    for (int i = 0; i < quantity; i++)
    {
        if (bk[i].id == ids)
        {
            return true;
        }
    }
    return false;
}

void Add_book()
{
    if (quantity > 1000)
    {
        cout << "Library Full";
        return;
    }

    int id;
    cout << "Enter Unique ID: ";
    cin >> id;
    if (idExists(id))
    {
        cout << "ID already exists! Enter a different ID.\n";
        return;
    }
    bk[quantity].id = id;

    // THIS CODE AUTOMATICALLY ASSIGN THE ID's FOR BOOKs
    //  cout << "Assigning ID...." << endl;
    //  bk[quantity].id = quantity+1;
    //  cout << "ID Assigned success" << endl;

    cout << "Enter the name of the book: \n";
    cout << "USE {_}userscore INSTEAD OF SPACE: ";
    cin >> bk[quantity].name;

    cout << "Enter the Author name: ";
    cin >> bk[quantity].author;

    quantity++;
    cout << "+++++++++++++Book added Successfully+++++++++++++++";
}

void View_book()
{
    cout << "Book list" << endl;
    cout << "ID\t\tNAME\t\tAUTHOR\t\tISSUED" << endl;
    for (int i = 0; i < quantity; i++)
    {
        cout << bk[i].id << "\t\t" << bk[i].name << "\t\t" << bk[i].author;
        if (bk[i].issued)
        {
            cout << "\t\tIssued" << endl;
        }
        else
        {
            cout << "\t\tAvailable" << endl;
        }
    }
    cout << "\nTotal Books : " << quantity << endl;
}

void Search_book()
{
    string bk_book;
    cout << "Enter the name of the book to find: ";
    cin >> bk_book;
    for (int i = 0; i < quantity; i++)
    {
        if (bk_book == bk[i].name)
        {
            cout << "*******BOOK FOUND********\n";
            cout << "Book ID : " << bk[i].id << "\n"
                 << "Book name : " << bk[i].name << "\n"
                 << "Book Author: " << bk[i].author << endl;
        }
        else
        {
            cout << "~~~~NOT FOUND~~~~";
        }
    }
}

void Issue_book()
{
    string bk_name;
    bool found = false;

    cout << "Enter the book name that you want to Issue: ";
    cin >> bk_name;

    for (int i = 0; i < quantity; i++)
    {
        if (bk_name == bk[i].name)
        {
            found = true;
            if (!bk[i].issued)
            {
                cout << "*******Book Issued Successfully******" << endl;
                bk[i].issued = true;
                // quantity--;
            }
            else
            {
                cout << "Book is already issued" << endl;
            }
            break;
        }
    }
    if (!found)
    {
        cout << "\nBook is not in the library" << endl;
    }
}

void Return_book()
{
    bool found = false;
    string bk_name;
    cout << "Enter the book that you want to return: ";
    cin >> bk_name;
    for (int i = 0; i < quantity; i++)
    {
        if (bk_name == bk[i].name)
        {
            found = true;
            if (bk[i].issued == 1) // 1 true
            {
                // quantity++;
                bk[i].issued = false;
                cout << "Book returned successfully" << endl;
            }
            else
            {
                cout << "Book was not issued" << endl;
            }
            break;
        }
    }
    if (!found)
    {
        cout << "\nBook is not in the library" << endl;
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1:Add Book \n2:View Book \n3:Search Book \n4:Issue Book \n5:Return Book \n6:Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            Add_book();
        }
        else if (choice == 2)
        {
            View_book();
        }
        else if (choice == 3)
        {
            Search_book();
        }
        else if (choice == 4)
        {
            Issue_book();
        }
        else if (choice == 5)
        {
            Return_book();
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid Input";
        }
    }
}
