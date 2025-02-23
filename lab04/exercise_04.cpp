#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    // Constructors
    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data, Node *next)
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

class List
{
    Node *head;

public:
    List()
    {
        head = nullptr;
    }

    void Insert(int data)
    {
        Node *newNode = new Node(data, nullptr);

        // Case 1: If there is not node in the list
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // Case 2: If there are already some nodes in the list
        Node *lastNode = head;
        while (lastNode->GetNext() != nullptr)
        {
            lastNode = lastNode->GetNext();
        }
        lastNode->SetNext(newNode);
    }

    void Print()
    {
        // Case 1: If list is empty
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        // Case 2: If list is not empty
        Node *temp = head;
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
        if (head == nullptr)
        {
            cout << "Can't delete from an empty list.\n";
            return;
        }

        // Case 2.: If first node contains the data
        if (head->GetData() == dataToDelete)
        {
            Node *temp = head;
            head = head->GetNext(); // If list contains one node or more than one node. This line handles both cases.
            delete temp;
            return;
        }

        // Case 2.1: If there is only one node and it does not contains the required data
        if (head->GetNext() == nullptr)
        {
            cout << "Data not found.\n";
            return;
        }

        // Case 3: If there are more than one nodes
        Node *nodeToDelete = head->GetNext();
        Node *previous = head;

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
        if (head == nullptr || head->GetNext() == nullptr)
        {
            cout << "List contains less than 2 nodes.\n";
            return;
        }

        Node *firstNode = head;
        Node *secondNode = head->GetNext();

        while (secondNode != nullptr)
        {
            if (firstNode->GetData() == firstNodeData && secondNode->GetData() == secondNodeData)
            {
                Node *newNode = new Node(data, secondNode);

                firstNode->SetNext(newNode);
                return;
            }

            firstNode = firstNode->GetNext();
            secondNode = secondNode->GetNext();
        }

        cout << "No two adjacent nodes found with given data.\n";
    }

    int FindMinimum()
    {
        if (head == nullptr)
        {
            throw runtime_error("List is empty. Can't find minimum value from an empty list.");
        }

        int minimum = head->GetData();
        Node *current = head;
        while (current != nullptr)
        {
            if (minimum > current->GetData())
            {
                minimum = current->GetData();
            }

            current = current->GetNext();
        }

        return minimum;
    }

    int FindMaximum()
    {
        if (head == nullptr)
        {
            throw runtime_error("List is empty. Can't find maximum value from an empty list.");
        }

        int maximum = head->GetData();
        Node *current = head;
        while (current != nullptr)
        {
            if (maximum > current->GetData())
            {
                maximum = current->GetData();
            }

            current = current->GetNext();
        }

        return maximum;
    }

    bool Search(int dataToSearch)
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *current = head;
        while (current != nullptr)
        {
            if (dataToSearch == current->GetData())
            {
                return true;
            }
            current = current->GetNext();
        }

        return false; // If data is not found after searching in whole list.
    }

    // Inserts data at given index in the list. Indexing starts from 0. Index:1 means node will be after head and before the node which was after the head.
    void InsertAt(int data, int index)
    {
        if (index < 0)
        {
            cout << "Index cannot be negative. Please enter a positive value.\n";
            return;
        }

        if (index == 0)
        {
            Node *newNode = new Node(data, head);
            head = newNode;
            return;
        }

        Node *current = head->GetNext();
        Node *previous = head;
        int counter = 0;
        while (current != nullptr)
        {
            if (counter == index)
            {
                Node *newNode = new Node(data, current);
                previous->SetNext(newNode);
                return;
            }
            counter++;
            current = current->GetNext();
            previous = previous->GetNext();
        }

        if (current == nullptr)
        {
            cout << "Index not found in the list.\n";
        }
    }

    // Swaps the data of two nodes on given indices. Indices need not to be consecutive.
    void Swap(int indexOfNode1, int indexOfNode2)
    {
        if (head == nullptr || head->GetNext() == nullptr)
        {
            cout << "Can't swap. List has less than 2 nodes.\n";
            return;
        }

        // Finding first node
        Node *node1 = head;
        int index1= 0;

        while (node1 != nullptr)
        {
            if (index1 == indexOfNode1)
            {
                break;
            }
            index1++;
            node1 = node1->GetNext();
        }

        // Findind second node
        Node *node2 = head;
        int index2 = 0;

        while (node2 != nullptr)
        {
            if (index2 == indexOfNode2)
            {
                break;
            }
            index2++;
            node2 = node2->GetNext();
        }

        if (node1 == nullptr || node2 == nullptr)
        {
            cout << "Indices are invalid.\n";
            return;
        }

        // Swapping
        int temp = node1->GetData();
        node1->SetData(node2->GetData());
        node2->SetData(temp);
    }

    void Sort()
    {
        if (head == nullptr)
        { return; }

        int size = 0;
        Node *current = head;
        while (current != nullptr)
        {
            size++;
            current = current->GetNext();
        }

        current = head;
        for (int i = 0; i < size-1; i++)
        {
            for (int j = 0; j < (size - i - 1); j++)
            {
                if (current->GetData() > current->GetNext()->GetData())
                {
                    int temp = current->GetData();
                    current->SetData(current->GetNext()->GetData());
                    current->GetNext()->SetData(temp);
                }
                current = current->GetNext();
            }
            current = head;
        }
    }

    // Inserts a node at its sorted place in a list. Given list must be already sorted
    void InsertInSorted (int data)
    {
        Node *newNode = new Node (data, nullptr);

        // Case 1: If list is empty
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        // Case 2: If the item to be inserted should be at head position
        if (data <= head->GetData())
        {
            newNode->SetNext(head);
            head = newNode;
            return;
        }

        // Case 3: If item to be inserted should be in somewhere between the list
        Node *current = head->GetNext();
        while (current->GetNext() != nullptr)
        {
            if (data <= current->GetNext()->GetData())
            {
                newNode->SetNext(current->GetNext());
                current->SetNext(newNode);
                return;
            }
            current = current->GetNext();
        }

        // Case 4: If the item to be inserted should be at the last of the list
        current->SetNext(newNode);

    }

    ~List() // Destructor to free memory just incase user forgot to free memory
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

int main()
{
    List myList;

    myList.InsertInSorted(1); // Testing Case 1

    myList.Insert(2);
    myList.Insert(3);
    myList.Insert(5);
    myList.Insert(6);
    myList.Insert(7);
    myList.Insert(8);

    myList.InsertInSorted(0); // Testing Case 2
    myList.InsertInSorted(3); // Testing Case 3
    myList.InsertInSorted(4); // Testing Case 3
    myList.InsertInSorted(9); // Testing Case 4
    return 0;
}