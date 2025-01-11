#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:

    //Constructors
    Node()
    {
        data = NULL;
        next = nullptr;
    }

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    int GetData()
    {
        return this->data;
    }

    Node *GetNext()
    {
        return this->next;
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