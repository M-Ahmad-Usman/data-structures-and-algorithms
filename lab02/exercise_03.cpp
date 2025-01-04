#include <iostream>
using namespace std;

void AscendingSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int arr[10];

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) 
    {
        cout << "Enter integer #" << (i + 1) << ": ";
        cin >> arr[i];
    }

    AscendingSort(arr, 10);

    cout << "Sorted array in ascending order:\n";
    for (int i = 0; i < 10; ++i) 
    {
        cout << arr[i] << " ";
    }

    char screenshot;
    cin >> screenshot; // For taking output's screenshot
    return 0;
}
