#include <iostream>
using namespace std;

double calculateArea(double* side) 
{
    return (*side) * (*side);
}

double calculateArea(double* length, double* width) 
{
    return (*length) * (*width);
}

double calculateArea(double* radius, double pie) 
{
    return pie * (*radius) * (*radius);
}

int main() 
{
    double side = 5.0;
    double length = 6.0;
    double width = 4.0;
    double radius = 3.0;

    cout << "Area of square: " << calculateArea(&side) << endl;

    cout << "Area of rectangle: " << calculateArea(&length, &width) << endl;

    cout << "Area of circle: " << calculateArea(&radius, 3.14) << endl;
    return 0;
}
