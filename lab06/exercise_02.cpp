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

class DoublyList
{
private:
    Node *head;

public:
    DoublyList()
    {
        head = nullptr;
    }

    void InsertNode(int data)
    {
        Node *newNode = new Node();
        newNode->SetData(data);

        // Case 1: If list has no node
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // Case 2: If list has already some nodes
        Node *current = head;
        
        while(current->GetNext() != nullptr)
        {
            current = current->GetNext();
        }

        current->SetNext(newNode);
        newNode->SetPrevious(current);
    }
    
    void DeleteNode(int);
    void PrintList();

    ~DoublyList() // Destructor to free memory just incase user forgot to free memory
    {
        if (head != nullptr)
        {
            Node *current = head;
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