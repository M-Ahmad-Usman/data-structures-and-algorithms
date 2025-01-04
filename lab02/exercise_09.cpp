#include<iostream>
using namespace std;

void SwapFunction (int *ptr1, int *ptr2)
{
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
}

int main ()
{
    int a,b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter Second number: ";
    cin >> b;

    SwapFunction(&a,&b);
    cout << "Value of first number: " << a << "\nValue of second number: " << b << "\n";

    getchar(); // For taking output's screenshot
    return 0;
}
