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

    void Push(int data)
    {
        if (IsFull())
        {
            cout << "Stack is full. Can't Insert more items.\n";
            return;
        }
        stackArray[++top] = data;
    }

    int Pop()
    {
        if (!IsEmpty())
        {
            return stackArray[top--];
        }

        throw runtime_error("Stack is empty. Can't pop from an empty stack.\n");
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Can't display anything.\n";
            return;
        }

        int counter = top;
        while (counter >= 0)
        {
            cout << stackArray[counter--] << " ";
        }
        cout << "\n";
    }

};

int main()
{
    Stack stack;

    stack.Display();

    try
    {
        stack.Pop();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    stack.Push(6);

    stack.Display();

    cout << "Popped: " << stack.Pop() << "\n";

    stack.Display();

    stack.Pop();
    stack.Pop();
    stack.Pop();

    stack.Display();

    return 0;
}