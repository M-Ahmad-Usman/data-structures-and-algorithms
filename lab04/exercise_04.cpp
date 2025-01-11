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
        data = 0;
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

int main ()
{
    List myList;

    try
    {
        int maximum = myList.FindMaximum();
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }

    myList.Insert(1);
    myList.Insert(2);
    myList.Insert(3);
    myList.Insert(4);
    myList.Insert(5);
    myList.Insert(6);
    myList.Insert(0);

    try
    {
        int maximum = myList.FindMinimum();
        cout << "The maximum number in the list is " << maximum << "\n";
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}