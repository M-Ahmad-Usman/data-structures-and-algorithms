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

    void Print()
    {
        // Case 1: If list is empty
        if (currentLocation == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        // Case 2: If list is not empty
        Node *temp = currentLocation;
        while (temp->GetNext() != nullptr)
        {
            cout << temp->GetData() << "->";
            temp = temp->GetNext();
        }
        cout << temp->GetData() << "\n";
    }

    void Delete(int dataToDelete)
    {
        // Case 1: If list is empty
        if (currentLocation == nullptr)
        {
            cout << "Can't delete from an empty list.\n";
            return;
        }

        // Case 2: If list is not empty
        Node *nodeToDelete = currentLocation->GetNext();
        Node *previous = currentLocation;

        // Case 2.1: If node to be deleted is first node
        if (currentLocation->GetData() == dataToDelete)
        {
            currentLocation = currentLocation->GetNext();
            delete previous;
            return;
        }

        // Case 2.2: If node to be deleted is not first node
        while(nodeToDelete != nullptr)
        {
            if (nodeToDelete->GetData() == dataToDelete)
            {
                previous->SetNext(nodeToDelete->GetNext());
                delete nodeToDelete;
                break;
            }
            nodeToDelete = nodeToDelete->GetNext();
            previous = previous->GetNext();
        }

        // Case 3: If data is not found
        if (nodeToDelete == nullptr)
        cout << "Data not found.\n";
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

    myList.Delete(1); // Testing Case 1

    myList.Insert(1);

    myList.Delete(2); // Testing Case 3

    myList.Delete(1); // Testing Case 2.1

    myList.Insert(2);
    myList.Insert(4);

    myList.Print();

    myList.Delete(4); // Testing Case 2.2

    myList.Print();

    return 0;
}