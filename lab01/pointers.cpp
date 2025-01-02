#include <iostream>
using namespace std;

int main ()
{
    // QNo06 Pointer declaration
    int *ptr;
    
    int number = 0;
    
    // QNo07 Pointer initialization
    ptr = &number;
    
    // QNo08 Dereferencing the pointer value
    cout << *ptr << endl;
    
    // QNo9 Pointer arithematic
    cout << *ptr+1 << endl;
    
    // QNo10 Pointer to Array elements
    int arr[5] = {1,2,3,4,5};
    int *arrPtr = arr;
    
    cout << *arrPtr << endl;
    
    char screenshot;
    cin >> screenshot; // For taking output's screenshot
    return 0;
}
