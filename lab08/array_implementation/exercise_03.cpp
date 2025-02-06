#include <iostream>
#include <limits>
#include "exercise_01.cpp"
using namespace std;

// Takes input from user
template <typename T>
bool TakeInput(T *input)
{
    // Takes user input and checking whether the input is valid integer
    if (!(cin >> *input))
    {
        cin.clear(); // When an invalid input (e.g., a non-integer) is entered, std::cin sets an error flag (failbit) to indicate the failure of the input operation. Once the error flag is set: Further attempts to use std::cin will fail until the error flag is cleared. Without clearing the error flag, std::cin remains in an unusable state.

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // When invalid input is entered (e.g., "abc" for an integer), the characters remain in the input buffer. If you don’t remove these characters, subsequent input attempts will read the same invalid data, causing repeated failures. std::numeric_limits<std::streamsize>::max() specifies the maximum number of characters to ignore. It ensures that all characters, up to a newline (\n), are removed. '\n' specifies the delimiter at which to stop ignoring characters. Typically, you stop at the newline character because it marks the end of the current input.

        return false;
    }

    return true;
}

template <typename T>
ArrayQueue<T> *InitializeQueue()
{
    int queueSize;

    cout << "Enter queue size: ";
    while (!(TakeInput(&queueSize)) || queueSize <= 0)
    {
        cout << "Invalid input.\n";
        cout << "Please enter a valid integer: ";
    }

    return new ArrayQueue<T>(queueSize);
}

template <typename T>
void Menu()
{
    int operation;
    bool run = true;

    ArrayQueue<T> *queue = InitializeQueue<T>();

    while (run)
    {
        cout << "1.Press 1 to insert element in Queue.\n";
        cout << "2.Press 2 to delete element from Queue.\n";
        cout << "3.Press 3 to display elements in Queue.\n";
        cout << "4.Press 4 to exit.\n";

        while (!(TakeInput(&operation)))
        {
            cout << "Invalid input.\n";
            cout << "Please enter an integer: ";
        }

        switch (operation)
        {

        case 1:
        {
            cout << "Enter element: ";
            T data;

            while (!(TakeInput(&data)))
            {
                cout << "Invalid input element.\n";
                cout << "Please enter again: ";
            }

            try
            {
                queue->Enqueue(data);
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }

            break;
        }
        case 2:
        {
            try
            {
                cout << queue->Dequeue() << " item deleted.\n";
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }

            break;
        }
        case 3:
        {
            cout << "Elements: ";
            queue->PrintQueue();
            break;
        }
        case 4:
        {
            run = false;
            break;
        }

        default:
        {
            cout << "Input operation not recognized. Please enter an integer from 1-4\n";
            break;
        }
        }
    }

    delete queue;
}

int main()
{
    Menu<int>();
    return 0;
}