#include <iostream>
using namespace std;

float total;
int student_num;

struct Student_record
{
    string name;
    int age;
    float marks[5];
};

int main()
{
    cout << "\nhow many student record you want to enter";
    cin >> student_num;

    for (int i = 0; i < student_num; i++)
    {
        Student_record s[student_num];

        cout << "Enter Student name: ";
        cin >> s[i].name;

        cout << "Enter Studennt age:";
        cin >> s[i].age;

        cout << "enter 5 subjects marks :";
        for (int j = 0; j < 5; j++)
        {
            cin >> s[i].marks[j];
            total += s[i].marks[j];
            // float percnt = (total / 500) * 100;
        }
        float percnt = (total / 500) * 100;

        cout << "student name: " << s[i].name << "\n";
        cout << "student age: " << s[i].age << "\n";
        cout << "student percentage  is : " << percnt;
    }
}