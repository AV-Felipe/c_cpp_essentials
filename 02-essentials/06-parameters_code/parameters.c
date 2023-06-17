#include<stdio.h>

// a function which takes an n sized array of char elements and returns it's length
// UNFORTUNATELY, as is it will return the size of a pointer in bytes, since
// an array type, as argument, is actually a pointer to the first element of the array
// so, here, we are getting the pointer size (8 bytes) and dividing by the size of a char (1 byte)
// we always will get 8 (in my current processor) regardless of the array length
int getLength(char A[])
{
    int length;
    // the sizeof calculates the size of the element in bytes
    // so we are getting the total size of the array and dividing
    // by the size of one element to get the number of elements [of that size]
    // we could also use the size of the data type of the element
    length = sizeof(A) / sizeof(A[0]);

    return length;
}

int getCorrectLength(char A[])
{
    int i;

    for(i = 0; i < 10; i++)
    {
        printf("%c and now\n", A[i]);
    }

    return i;
}

int main()
{
    char test[6] = {'f', 'e', 'l', 'i', 'p', 'e'};

    int length = getLength(test);

    printf("%d\n", length); // will print 8 (or the byte size of an int in the processor)

    // this is the same logic of the function, but operated within the scope of the array declaration
    // here we will have the expected result of 6
    int length2 = sizeof(test) / sizeof(test[0]);

    printf("%d\n", length2); // will print 6, the number of elements in the array

    int size = getCorrectLength(test);

    return 0;
}