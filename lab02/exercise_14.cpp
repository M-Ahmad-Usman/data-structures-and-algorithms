#include <iostream>
using namespace std;

int main ()
{
    char stringArray[20];
    cout << "Enter a string of less than 19 without spaces characters.\n";
    cin >> stringArray;
    char *ptr = stringArray;
    int i;
    for (i=0; *ptr != '\0'; i++)
    {
        *(ptr++);
    }
    cout << "The length of entered array is " << i << "\n";

    return 0;
}
