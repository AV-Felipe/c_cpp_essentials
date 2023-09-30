#include<stdio.h>

int FibArray[10];

int fibonacci(int position)
{
    if(position <= 1)
    {
        FibArray[position] = position;
        return FibArray[position];
    }

    if(FibArray[position - 1] == -1)
    {
        FibArray[position - 1] = fibonacci(position - 1);
    }

    if(FibArray[position - 2] == -1)
    {
        FibArray[position - 2] = fibonacci(position - 2);
    }

    FibArray[position] = FibArray[position - 1] + FibArray[position - 2];

    return FibArray[position];
}

int main()
{
    for(int i = 0; i <= 10; i++)
    {
        FibArray[i] = -1;
    }
    printf("the value is: %d\n", fibonacci(1));
    printf("the value is: %d\n", fibonacci(10));
    return 0;
}