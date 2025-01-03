#include <iostream>
using namespace std;

class Student
{
public:
    string rollNo;
    string name;
    int marks[3];
};

void FindFailedStudents(Student students[3])
{
    cout << "Failed students: ";

    int fail = 0;
    for (int i = 0; i < 3; i++)
    {
        if (students[i].marks[0] <= 49)
            fail++;
        if (students[i].marks[1] <= 49)
            fail++;
        if (students[i].marks[2] <= 49)
            fail++;

        if (fail >= 2)
        {
            cout << students[i].name << endl
                 << students[i].rollNo;
            fail = 0;
        }
        else
            fail = 0;
    }
}

int main()
{
    Student students[3]; // Created list of 3 students instead of 25 for convenience
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter name of student " << i + 1 << endl;
        cin >> students[i].name;
        cout << "Enter roll no of student " << i + 1 << endl;
        cin >> students[i].rollNo;

        for (int j = 0; j < 3; j++)
        {
            cout << "Enter marks of subject " << j + 1 << endl;
            cin >> students[i].marks[j];
        }
    }

    FindFailedStudents(students);

    char screenshot;
    cin >> screenshot; // For taking output's screenshot
    return 0;
}
