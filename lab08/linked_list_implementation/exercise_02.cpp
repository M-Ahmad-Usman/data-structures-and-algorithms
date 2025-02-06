#include <iostream>
#include "exercise_01.cpp"
using namespace std;

int main ()
{
    LinkedQueue<int> lst; 
    lst.PrintQueue(); 
     
    lst.Enqueue(100); 
    lst.PrintQueue(); 
     
    lst.Enqueue(200); 
    lst.PrintQueue(); 
     
    lst.Enqueue(300); 
    lst.PrintQueue(); 
     
    lst.Enqueue(400); 
    lst.PrintQueue(); 

    cout << "The Fornt element is " << lst.GetFront() << "\n\n";

    return 0;
}