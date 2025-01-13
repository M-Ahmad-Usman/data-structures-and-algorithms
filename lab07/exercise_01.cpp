#include <iostream>
using namespace std;

// Stack implementation using array
int const STACKSIZE = 5;

class Stack
{
    int stackArray[STACKSIZE];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    bool IsEmpty()
    {
        return (top == -1)? true: false;
    }

    bool IsFull()
    {
        return (top == STACKSIZE-1)? true: false;
    }

    int Size()
    {
        return STACKSIZE;
    }
    
    void Push(int);
    void Pop();
    void Display();

};

main()
{
    return 0;
}