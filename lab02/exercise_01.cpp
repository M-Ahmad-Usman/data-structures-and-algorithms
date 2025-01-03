#include <iostream>
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
    bool run = true;
    int choice;
    char ch;

    while (run)
    {
        cout << "1.Press 1 for finding area of square.\n2.Press 2 for finding area of Circle.\n3.Press 3 for finding the area of rectangle.";
        cin >> choice;

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
            cout << "Invalid input\n";
        }

        cout << "Do you want to calculate again (Y/N)?\n";
        cin >> ch;
        if (ch == 'N' || ch == 'n')
        {
            run = false;
        }
    }
}

int main()
{
    GetChoice();

    char screenshot; // For taking output's screenshot
    cout << "Enter any character to close.\n";
    cin >> screenshot;
    return 0;
}
