#include<iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main () 
{
    //in C++ syntax we don't need to state struct previous to declaring/instantiating a new instance
    Rectangle r = {10, 5};

    // here we initialized a pointer to the address of the struct
    Rectangle* p = &r;
    cout << p << endl;
    cout << p->breadth << endl;
    cout << p->length << endl;

    // now we will create a pointer to some data we will dynamically populate in the heap
    Rectangle* heapPointer;
    heapPointer = new Rectangle;
    //now we assign values to the struct properties
    heapPointer->length = 15;
    heapPointer->breadth = 10;

    cout << "length in heap: " << heapPointer->length << endl << "breadth in heap: " << heapPointer->breadth << endl;

    delete heapPointer;

    return 0;
}
