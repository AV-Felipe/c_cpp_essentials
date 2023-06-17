#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> // for this header that provide us with the log10 function we must link the library by passing the -lm flag to gcc(https://man7.org/linux/man-pages/man3/log10.3.html): gcc pointer_parameters.c -lm

int PERCENTAGE = 538;

// this function relays on a sentinel value at the end of a characters array to return the number of elements it contains
int getStringLength(char A[])
{
    int i = 0;
    bool flag = true;

    while (flag)
    {
        i++;
        if (A[i] == '\0')
        {
            flag = false;
        }
    }

    return i;
}

// this function generates a string with the decimal representation of the tax amount due
char *getDecimalRepresentation(char A[], int arraySize)
{
    // this initializes a pointer variable will use to store the array generated in this function
    // we cannot directly return an array from the function, only a pointer to one.
    char *pointerToHeapResult;

    if (arraySize <= 8) // 8 is the number of decimal places we fixed in our count to work with integers (10k * 10k), if we have less characters then that, will b appending zeroes
    {
        pointerToHeapResult = (char *)malloc(10 * sizeof(int));

        // we chose 10 because we are forcefully adjusting 8 decimal places plus the integer part and decimal separator
        pointerToHeapResult[0] = '0';
        pointerToHeapResult[1] = '.';

        int zerosToAdd = 8 - arraySize;
        printf("zeroes count to add: %d\n", zerosToAdd);

        int i = 2; // position for the first zero
        while (zerosToAdd > 0)
        {
            pointerToHeapResult[i] = '0';
            i++;
            zerosToAdd--;
        }
        int i2 = 0;
        while (arraySize > 0)
        {
            pointerToHeapResult[i] = A[i2];
            i++;
            i2++;
            arraySize--;
        }
        printf("value in the heap flow a: %s\n", pointerToHeapResult);
        return pointerToHeapResult;
    }
    else
    {
        printf("array size: %d\n", arraySize);
        int integerPart = arraySize - 8;
        int fraction = arraySize - integerPart;
        printf("integer part size: %d\n", integerPart);
        printf("fraction part size: %d\n", fraction);

        pointerToHeapResult = (char *)malloc((arraySize + 1) * sizeof(int));

        int i = 0;

        while (integerPart > 0)
        {

            pointerToHeapResult[i] = A[i];
            i++;
            integerPart--;
            // printf("current index: %d\n", i);
        }

        pointerToHeapResult[i] = '.';
        i++;
        // printf("current index out: %d\n", i);
        while (fraction > 0)
        {
            // printf("current index before: %d\n", i);
            // printf("setting fraction value of: %c\n", A[i-1]);
            pointerToHeapResult[i] = A[i - 1];
            i++;
            fraction--;
            // printf("current index after: %d\n", i);
        }
        printf("value in the heap flow b: %s\n", pointerToHeapResult);
        return pointerToHeapResult;
    }
}

// this function receives one integer value, corresponding to an integer amount of money - not in cents
// and returns the amount of tax due for this amount as a string representing an decimal value
char *getTaxAmount(int A)
{
    // printf("pointer: %p\n", A);

    int adjustedBase = A * 10000; // since our percentage is 5,38% or 0.0538 and we want to work with integers
    printf("adjusted base: %d\n", adjustedBase);

    int partialResult = adjustedBase * PERCENTAGE; // apply the tax percentage to the provided value
    printf("intermediary result: %d\n", partialResult);

    // with the help of the log10 function we get the number of digits in the integer result (we don't care about the fraction in the log here)
    int numberOfDigits = log10(partialResult) + 1;
    printf("digits count: %d\n", numberOfDigits);

    // here we convert the integer to a string, so we may operate it in a character basis
    char result2[numberOfDigits];
    sprintf(result2, "%d", partialResult);
    printf("value as string: %s\n", result2);

    int length = getStringLength(result2);
    printf("generated string length: %d\n", length);
    
    char *finalValue = getDecimalRepresentation(result2, length);
    printf("final value: %s\n", finalValue);

    return finalValue;
}

int main()
{
    int numberA = 100;
    int numberB = 5;

    char *returnedNumber = getTaxAmount(numberA); // to call the function we must pass the reference of an integer and one integer

    printf("you will have to pay R$%s\n", returnedNumber);

    free(returnedNumber);

    return 0;
}