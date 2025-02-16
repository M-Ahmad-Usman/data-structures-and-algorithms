#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

// Returns factorial of given positive integer
unsigned long long CalcFactorial(int number)
{
    // Edge case
    if (number < 0) 
        throw runtime_error("Factorial of negative integers is not allowed.");

    unsigned long long result = 1;
    while (number >= 1)
    {
        result *= number;
        number--;
    }
    return result;
}

int TakeIntegerInput()
{
    string inputStr;
    int number;

    // Stores the index where non-integer character starts
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
            cout << "Invalid input. Enter a positive integer without spaces: ";
        }
        
    }
}

int main ()
{
    int number;
    char choice;

    do
    {
        cout << "Enter number: ";
        number = TakeIntegerInput();
        
        try
        {
            unsigned long long result = CalcFactorial(number);
            cout << "Factorial: " << result << "\n";
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }

        cout << "Do you want to calculate again? (Y/N) ";
        cin >> choice;

        // Clearing the input buffer before taking new input in getline
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');

    return 0;
}