#include <iostream>
using namespace std;

void FibonacciSequence(int n)
{
    if (n <= 0)
        return;
    else if (n == 1)
    {
        cout << "0\n";
        return;
    }

    int first = 0;
    int second = 1;
    int sequence;

    cout << "0 1 ";
    while (n >= 3)
    {
        sequence = first + second;
        cout << sequence << " ";

        first = second;
        second = sequence;
        n--;
    }

    cout << "\n";
    return;
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
    int n;
    char choice;
    
    do
    {
        cout << "Enter Number: ";
        n = TakeIntegerInput();
        FibonacciSequence(n);

        cout << "Do you want to write again? (Y/N) ";
        cin >> choice;

        cin.ignore();
        
    } while (choice == 'Y' || choice == 'y');
    

    return 0;
}