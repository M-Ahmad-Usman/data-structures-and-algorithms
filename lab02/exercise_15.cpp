#include <iostream>
using namespace std;

void FindMin(int arr[], int size)
{
    int minimum = *arr;
    for (int i=0; i<size; i++)
    {
        if (minimum > *(arr+i))
        {
            minimum = *(arr+i);
        }
    }
    cout << "The minimum value in the array is " << minimum << "\n";
}

int main ()
{
    int arr[5];
    cout << "Enter five integers: \n";
    for (int i=0; i<5; i++)
    {
        cin >> arr[i];
    }
    FindMin(arr, 5);

    return 0;
}
