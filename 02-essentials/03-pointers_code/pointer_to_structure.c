#include<stdio.h>
#include<stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

void main () 
{
    struct Rectangle r = {10, 5};

    // here we initialized a pointer to the address of the struct
    struct Rectangle* p = &r;
    printf("%p\n", p);

    // to access a property of the struct referenced by the pointer we cannot use the dot syntax
    // directly over the pointer variable. The dot syntax has a higher precedence than the the 
    // pointer, so, instead off following the pointer and looking for the property, it would be
    // looking for the property in the pointer itself.
    //printf("%d", p.length); // wont compile
    // What we have to do is one of the following
    printf("%d\n", (*p).length);
    // above we forced the precedence using parentheses
    // but we can also use the arrow syntax
    printf("%d\n", p->length);

    // now we will create a pointer to some data we will dynamically populate in the heap
    struct Rectangle* heapPointer;
    heapPointer = (struct Rectangle*) malloc(sizeof(struct Rectangle));
    //now we assign values to the struct properties
    heapPointer->length = 10;
    heapPointer->breadth = 5;

    printf("length in heap: %d\nbreadth in heap: %d\n", heapPointer->length, heapPointer->breadth);

    free(heapPointer);
}
