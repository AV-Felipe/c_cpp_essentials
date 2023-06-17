#include<stdio.h> // this header includes some basic input output functions from c (printf, scanf, fprintf, fscanf)
// the void before the main function signalizes it will not return any data, we may also se it returning an int, in this case we will end the main with return 0;
void main()
{
    printf("Hello array\n");

    int MyArrayA[3];
    MyArrayA[0] = 10;
    MyArrayA[1] = 20;
    MyArrayA[2] = 30;

    /*
    *  here we are using a format pattern, %d signalizes a placeholder for an integer
    *  we could %s for a string, %c for a character, %f for a float...
    */ 
    printf("%d\n", MyArrayA[0]);
    printf("%d %d\n", MyArrayA[0], MyArrayA[1]);

    // here we will declare and initialize an array in the same step
    char MyArrayB[6] = {'f', 'e', 'l', 'i', 'p', 'e'};

    // and here we are using a for loop to print each element of an array of characters
    int i;
    for(i=0; i<6; i++)
    {
        printf("%c", MyArrayB[i]);
        if (i == 5)
        {
            printf("\n");
        }
    }

}
/*
*  to try this code we must compile it with:
*  gcc array.c
*  which will generate a file called a.out that is our executable file:
*   ./a.out
*  will print in the terminal:
*   Hello array
*   10
*   10 20
*   felipe
*
*  When compiling, we may place the flag -o and provide a custom name for the file:
*   gcc array.c -o print_my_arrays
*/

/*
*  Concerning the memory usage of the code we can check it using the following procedure:
*   size a.out 
*  This will show, in bytes, the amount of memory used for the code (text), the memory used for 
*  for initialized global and static variables (data) and for uninitialized ones (bss). Dec and 
*  hex columns of the return represent the total memory used (text + data + bss) in decimal and hex.
*/