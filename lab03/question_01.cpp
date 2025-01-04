#include <iostream>
using namespace std;

class MobilePhone
{
    private:
    int phoneId;
    string batteryLife;
    string ownerName;

    public:
    MobilePhone ()
    {
        phoneId = 0;
        batteryLife = "Not Initialized yet";
    }

    MobilePhone (int pid, string battery, string name)
    {
        phoneId = pid;
        batteryLife = battery;
        ownerName = name;   
    }

    string GetOwnerName ()
    {
        return ownerName;
    }
    void SetOwnerName (string name)
    {
        ownerName = name;
    }

    void Display ()
    {
        cout << "PhoneID: " << phoneId << "\nBattery Life: " << batteryLife << "\nOwner Name: " << ownerName << "\n";
    }



};

int main ()
{
    MobilePhone Samsung (1, "90 Percent", "Ahmad");
    Samsung.SetOwnerName("Muhammad Ahmad");
    Samsung.Display();
    return 0;
}