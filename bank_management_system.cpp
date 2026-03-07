#include <iostream>
using namespace std;

struct atm_system
{
    string name;
    string account_number;
    float balance;
};

atm_system atm[100];
int atm_qtn = 0;

void Creat_Account()
{
    if (atm_qtn >= 100)
    {
        cout << "FULL\n";
        return;
    }

    cout << "Enter name : ";
    cin >> atm[atm_qtn].name;

    cout << "Enter the Account Number :";
    string acc_no;
    cin >> acc_no;
    if (acc_no.length() < 10 || acc_no.length() > 12)
    {
        cout << "Invalid account number" << endl;
        return;
    }
    else
    {
        atm[atm_qtn].account_number = acc_no;
    }

    cout << "Enter amount: ";
    cin >> atm[atm_qtn].balance;

    atm_qtn++;
    cout << "++++++++++++++Account Created Successfully+++++++++++++++++++++";
}

void withdraw()
{
    string user, acc_no;
    cout << "Enter name: ";
    cin >> user;
    cout << "Enter account number: ";
    cin >> acc_no;
    bool found = false;

    for (int i = 0; i < atm_qtn; i++)
    {
        if (user == atm[i].name && acc_no == atm[i].account_number)
        {
            found = true;
            if (atm[i].balance > 0)
            {
                cout << "Enter Amount to withdraw :";
                int amnt, updated_balance;
                cin >> amnt;
                updated_balance = int(atm[i].balance) - amnt;
                cout << "++++++++++++++Withdraw Successfull++++++++++++++" << endl;
                cout << "~~~~~~~~~Avlb Balance: " << updated_balance;
                atm[i].balance = updated_balance;
            }
            else
            {
                cout << "Insufficient Balance" << endl;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "\nUNREGISTERED USER\n";
    }
}

void check_balance()
{
    string user, acc_no;
    cout << "Enter name: ";
    cin >> user;
    cout << "Enter account number: ";
    cin >> acc_no;

    bool found = false;

    for (int i = 0; i < atm_qtn; i++)
    {
        if (user == atm[i].name && acc_no == atm[i].account_number)
        {
            cout << "\nAccount holder name: " << atm[i].name << endl;
            cout << "Total amount: " << atm[i].balance << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nUNREGISTERED USER\n";
    }
}

void Deposit()
{
    for (int i = 0; i < atm_qtn; i++)
    {
        string user, acc_no;
        cout << "Enter name: ";
        cin >> user;
        cout << "Enter account number: ";
        cin >> acc_no;

        if (user == atm[i].name && acc_no == atm[i].account_number)
        {
            int amount;
            cout << "Enter deposit amount: ";
            cin >> amount;

            atm[i].balance += amount;

            cout << "+++++++++++++++Deposit Successful++++++++++++++++++++++++++\n";
            cout << "+++Updated Balance: " << atm[i].balance << endl;
            break;
        }
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1:check Balance\n2:Creat Account\n3:Withdraw\n4:Deposit\n5:Exit" << endl;
        cout << "Enter:";

        cin >> choice;

        if (choice == 1)
        {
            check_balance();
        }
        else if (choice == 2)
        {
            Creat_Account();
        }
        else if (choice == 3)
        {
            withdraw();
        }
        else if (choice == 4)
        {
            Deposit();
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid Input";
        }
    }
}
