#include <stdio.h>

// here is a style of programming on C that resembles an object orientation
// we define the operations that can be performed in a certain struct into functions and 
// only operate on it using them

// our struct
struct Rectangle
{
    int length;
    int breadth;
};

// a function for initializing its values
void initializeRectangle(struct Rectangle *r, int newLength, int newBreadth)
{
    r->length = newLength;
    r->breadth = newBreadth;
}

// one to extract a computed value based on it's properties
int getAreaForRectangle(struct Rectangle r)
{
    int area;

    area = r.length * r.breadth;

    return area;
}

// one to change one of it's properties values
void changeRectangleLength(struct Rectangle *r, int newLength)
{
    r->length = newLength;
}

int main()
{
    struct Rectangle partyPlace;

    initializeRectangle(&partyPlace, 10, 5);

    printf("the party place will have\nlength: %d\nbreadth: %d\n", partyPlace.length, partyPlace.breadth);

    printf("the area of this place is %d square meters\n", getAreaForRectangle(partyPlace));

    changeRectangleLength(&partyPlace, 15);

    printf("the party place length was adjusted to %d\n", partyPlace.length);

    printf("the area of this place is %d square meters\n", getAreaForRectangle(partyPlace));

    return 0;
}