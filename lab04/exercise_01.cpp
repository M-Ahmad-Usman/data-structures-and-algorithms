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

int main()
{
    return 0;
}