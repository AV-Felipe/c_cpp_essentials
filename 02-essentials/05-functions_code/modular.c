#include<stdio.h>

// it is important to alway declare what will be used BEFORE it is used
// so the add function is declare before the main, that is the code entry point
// and where we call the add function
int add(int a, int b) // the function signature, here is called the PROTOTYPE of the function or header of the function
{
    int c;
    c = a + b;
    return c;
} // within the curly brackets we have the DEFINITION of the function

void main()
{
    //we can declare multiple variables at once, for the same type
    int x, y, z;

    x = 10;
    y = 15;

    // here we call our previously defined function
    // on calling the function, it's own stack frame is created (above the main function frame)
    z = add(x, y); // within the function call, we are passing the ACTUAL PARAMETERS (x and y). They must conform to the FORMAL PARAMETERS (defined in the function signature)
    printf("%d + %d = %d\n", x, y, z);

    // if omitted the code will continue to compile
    return 0;
}