#include <iostream>
using namespace std;

template <typename T>
class ArrayQueue
{
    // Data Memebers
    T *arrptr;
    int front;
    int rear;
    int size;

    /* Queue visualization
        front ------------ rear
        1. Data is enqueued on "rear".
        2. Data is dequeued from "front".
    */

public:
    // Constructor
    ArrayQueue(int size)
    {
        if(size <= 0)
        {
            throw runtime_error("Queue size must be greater than 0.");
        }
        
        front = -1;
        rear = -1;

        this->size = size;
        arrptr = new T[size];
    }

    void Enqueue(T data)
    {
        if (IsFull())
        {
            throw runtime_error("Queue is full. Can't enqueue more elements");
        }

        if (IsEmpty())
        {
            front++;
            rear++;

            arrptr[rear] = data;
        }
        else
        {
            rear = (rear+1) % size;

            arrptr[rear] = data;
        }
    }

    T Dequeue()
    {
        if (IsEmpty())
        {
            throw runtime_error("Queue is empty. Can't Dequeue.");
        }

        if (front == rear)
        {
            T data = arrptr[front];
            front = -1;
            rear = -1;
            return data;
        }
        else
        {
            T data = arrptr[front];
            front = (front+1) % size;
            return data;
        }
    }

    void PrintQueue()
    {
        if (IsEmpty())
            return;

        int current = front;
        while (true)
        {
            cout << arrptr[current] << " ";
            if (current == rear)
                break;
            current = (current + 1) % size;
        }
        cout << endl;
    }

    bool IsEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool IsFull()
    {
        if ((rear + 1) % size == front)
            return true;
        else
            return false;
    }

    T GetFront()
    {
        if (IsEmpty())
            throw runtime_error("Queue is empty. Can't get front");

        return arrptr[front];
    }

    // Destructor
    ~ArrayQueue()
    {
        delete[] arrptr;
    }
};