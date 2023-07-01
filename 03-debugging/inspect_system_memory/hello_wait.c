#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for picking command line arguments, on c, we use two arguments on main, the first is an int
// that will register the number o space separated values after the program call,
// the second is a vector of pointers to characters each containing one of the arguments provided
// the output is at least one, since the program name is passed bay default, som even if we don't pass
// we will have a return of 1 argument and the program name
int main(int argc, char *argv[])
{

    printf("you have entered %d arguments on app execution\n", argc);
    
    for(int i = 0; i < argc; ++i)
    {
        printf("data: %s\n", argv[i]);
    }
    
    
    /*
    *  in the following you may chose to play around passing command line arguments to the heap
    *  and block the code execution with a getchar() - that will keep the app running until you press
    *  enter on the terminal or you may chose to comment this part and play with the debugging
    *  break points (the code will remain in memory running, when in a break point)
    */
   
    // char *pointerToHeap = malloc(strlen(argv[1]) + 1);
    // strcpy(pointerToHeap, argv[1]);
    //getchar();

    char frase[20] = "hello from the heap!";
    char *pointerToHeap = malloc(strlen(frase) + 1);
    strcpy(pointerToHeap, frase);
    printf("data: %s\n", pointerToHeap); // place a break point in this line
    /**/

    free(pointerToHeap);
    return 0;
}
