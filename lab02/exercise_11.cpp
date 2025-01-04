#include<iostream>
#include<string>
using namespace std;

int main ()
{
    string studentName[3];

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter the name of student: ";
        cin >> studentName[i];
    }

    cout << "Student names are: " << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << studentName[i] << endl;
    }

    return 0;
}
