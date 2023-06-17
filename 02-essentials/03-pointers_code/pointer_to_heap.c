#include <stdio.h>
#include <stdlib.h> // to make available the functions for dealling with the heap (malloc, realloc, calloc, free)

void main()
{
    // here we are initializing the pointer we will use
    // we want to point to a vector of 5 integers, so we use int type
    int* pointerToHeap;

    // the malloc function is used to allocate data in the heap, it takes the size we will need
    // since we don't know the size the particular processor uses to allocate an integer, we
    // set it programmatically, by using the function sizeof in the integer type and multiplying it by
    // the number of elements we will want in our array. The malloc returns an address to the heap location.
    // Also, the malloc returns a void* pointer, by default, so, in this case, we must explicitly cast it
    // to integer type (int*) - without it the code would compile until we needed to access the pointer data.
    pointerToHeap =(int*)malloc(5 * sizeof(int));

    printf("address on the heap: %p\n", pointerToHeap);

    // here we don't need to dereference the data because in C, when we access array elements,
    // we are implicitly dereferencing the index:
    // array[i] is equivalent to *(array + i)
    printf("array data in position 0: %d\n", pointerToHeap[0]);

    // to set the values we must point to each element in the array,
    // pointerToHeap = {1, 2, 3, 4, 5};
    // will not work
    for (int i = 0; i < 5; i++) {
        pointerToHeap[i] = i + 1;
    }

    // Print the array elements
    for (int i = 0; i < 5; i++) {
        printf("%d ", pointerToHeap[i]);
    }
    printf("\n");

    // cleans/deallocates the used heap memory
    free(pointerToHeap);
}