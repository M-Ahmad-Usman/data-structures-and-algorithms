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
        string GetName () 
        {
            return name;
        }

        int GetAge()
        {
            return age;
        }

        string GetCNIC() 
        {
            return cnic;
        }

    void SetName(string n)
    {
        name = n;
    }

    void SetAge(int a) 
    {
        if (a < 0 || a > 130) 
        {
            cout << "Invalid age. Age must be between 0 and 130 years.";
        }
        else
        age = a;
    }

    void SetCNIC (string c) 
    {
        if (c.length() != 13) 
        {
            cout << "Invalid CNIC number. CNIC number must be 13 digits long.";
            cnic = "Default";
        }
        else
        cnic = c;
    }

    void Print() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "CNIC: " << cnic << endl;
    }
};

int main() 
{
    Person person1;
    person1.SetName("Muhammad Ahmad");
    person1.SetAge(18);
    person1.SetCNIC("1234567890123");

    person1.Print();

    char screenshot;
    cin >> screenshot; // For taking output's screenshot
    return 0;
}
