#include <iostream>
#include <string>
using namespace std;

class Person 
{
    private:
        string name;
        int age;
        string cnic;

    public:

    Person(string n, int a, string c)
    {
        name = n;
        age = a;
        cnic = c;
    }

    void Print() 
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
    }
};

int main() {
    Person person1("Muhammad Ahmad", 18, "123456798484");

    person1.Print();

    char screenshot;
    cin >> screenshot; // For taking output's screenshot
    return 0;
}
