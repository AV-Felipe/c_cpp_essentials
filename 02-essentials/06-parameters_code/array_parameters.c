#include<stdio.h>
#include <stdbool.h> // needed to use boolean type

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

// in this approach we will create a rule for the arrays received by our function:
// they will always have an sentinel value at their end.
// On C it is common to use the null character (ASCII value 0) as a sentinel value
// to mark the end of a string, so, for an array of characters, not generated from a string, we may
// add the \0 as the final element, so to mark it as the end of the array - this will obviously
// force us to interpret the size of the array function as a function for the size of the array
// filed with desired data (since \0 will be adding to the array but will not be reflected in the length)
int getStringLength(char A[])
{
    int i = 0;
    bool flag = true;

    while(flag)
    {
        printf("%c and now\n", A[i]);
        i++;
        if (A[i] == '\0')
        {
            flag = false;
        }
        
    }

    return i;
}

int main()
{
    char test[6] = {'f', 'e', 'l', 'i', 'p', 'e'};

    int length = getLength(test);

    printf("wrongly showing size of pointer: %d\n", length); // will print 8 (or the byte size of an int in the processor)

    // this is the same logic of the function, but operated within the scope of the array declaration
    // here we will have the expected result of 6
    int length2 = sizeof(test) / sizeof(test[0]);

    printf("size of array in scope: %d\n", length2); // will print 6, the number of elements in the array

    char test2[7] = {'f', 'e', 'l', 'i', 'p', 'e', '\0'}; // this is a defined char array
    int size = getStringLength(test2);

    printf("array size till sentinel value: %d\n", size);

    char test3[] = "felipe"; // this is the C equivalent of a string type (an array of chars with no predefined type)
    int size2 = getStringLength(test3);

    printf("undefined array size: %d\n", size); // C fills e unused spaces with \0 so in this case the compiler has marked the end of the array for us

    char test4[7] = {'f', 'e', 'l', 'i', 'p', 'e'}; // this is a defined char array with one undefined element
    int size3 = getStringLength(test4);

    printf("array with uninitialized element at end size: %d\n", size3); // as with the string, uninitialized char elements receive a \0 value

    return 0;
}