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

        while (current->GetNext() != nullptr)
        {
            current = current->GetNext();
        }

        current->SetNext(newNode);
        newNode->SetPrevious(current);
    }

    void DeleteNode(int dataToDelete)
    {
        if (head == nullptr)
        {
            cout << "Can't delete from an empty list.\n";
            return;
        }

        // Case 1: If first node has to be deleted
        if (head->GetData() == dataToDelete)
        {
            Node *temp = head;
            head = head->GetNext();

            // Case 1.1: If list has only one node. Then head's previous pointer cannot be updated. head's next pointer will already be set to nullptr.
            if (head == nullptr)
            {
                delete temp;
                return;
            }
            // Case 1.2: If list has more than one node. Then head's previous pointer should be set to nullptr. Since there is no node behind head.
            else
            {
                head->SetPrevious(nullptr);
                delete temp;
                return;
            }
        }

        // Case 2: If node to be deleted is not first node.
        Node *current = head->GetNext(); // Since first node has already been checked.

        while (current != nullptr)
        {
            if (current->GetData() == dataToDelete)
            {
                current->GetPrevious()->SetNext(current->GetNext()); // Setting the previous node of current node to point to the next node of current node. Since current node has to be deleted

                // Case 2.1: If there are some nodes after current
                if (current->GetNext() != nullptr)
                {
                    current->GetNext()->SetPrevious(current->GetPrevious()); // Setting the previous of current's next node to point to the current's previous node. Since current has to be deleted
                    delete current;
                    return;
                }
                // Case 2.2: If there is not any node after current.
                else
                {
                    delete current;
                    return;
                }
            }
            current = current->GetNext();
        }

        // Case 3:
        cout << "No node found with given data.\n";
    }

    void PrintList()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Can't Print anything.\n";
            return;
        }

        Node *current = head;
        while (current->GetNext() != nullptr)
        {
            cout << current->GetData() << "->";
            current = current->GetNext();
        }
        cout << current->GetData() << "\n";

    }

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

int main ()
{
    DoublyList list;

    list.InsertNode(1);
    list.InsertNode(2);
    list.InsertNode(3);
    list.InsertNode(4);
    list.InsertNode(5);
    list.InsertNode(6);
    list.InsertNode(7);

    list.PrintList();

    list.DeleteNode(1);
    list.DeleteNode(2);
    list.DeleteNode(3);
    list.DeleteNode(4);
    list.DeleteNode(5);
    list.DeleteNode(6);
    list.DeleteNode(7);    

    list.PrintList();
    
    return 0;
}