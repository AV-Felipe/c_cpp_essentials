#include<iostream>

using namespace std;

int main()
{
    int* pointerToHeap;

    // the syntax in C++ is a lot simpler
    pointerToHeap = new int[5];

    // we still can use C syntax
    printf("address on the heap: %p\n", pointerToHeap);

    // or C++
    cout << "array data in position 0: " << pointerToHeap[0] << endl;

    // to set the values we must point to each element in the array,
    // pointerToHeap = {1, 2, 3, 4, 5};
    // will not work
    for (int i = 0; i < 5; i++) {
        pointerToHeap[i] = i + 1;
    }

    // Print the array elements
    for (int i = 0; i < 5; i++) {
        cout << pointerToHeap[i] << " ";
    }
    printf("\n");

    // cleans/deallocates the used heap memory
    // this is crucial, specially in big projects
    //
    delete [] pointerToHeap;

    return 0;
}