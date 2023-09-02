#include <stdio.h>

/*
*  This implementations changes the time complexity from O(n²) (quadratic) 
*  to O(n) (linear)
*/

double taylor(int exponent, int terms)
{
    static double acumulator;
    if (terms == 0)
    {
        return acumulator;
    }

    acumulator = 1 + exponent * acumulator / terms;
    return taylor(exponent, terms -1);
}

int main()
{
    printf("%lf\n", taylor(2,10));
    return 0;
}