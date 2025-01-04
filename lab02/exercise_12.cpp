#include <iostream>
using namespace std;

void printValue(const int* ptr) 
{
    cout << "Value pointed to by the pointer: " << *ptr << endl;
}

int main() 
{
    const int num = 10;
    const int* ptr = &num;
    
    printValue(ptr);

    return 0;
}
