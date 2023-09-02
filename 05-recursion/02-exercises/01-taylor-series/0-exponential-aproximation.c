#include<stdio.h>

float taylor(float expoent, float terms)
{
    printf("terms: %f expoent: %f\n", terms, expoent);

    // static int factorial = 1;
    static float power = 1;
    static float factorial = 1;
    
    if (terms == 0)
    {
        printf("aqui\n");
        return 1.0;
    }
    
    printf("acula\n");

    float term = taylor(expoent, terms - 1.0);
    printf("%.6f\n", term);

    printf("power: %f expoent: %f\n", power, expoent);
    power = power * expoent;
    printf("power: %f\n", power);

    factorial = factorial * terms;
    printf("factorial: %f\n", factorial);
    
    float partial = power / factorial;
    printf("partial result: %f\n", partial);
    float result = term + partial; 
    return result;
}


int main()
{
    printf("%f\n", taylor(1,4));
    return 0;
}