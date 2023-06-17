#include <stdio.h>

void main()
{
    // here we declare and initialize a variable with an integer
    int valueVariable;
    valueVariable = 10;

    // here we declare a pointer to a integer value
    // we do this by defining the type of data we are pointing to and marking it with the *
    // we call the * the indirection operator or dereference operator
    int *pointerVariable;
    // here we initialize the pointer, we point it to a integer variable
    // for this we use the reference operator: &
    pointerVariable = &valueVariable;

    printf("%d\n", valueVariable);

    // here we are printing the pointer itself - it will show the address used for the reference
    printf("%p\n", pointerVariable);

    // here we print the referred value to which the pointer is pointing
    printf("%d\n", *pointerVariable);

    // if we change the value of the referenced variable, the value in the pointer will remain the same
    valueVariable = 15;
    printf("%p\n", pointerVariable);
    printf("%d\n", *pointerVariable);

    int i = 0;

    for (i; i <= 15; i++)
    {
        valueVariable = i;
        printf("the address whe are pointing: %p\n", pointerVariable);
        printf("the value within this address: %d\n", *pointerVariable);
    }

    // i can get the address for an value variable, without referencing it in a pointer
    printf("the address of valueVariable is: %p\n", &valueVariable);

    // also, we can take advantage of the address within the pointer to handle it's referenced data
    printf("the address whe are pointing: %p\n", pointerVariable);
    printf("the value within this address: %d\n", *pointerVariable);
    // by dereferencing the pointer we access the address in memory (the data) it is pointing to
    *pointerVariable = 20;
    printf("the new value within valueVariable: %d\n", valueVariable);

    // concerning the size of pointers, every pointer has the same size,
    // regardless of the data it is pointing to
    int *p1;
    char *p2;
    float *p3;
    double *p4;

    printf("int size: %lu\n", sizeof(int)); //4 bytes (32bits)
    printf("int pointer size: %lu\n", sizeof(p1)); //8 bytes (64bits)
    printf("char size: %lu\n", sizeof(char)); //1 byte (8bits)
    printf("char pointer size: %lu\n", sizeof(p2)); //8 bytes (64bits)
    printf("float size: %lu\n", sizeof(float)); //4 bytes (32bits)
    printf("float pointer size: %lu\n", sizeof(p3)); //8 bytes (64bits)
    printf("double size: %lu\n", sizeof(double)); //8 bytes (64bits)
    printf("double pointer size: %lu\n", sizeof(p4)); //8 bytes (64bits)

}