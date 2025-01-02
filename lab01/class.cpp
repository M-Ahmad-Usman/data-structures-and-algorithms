#include <iostream>
#include <cstring>
using namespace std;

// QNo 01 Class definition
class Person
{
    public:
    string name;
    double age;
    char gender;

// QNo04 Member Function Call
void displayInfo ()
{
    cout << "Person Details: \nName: " << name << "\nAge: " << age << "\nGender: " << gender << "\n";
} 
    
};

int main ()
{
    // QNo02 Object Creation
    Person person1;
    
    
    // QNo03 Member Access
    person1.name = "Ahmad";
    person1.age  = 21;
    person1.gender = 'M';
    cout << person1.name << "\n";
    
    // QNo04 Member Function call
    person1.displayInfo();
    
    // QNo05 Multiple Objects
    Person person2;
    person2.name = "Ali";
    person2.age = 22;
    person2.gender = 'M';
    
    person2.displayInfo();
    
    char screenshot;
    cin >> screenshot; // For taking output's screenshot

    return 0;
}
