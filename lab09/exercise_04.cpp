#include <iostream>
#include <string.h>

using namespace std;

double PowerUsingRecursion(int operand, int exponent)
{

    if (operand == 0 && exponent == 0)
        throw runtime_error("0^0 is ambigous.");
    else if (exponent == 0)
        return 1;
    else if (operand == 0)
        return 0;
    
    if (exponent < 0)
    {
        exponent = -exponent;
        double result = operand * PowerUsingRecursion(operand, exponent - 1);
        return 1.0 / result;
    }

    if (exponent == 1)
        return operand;
    else
        return operand * PowerUsingRecursion(operand, exponent - 1);
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

            double result = PowerUsingRecursion(operand, exponent);
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