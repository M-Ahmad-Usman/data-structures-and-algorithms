#include <iostream>
using namespace std;

// QNo11 Class Object with Pointer
class Car
{
    public:
    string model;
    int year;
    
    
    // QNo13 Member function's code
    void displayDetails ()
    {
        cout << "Car details:\nModel: " << model << "\nYear: " << year << endl; 
    }   
};

int main ()
{
    Car myCar;
    myCar.model = "Honda";
    myCar.year = 2018;
    
    Car *carPtr = &myCar;
    
    // QNo12 Member Access through pointer
    cout << carPtr -> model << endl;
    
    // QNo13 Member Function call through Pointer
    carPtr -> displayDetails();
    
    // QNo14 Pointer to multiple objects
    Car carArray[2];
    carArray[0] = myCar;  
    
    Car *arrayPtr = carArray;
    
    // Accessing the model of the first car through pointer
    cout << arrayPtr-> model;
    
    
    // QNo15 Object Assignment through Pointer
    Car anotherCar;
    anotherCar.model = carPtr-> model;
    anotherCar.year = carPtr-> year;

    // Assigning the second index of carArray through pointer
    arrayPtr[1] = anotherCar;
    arrayPtr[1].displayDetails();

    char screenshot;
    cin >> screenshot; // For taking output's screenshot

    return 0;
}
