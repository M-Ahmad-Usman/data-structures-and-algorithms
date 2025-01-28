#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = nullptr;
    }

    int GetData()
    {
        return data;
    }

    Node *GetNext()
    {
        return next;
    }

    void SetData(int data)
    {
        this->data = data;
    }

    void SetNext(Node *next)
    {
        this->next = next;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool IsEmpty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }

    void Push(int data)
    {
        Node *newNode = new Node();

        newNode->SetData(data);

        if (top != nullptr)
        {
            newNode->SetNext(top);
            top = newNode;
        }
        else
        {
            top = newNode;
        }
    }

    int Pop()
    {
        if (!IsEmpty())
        {
            int data = top->GetData();
            Node *temp = top;
            top = top->GetNext();
            delete temp;
            return data;
        }
        else
        {
            cout << "Stack is empty. Can't Pop\n";
            return -1;
        }
    }

    bool CheckBalancedParanthesis(string exp)
    {
        if (exp.empty())
        {
            cout << "Expression is empty";
            return false;
        }
        else
        {
            for (int i = 0; i < exp.length(); i++)
            {
                if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
                {
                    int bracket = exp[i];
                    Push(bracket);
                }
                else if (exp[i] == ')')
                {
                    int bracket = exp[i];
                    if (!IsEmpty() && Pop() != bracket - 1)
                        {return false;}
                }
                else if (exp[i] == ']' || exp[i] == '}')
                {
                    int bracket = exp[i];
                    if (!IsEmpty() && Pop() != bracket - 2)
                        return false;
                }
            }
            if (IsEmpty())
                return true;
            else
                return false;
        }
    }

    ~Stack()
    {
        if (top != nullptr)
        {
            Node *current = top;
            Node *next;
            while (current != nullptr)
            {
                next = current->GetNext(); // Traversing to second node before deleting the first node
                delete current;
                current = next;
            }
        }
    }
};

int main()
{
    Stack myStack;
    string exp;
    cout << "Enter expression\n";
    cin >> exp;

    if (myStack.CheckBalancedParanthesis(exp))
    {
        cout << "Before Checking: " << exp << endl;
        cout << "Expression is balanced. Expression: " << exp << endl;
    }
    else
    {
        cout << "Before Checking: " << exp << endl;
        cout << "Expression is not balanced. Expression: " << exp << endl;
    }
    return 0;
}
