#include <iostream>
#include <limits>
using namespace std;

int CalculateSquareArea(int length)
{
    return length * length;
}

float CalculateCircleArea(int radius)
{
    return 3.14 * radius * radius;
}

float CalculateRectangleArea(int length, int width)
{
    return length * width;
}

void GetChoice()
{
    int choice;

    cout << "1.Press 1 for finding area of square.\n2.Press 2 for finding area of Circle.\n3.Press 3 for finding the area of rectangle.";

    if (!(cin >> choice))
    {
        cin.clear(); // When an invalid input (e.g., a non-integer) is entered, std::cin sets an error flag (failbit) to indicate the failure of the input operation. Once the error flag is set: Further attempts to use std::cin will fail until the error flag is cleared. Without clearing the error flag, std::cin remains in an unusable state.

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // When invalid input is entered (e.g., "abc" for an integer), the characters remain in the input buffer. If you don’t remove these characters, subsequent input attempts will read the same invalid data, causing repeated failures. std::numeric_limits<std::streamsize>::max() specifies the maximum number of characters to ignore. It ensures that all characters, up to a newline (\n), are removed. '\n' specifies the delimiter at which to stop ignoring characters. Typically, you stop at the newline character because it marks the end of the current input.

        throw runtime_error("Invalid input. Please enter a number.");
    }

    switch (choice)
    {
    case 1:
    {
        int length;
        cout << "Enter radius of square.\n";
        cin >> length;
        int area = CalculateSquareArea(length);
        cout << "The area of given square is " << area << endl;
        break;
    }
    case 2:
    {
        int radius;
        cout << "Enter radius of circle.\n";
        cin >> radius;

        float area = CalculateCircleArea(radius);
        cout << "The area of given circle is " << area << endl;
        break;
    }
    case 3:
    {
        int length, width;
        cout << "Enter the length and width of rectangle.\n";
        cin >> length >> width;

        int area = CalculateRectangleArea(length, width);
        cout << "The area of given rectangle is " << area << endl;
        break;
    }
    default:
        throw runtime_error("Invalid choice. Please enter a valid choice.");
    }
}

int main()
{
    char calculateAgain = 'y';

    while (calculateAgain == 'y')
    {
        try
        {
            GetChoice();
            cout << "Press y to calculate again or any other key to close\n";
            cin >> calculateAgain;
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
    }

    return 0;
}
