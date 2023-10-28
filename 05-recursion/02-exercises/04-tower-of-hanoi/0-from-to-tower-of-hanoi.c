#include<stdio.h>

/*
move extra discs to intermediary
move last disc to final
move extra discs to final

2 groups, always: 1 and n-1
n-1 goes from source to intermediary (using final destination as auxiliary)
1 goes to destination directly
*/

void toh(int size, char s, char i, char f)
{
    // if only one goes to final destination (1)
    if (size == 1)
    {
        printf("move %d from %c to %c\n",size, s, f);
        return;
    }

    // if more than one send all to intermediary (n-1)
    toh(size - 1, s, f, i);
    printf("move %d from %c to %c\n", size, s, f);
    // then send then from intermediary to final destination
    toh(size-1, i, s, f);
    return;
}

int main()
{
    printf("---\n");
    toh(4, 'A', 'B', 'C');
    return 0;
}