#include <iostream>
using namespace std;

int* FindMaximum (int array[], int size, int *max)
{
    int *ptr = array;
    int maximum = *ptr;
    
    for (int i=0; i<size; i++)
    {
        if (maximum < * (ptr+i))
        {
            max = ptr+i;
            maximum = *ptr+i;
        }
    }

    return max;
}

void Display (int *ptr)
{
    cout << "The maximum value is " << *ptr;
}

int main ()
{   
    int* maximum;
    int arr[5] = {1,2,3,4,5};
    Display(FindMaximum(arr, 5, maximum));

    return 0;
}