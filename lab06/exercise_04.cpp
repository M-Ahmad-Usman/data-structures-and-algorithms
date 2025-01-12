#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    // Constructors
    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    // Getters
    int GetData()
    {
        return this->data;
    }

    Node *GetNext()
    {
        return this->next;
    }

    // Setters
    void SetData(int data)
    {
        this->data = data;
    }

    void SetNext(Node *next)
    {
        this->next = next;
    }
};

class CircularList
{
    Node *head;

public:

    // Constructor
    CircularList()
    {
        head = nullptr;
    }

    void Insert (int data)
    {
        Node *newNode = new Node (data);

        if (head == nullptr)
        {
            head = newNode;
            head->SetNext(head);
            return;
        }

        Node *current = head;
        while (current->GetNext() != head)
        {
            current = current->GetNext();
        }
        current->SetNext(newNode);
        newNode->SetNext(head);
    }

    void Print ()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Can't Print from and empty list.\n";
            return;
        }
        Node *current = head;
        while (current->GetNext() != head)
        {
            cout << current->GetData() << "->";
            current = current->GetNext();
        }
        cout << current->GetData() << "\n";
    }

    void Delete (int dataToDelete)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Can't delete from an empty list.\n";
            return;
        }

        // Case 1: If node to be deleted is first node
        if (head->GetData() == dataToDelete)
        {
            Node *temp = head;
            head = head->GetNext();
            
            // Case 1.1: If there was only one node
            if (temp == head)
            {
                delete temp;
                head = nullptr;
                return;
            }
            // Case 1.2 If there are more than one nodes in the list
            else
            {
                Node *current = head;

                // Since in circular list last node has the address of head. So after changing head we have to update the last node's next pointer to point to the new head node not the older one which will be deleted.
                while (current->GetNext() != temp)
                {
                    current = current->GetNext();
                }
                current->SetNext(head);

                delete temp;
                return;
            }
        }

        // Case 2: If there is only one node and that node hasn't to be deleted (Case 1)
        if (head->GetNext() == head)
        {
            cout << "List doesn't has a node with specified data.\n";
            return;
        }

        // Case 3: If node to be deleted is not the first node and is in somewhere middle (not at the end) and there are more than one nodes in the list (Case 2).
        Node *current = head->GetNext();
        Node *previous = head;
        while (current->GetNext() != head)
        {
            if (current->GetData() == dataToDelete)
            {
                previous->SetNext(current->GetNext());
                delete current;
                return;
            }
            current = current->GetNext();
            previous = previous->GetNext();
        }

        // Case 4: If last node (case 3) has given data
        if (current->GetData() == dataToDelete)
        {
            previous->SetNext(head);
            delete current;
            return;
        }

        // Case 5: If list hasn't given data (case 1,2,3,4)
        cout << "List doesn't has a node with specified data.\n";

    }

    ~CircularList()
    {
        if (head != nullptr)
        {
            Node *current = head;
            Node *next;

            while (current->GetNext() != head)
            {
                next = current->GetNext();
                delete current;
                current = next;
            }

            delete current;
        }
    }
};

int main()
{
    CircularList list;

    list.Delete(1);
    list.Print();

    list.Insert(1);
    list.Print();
    list.Delete(1);
    list.Print();

    list.Insert(1);
    list.Insert(2);
    list.Print();
    list.Delete(1);
    list.Print();
    list.Insert(1);
    list.Delete(2);
    list.Print();

    list.Insert(2);
    list.Insert(3);
    list.Print();
    list.Delete(3);
    list.Delete(2);
    list.Delete(1);
    list.Print();
    return 0;
}