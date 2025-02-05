#include <iostream>
using namespace std;

template <typename T>
class Node
{

private:
    T data;
    Node *next;

public:
    // Constructors
    Node() { next = nullptr; }

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }

    Node(T data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    // Getters
    T GetData() { return data; }

    Node *GetNext() { return next; }

    // Setters
    void SetData(T data) { this->data = data; }

    void SetNext(Node *next) { this->next = next; }
};

template <typename Q>
class LinkedQueue
{
private:
    Node<Q> *front;
    Node<Q> *rear;

    /* Queue visualization
        front ------------ rear
        1. Data is enqueued on "rear".
        2. Data is dequeued from "front".
    */

public:
    // Constructor
    LinkedQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void Enqueue(Q data)
    {
        Node<Q> *newNode = new Node(data);

        if (IsEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->SetNext(newNode);
            rear = rear->GetNext();
        }
    }

    Q Dequeue()
    {
        // Case 1: If Queue is empty
        if (IsEmpty())
        {
            throw runtime_error("Queue is empty. Can't Dequeue.");
        }

        Q data = front->GetData();

        // Case 2: If Queue has only one node
        if (front == rear)
        {
            delete rear;

            front = nullptr;
            rear = nullptr;

            return data;
        }

        // Case 3: If Queue has more than one node
        Node<Q> *tmp = front;

        front = front->GetNext();

        delete tmp;

        return data;
    }

    void PrintQueue()
    {
        if (IsEmpty())
            return;

        Node<Q> *current = front;

        while (current->GetNext() != nullptr)
        {
            cout << current->GetData() << "->";
            current = current->GetNext();
        }

        cout << current->GetData() << "\n";
    }

    bool IsEmpty() { return (front == nullptr && rear == nullptr); }

    Q GetFront()
    {
        if (IsEmpty())
            throw runtime_error("Queue is empty. Can't get front.");

        else
            return front->GetData();
    }

    ~LinkedQueue()
    {
        Node<Q> *tmp = front;
        Node<Q> *next;

        while (tmp != nullptr)
        {
            next = tmp->GetNext();
            delete tmp;
            tmp = next;
        }
    }
};

int main()
{
    LinkedQueue<int> queue;

    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    cout << "Queue: ";
    queue.PrintQueue();

    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    cout << "Queue: ";
    queue.PrintQueue();
    return 0;
}