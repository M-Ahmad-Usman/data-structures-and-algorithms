#include <iostream>
using namespace std;

// Stack implementation using array of dynamic size

template<typename T>
class Stack
{
    T *arrptr;
    int size;
    int top;

public:

    Stack(int size)
    {
        if (size <= 0)
        {
            throw runtime_error("Stack size must be a positive integer.\n");
        }

        top = -1;
        this->size = size;

        arrptr = new T[size];
    }

    bool IsEmpty()
    {
        return (top == -1) ? true : false;
    }

    bool IsFull()
    {
        return (top == size - 1) ? true : false;
    }

    // Returns the current size of the stack (i.e items currently in stack)
    int Size()
    {
        return top + 1;
    }

    void Push(T data)
    {
        if (IsFull())
        {
            cout << "Stack is full. Can't Insert more items.\n";
            return;
        }
        arrptr[++top] = data;
    }

    T Pop()
    {
        if (!IsEmpty())
        {
            return arrptr[top--];
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
            cout << arrptr[counter--] << " ";
        }
        cout << "\n";
    }

    // Destructor to free the memory allocated to stack
    ~Stack()
    {
        delete[] arrptr;
    }
};

int main()
{
    try
    {
        Stack<string> s(3);
        s.Push("10");
        s.Push("20");
        s.Push("30");
        s.Display();

        cout << "Popped: " << s.Pop() << "\n";
        s.Display();

        s.Push("40");
        s.Display();

        s.Push("50");
    }
    catch (const exception &e)
    {
        cout << e.what();
    }

    return 0;
}