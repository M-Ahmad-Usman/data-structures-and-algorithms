#include <iostream>
using namespace std;

class Distance 
{
    private:
        int feet;
        float inches;

    public:
    void set(int ft, float in) 
    {
        feet = ft;
        inches = in;
    }

    void disp() 
    {
        cout << "Distance: " << feet << " feet " << inches << " inches" << endl;
    }

    Distance add(Distance d1, Distance d2) 
    {
        Distance sum;
        sum.feet = d1.feet + d2.feet;
        sum.inches = d1.inches + d2.inches;
        return sum;
    }
};

int main() {
    Distance d1, d2, d3;

    d1.set(5, 6.5);
    d2.set(3, 8.25);

 
    d3 = d3.add(d1, d2);

    cout << "Distance 1: ";
    d1.disp();
    cout << "Distance 2: ";
    d2.disp();
    cout << "Sum of Distance 1 and Distance 2: ";
    d3.disp();

    char screenshot;
    cin >> screenshot; // For taking output's screenshot
    return 0;
}
