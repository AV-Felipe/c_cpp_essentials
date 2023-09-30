#include<stdio.h>

int possible_combinations(int set_size, int sub_size)
{
    if(set_size == sub_size || sub_size == 0)
    {
        return 1;
    }

    return possible_combinations(set_size - 1, sub_size - 1) + possible_combinations(set_size - 1, sub_size);
}

int main()
{
    printf("you may have %d combinations", possible_combinations(4, 2));
    return 0;
}