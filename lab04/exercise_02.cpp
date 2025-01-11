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

        // Case 2.: If first node contains the data
        if (currentLocation->GetData() == dataToDelete)
        {
            Node *temp = currentLocation;
            currentLocation = currentLocation->GetNext(); // If list contains one node or more than one node. This line handles both cases.
            delete temp;
            return;
        }

        // Case 2.1: If there is only one node and it does not contains the required data
        if (currentLocation->GetNext() == nullptr)
        {
            cout << "Data not found.\n";
            return;
        }

        // Case 3: If there are more than one nodes
        Node *nodeToDelete = currentLocation->GetNext();
        Node *previous = currentLocation;

        // Case 3.1: If node to delete is some middle node. The loop breaks when nodeToDelete reaches last node. It does not check whether last node contains required data or not.
        while (nodeToDelete->GetNext() != nullptr)
        {
            if (nodeToDelete->GetData() == dataToDelete)
            {
                previous->SetNext(nodeToDelete->GetNext());
                delete nodeToDelete;
                return;
            }
            nodeToDelete = nodeToDelete->GetNext();
            previous = previous->GetNext();
        }

        // Case 3.2: If the node to be deleted is last node
        if (nodeToDelete->GetData() == dataToDelete)
        {
            previous->SetNext(nullptr);
            delete nodeToDelete;
            return;
        }
        else // Case 4: If data is not found after traversing whole list
            cout << "Data not found.\n";
    }

    void AddBetween(int data, int firstNodeData, int secondNodeData)
    {
        if (currentLocation == nullptr || currentLocation->GetNext() == nullptr)
        {
            cout << "List contains less than 2 nodes.\n";
            return;
        }

        Node *firstNode = currentLocation;
        Node *secondNode = currentLocation->GetNext();

        while (secondNode != nullptr)
        {
            if (firstNode->GetData() == firstNodeData && secondNode->GetData() == secondNodeData)
            {
                Node *newNode = new Node();
                newNode->SetData(data);
                firstNode->SetNext(newNode);
                newNode->SetNext(secondNode);
                return;
            }

            firstNode = firstNode->GetNext();
            secondNode = secondNode->GetNext();
        }

        cout << "No two adjacent nodes found with given data.\n";
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

    // Testing AddBetween()
    myList.AddBetween(1, 2, 3); // If list is empty
    myList.Insert(1);
    myList.Insert(3);

    myList.AddBetween(2, 1, 4);
    myList.AddBetween(2, 2, 3);
    myList.AddBetween(2, 1, 3);

    myList.Insert(4);
    myList.Insert(5);
    myList.Insert(6);

    myList.AddBetween(7, 5, 6);

    return 0;
}