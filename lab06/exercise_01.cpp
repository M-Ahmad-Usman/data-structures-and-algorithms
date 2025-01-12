#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *previous;

public:

    Node()
    {
        data = 0;
        next = nullptr;
        previous = nullptr;
    }

    int GetData()
    { 
        return this->data; 
    }
    
    void SetData(int data)
    { 
        this->data = data; 
    }

    Node *GetNext()
    { 
        return this->next; 
    }

    void SetNext(Node *nextNode)
    { 
        this->next = nextNode; 
    }

    Node *GetPrevious()
    { 
        return this->previous; 
    }

    void SetPrevious(Node *prevNode)
    { 
        this->previous = prevNode; 
    }
};