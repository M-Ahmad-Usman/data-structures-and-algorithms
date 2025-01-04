#include <iostream>
using namespace std;

void Sum (int *ptr1, int *ptr2)
{
    *ptr1 += *ptr2;
    *ptr2 = *ptr1;
}

int main ()
{
    int a, b;
    cout << "Enter the numbers: \n";
    cin >> a >> b;

    Sum (&a, &b);
    cout << a << "\n" << b;

    getchar(); // For taking output's screenshot
    return 0;
}
