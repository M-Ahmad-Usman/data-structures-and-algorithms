#include <iostream>
#include <string>
#include <limits>
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

    T GetTop()
    {
        if (!IsEmpty())
        {
            return arrptr[top];
        }
        else
        {
            throw runtime_error("Stack is empty. Can't get top.");
        }
    }
    
    // Destructor to free the memory allocated to stack
    ~Stack()
    {
        delete[] arrptr;
    }
};

/*
Returns a positive integer representing the precedence of operators. Greater the value greater
the precedence. Returns 0 if operator is not defined  */
int GetOprPrec(char opr)
{
    if (opr == '+' || opr == '-')
    {
        return 1;
    }
    else if (opr == '*' || opr == '/')
    {
        return 2;
    }
    else if (opr == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

/*
Retuns 1 if operator's associativity is left-to-right and 2 if associativity is right-to-left.
Returns 0 if operator is not defined */
int GetOprAssoc(char opr)
{
    if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
    {
        return 1;
    }
    else if (opr == '^')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// Returns true if operator is valid. Valid operators are: "+, -, /, *, ^"
bool IsOprValid(char opr)
{
    if (opr == '+' || opr == '-' || opr == '*' || opr == '/' || opr == '^')
        return true;
    else
        return false;
}

// Retuns a postfix expression of an infix expression. Supports only expressions with operators : " +, -, /, *, ^ "
string InfixToPostfix(string infix)
{
    int size = infix.length();

    // If two consecutive operators occur then an exception will be thrown
    bool consecutiveOpr = false;

    if (size == 0)
    {
        throw runtime_error("Invalid infix expression. Expression can't be empty");
    }

    Stack<char> stk(size);
    string postfix = "";

    // Traversing the whole expression in try block to check whether the infix expression is valid or not

    for (int i = 0; i < size; i++)
    {
        // Checking if ith character is an operand
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            consecutiveOpr = false;

            postfix += infix[i];
        }
        // Ignoring spaces in expression
        else if (infix[i] == ' ')
        {
            continue;
        }
        // Checking if ith character is some opening bracket
        else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{')
        {
            consecutiveOpr = false;

            stk.Push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            consecutiveOpr = false;

            while (stk.GetTop() != '(')
            {
                postfix += stk.Pop();
            }

            // Removing the opening bracket
            stk.Pop();
        }
        else if (infix[i] == ']' || infix[i] == '}')
        {
            consecutiveOpr = false;

            int br = infix[i];

            // The difference of ASCII values btw the opening & closing brackets of [] and {} is of 2
            while (stk.GetTop() != br - 2)
            {
                postfix += stk.Pop();
            }

            // Removing the opening bracket
            stk.Pop();
        }
        // If the ith character is valid operator
        else if (IsOprValid(infix[i]))
        {
            // Variables to store precedences of current operator and operator at the top of stack
            int topOprPrecedence, currOprPrecedence;

            /*
            Variable to store the associativity of current operator.
            Will be used if the precedence of current and stack's top operator is same */
            int currOprAssociativity;

            currOprPrecedence = GetOprPrec(infix[i]);

            while (true)
            {
                if (stk.IsEmpty())
                {
                    if (consecutiveOpr == true)
                    {
                        throw runtime_error("Invalid Infix expression");
                    }

                    consecutiveOpr = true;

                    stk.Push(infix[i]);
                    break;
                }
                else if ((stk.GetTop() == '(' || stk.GetTop() == '[' || stk.GetTop() == '{'))
                {
                    if (consecutiveOpr == true)
                    {
                        throw runtime_error("Invalid Infix expression");
                    }

                    consecutiveOpr = true;

                    stk.Push(infix[i]);
                    break;
                }
                else
                {
                    topOprPrecedence = GetOprPrec(stk.GetTop());

                    if (currOprPrecedence > topOprPrecedence)
                    {
                        if (consecutiveOpr == true)
                        {
                            throw runtime_error("Invalid infix expression");
                        }

                        stk.Push(infix[i]);

                        consecutiveOpr = true;

                        break;
                    }
                    // While loop is used for this case
                    else if (currOprPrecedence < topOprPrecedence)
                    {
                        postfix += stk.Pop();
                    }
                    else
                    {
                        if (consecutiveOpr == true)
                        {
                            throw runtime_error("Invalid infix expression");
                        }

                        consecutiveOpr = true;

                        currOprAssociativity = GetOprAssoc(infix[i]);

                        // If associativity is left to right
                        if (currOprAssociativity == 1)
                        {
                            postfix += stk.Pop();
                            stk.Push(infix[i]);
                            break;
                        }
                        // If associativity is right to left
                        else
                        {
                            stk.Push(infix[i]);
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            throw runtime_error("Expression contain invalid symbols.");
        }
    }

    // Appending all of the operators to the expression
    while (!(stk.IsEmpty()))
    {
        if (stk.GetTop() == '(' || stk.GetTop() == '[' || stk.GetTop() == '{')
        {
            throw runtime_error("Invalid infix expression");
        }

        postfix += stk.Pop();
    }

    return postfix;
}

int main()
{
    bool run = true;
    string infix, postfix;

    while (run)
    {
        cout << "Enter infix expression: ";
        // cin >> infix; // Stops at first whitespace

        // getline(cin, infix); Reads entire line with whitespaces

        getline(cin, infix);

        try
        {
            postfix = InfixToPostfix(infix);
            cout << "Postfix expression: " << postfix << "\n";
        }
        catch (const exception &e)
        {
            cerr << e.what() << '\n';
        }

        cout << "Press 1 to calculate again and 0 to quit.";
        cin >> run;
        cout << "\n";

        /* 
        cin >> run leaves a new line character in the input buffer. 
        To prevent getline() to take that new line as new input, 
        input buffer must be cleaned before taking new string. */
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}