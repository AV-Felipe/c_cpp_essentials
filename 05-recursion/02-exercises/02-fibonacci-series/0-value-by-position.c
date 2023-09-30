#include<stdio.h>

int fibonacci(int position)
{
    if(position <= 1)
    {
        return position;
    }
    return fibonacci(position - 2) + fibonacci(position - 1);
}

int main()
{
    printf("the value is: %d\n", fibonacci(1));
    printf("the value is: %d\n", fibonacci(10));
    return 0;
}