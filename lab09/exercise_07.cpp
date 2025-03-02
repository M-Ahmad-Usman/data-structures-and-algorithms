#include <iostream>
using namespace std;

int SumOfDigits(int n)
{
    int result = 0;
    while (n >= 1)
    {
        result += n;
        n--;
    }
    return result;
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

int main()
{
    int n;
    char choice;
    
    do
    {
        cout << "Enter Number: ";
        n = TakeIntegerInput();
        cout << SumOfDigits(n) << "\n";

        cout << "Do you want to calculate again? (Y/N) ";
        cin >> choice;

        // Ignoring the newline character left by cin
        cin.ignore();
        
    } while (choice == 'Y' || choice == 'y');

    return 0;
}