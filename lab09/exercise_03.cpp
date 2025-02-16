#include <iostream>
#include <limits>
#include <string.h>

using namespace std;

long RaiseToPower(int operand, int exponent)
{
    long result = 1.0;

    if (operand == 0 && exponent == 0)
        throw runtime_error("0^0 is ambigous.");

    if (operand == 0)
        return 0;

    else if (exponent == 0)
        return 1.0;

    else if (exponent < 0)
    {
        exponent = -exponent;
        while (exponent >= 0)
        {
            result *= operand;
            exponent--;
        }
        return 1.0 / result;
    }

    else
    {
        while (exponent >= 1)
        {
            result *= operand;
            exponent--;
        }

        return result;
    }
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
            cout << "Invalid input. Enter a valid integer: ";
        }
        
    }
}

int main ()
{
    int operand;
    int exponent;
    char choice;

    do
    {
        try
        {
            cout << "Enter operand: ";
            operand = TakeIntegerInput();

            cout << "Enter exponent: ";
            exponent = TakeIntegerInput();

            long result = RaiseToPower(operand, exponent);
            cout << operand << "^" << exponent << ": " << result << "\n";
        }
        catch(const exception& e)
        {
            cerr << e.what() << '\n';
        }

        cout << "Do you want to calculate again? (Y/N) ";
        cin >> choice;

        // Clearing the input buffer from '\n' left by cin before taking new input in getline
        cin.ignore();
        
    } while (choice == 'y' || choice == 'Y');

    return 0;
}