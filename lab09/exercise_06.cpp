#include <iostream>
using namespace std;

void FibonacciUsingRecursion(int n, int first = 0, int second = 1, int sum = 1)
{
    if (n < 0)
    {
        cout << "Please enter a positive number\n";
        return;
    }
    else if (n == 1)
    {
        cout << "0";
        return;
    }
    else if (n == 2)
    {
        // Base case
        if (first == 0 && second == 1)
            cout << "0 1";
        return;
    }
    else if (n > 2)
    {
        if (first == 0 && second == 1)
            cout << "0 1 ";
        cout << sum << " ";

        first = second;
        second = sum;
        sum = first + second;
        FibonacciUsingRecursion(n - 1, first, second, sum);
    }
}

int TakeIntegerInput()
{
    string inputStr;
    int number;

    // Stores the index where non-integer character starts if any.
    size_t charPosition;

    while(true)
    {
        try
        {
            getline(cin, inputStr);
            number = stoi(inputStr, &charPosition);
            
            if (charPosition != inputStr.length())
                throw runtime_error("Input contains non-integer characters");
            else
                return number;
        }
        catch(const exception& e)
        {
            cout << "Invalid input. Enter a valid integer: ";
        }
        
    }
}

int main ()
{
    int n;
    char choice;
    
    do
    {
        cout << "Enter Number: ";
        n = TakeIntegerInput();
        FibonacciUsingRecursion(n);
        cout << "\n";

        cout << "Do you want to write again? (Y/N) ";
        cin >> choice;

        cin.ignore();
        
    } while (choice == 'Y' || choice == 'y');

    return 0;
}