#include <iostream>

using namespace std;

// with classes we have actual object orientation

class Rectangle
{
    // Data members
private: // access specifier - set the following elements to be accessible only from within the class scope
    int length;
    int breadth;

    // Functions
public: // set the following class elements to be accessible from the scope where a class is instantiated
    // void initializeRectangle(int newLength, int newBreadth)
    // {
    //     length = newLength;
    //     breadth = newBreadth;
    // }
    Rectangle(int newLength, int newBreadth) // by setting a function with the class name we define the constructor method for it
    {
        length = newLength;
        breadth = newBreadth;
    }

    int getAreaForRectangle()
    {
        int area;

        area = length * breadth;

        return area;
    }

    void changeRectangleLength(int newLength)
    {
        length = newLength;
    }
};

int main()
{
    // Rectangle partyPlace; // here we instantiated an rectangle object

    // partyPlace.initializeRectangle(10, 5); // here we call the method for initializing it

    // instead of the above, we use the constructor method to declare and initialize the object in a single movement
    Rectangle partyPlace(10, 5);

    // we no longer have direct access to this properties, they are private to the class
    // either we make then public or we define methods por accessing them
    // printf("the party place will have\nlength: %d\nbreadth: %d\n", partyPlace.length, partyPlace.breadth);

    printf("the area of this place is %d square meters\n", partyPlace.getAreaForRectangle());

    partyPlace.changeRectangleLength(15);

    // printf("the party place length was adjusted to %d\n", partyPlace.length);

    printf("the area of this place is %d square meters\n", partyPlace.getAreaForRectangle());

    return 0;
}