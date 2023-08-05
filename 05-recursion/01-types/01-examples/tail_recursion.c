#include<stdio.h>

/*
** FACTORIAL FUNCTIONS
**
** With a 4 bytes unsigned integer (32bits) we can represent up to
** decimal 4.294.967.295 (2^32 - 1), whereas with a signed integer we may
** represent from -2.147.483.648 (-2^32/2) to 2.147.483.647 ((2^32/2) - 1)
** 10! =     3.628.800
** 11! =    39.916.800
** 12! =   479.001.600 -> limit for standard int types
** 13! = 6.227.020.800
*/

// this implementation uses local variables, which in some compilers may not be memory
// efficient, since it will instantiate every variable used in the stack for each
// recursive call, for the present data being manipulated (integer) there is no much gain,
// but for a large and complex data structure, ther could be some advantage in using a
// static, a global variable or a pointer. This function is has both time and space complexity
// of order of n O(n) - if the compiler optimizes the tail recursion, it would be 
// order of 1 O(1) for space complexity, in c we could achieve this by implementing the
// using a while instead of a tail recursion
unsigned int get_factorial(unsigned int value, unsigned int result)
{
    if(value < 1)
    {
        return result;
    }
    return get_factorial(value - 1, result * (value));
}

int main()
{
    printf("%lu \n", sizeof(int));
    int start_result = 1; // 0! = 1 
    printf("Factorial of %u is %u \n", 12, get_factorial(12, start_result));

    return 0;
}