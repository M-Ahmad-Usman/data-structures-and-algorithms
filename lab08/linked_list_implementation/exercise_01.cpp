#include <stdio.h>
using namespace std;

template <typename T>
class Node;

int main()
{
    return 0;
}

template <typename T>
class Node
{

private:
    T data;
    Node *next;

public:

    // Constructors
    Node () { next = nullptr;}

    Node (T data)
    {
        this->data = data;
        next = nullptr;
    }

    Node (T data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    // Getters
    T GetData() { return data; }

    Node *GetNext() { return next; }

    // Setters
    void SetData(T data) { this->data = data; }

    void SetNext(Node *next) { this->next = next; }
};
