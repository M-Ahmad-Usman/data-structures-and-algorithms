#include <iostream>
using namespace std;

class Node
{
private:
    int Data;
    Node *Next;

public:
    int GetData()
    {
        return Data;
    }

    Node *GetNext()
    {
        return Next;
    }

    void SetData(int Data)
    {
        this->Data = Data;
    }

    void SetNext(Node *Next)
    {
        this->Next = Next;
    }
};

class List
{
    Node *currentLocation;

public:
    List()
    {
        currentLocation = nullptr;
    }

    void Insert(int data)
    {
        Node *newNode = new Node();
        newNode->SetData(data);
        newNode->SetNext(nullptr);

        // Case 1: If there is not node in the list
        if (currentLocation == nullptr)
        {
            currentLocation = newNode;
            return;
        }

        // Case 2: If there are already some nodes in the list
        Node *lastNode = currentLocation;
        while (lastNode->GetNext() != nullptr)
        {
            lastNode = lastNode->GetNext();
        }
        lastNode->SetNext(newNode);
    }

    ~List() // Destructor to free memory just incase user forgot to free memory
    {
        if (currentLocation != nullptr)
        {
            Node *current = currentLocation;
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
    List myList;
    myList.Insert(1);
    myList.Insert(2);
    
    return 0;
}