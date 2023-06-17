#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
};

struct NamedRectangle
{
    int length;
    int breadth;
    char name;
};

struct test
{
    int row;
    char name[25];
    char dept[10];
    char address[50];
};


void main()
{
    struct Rectangle recA;
    recA.length = 20;
    recA.breadth = 5;

    printf("length: %d\nbreadth: %d\narea: %d\n\n", recA.length, recA.breadth, recA.length * recA.breadth);

    struct Rectangle recB = {15, 10};

    printf("length: %d\nbreadth: %d\n\n", recB.length, recB.breadth);

    struct NamedRectangle recC = {30, 20, 'A'};

    // here the size will be 8 units of the processor char length (the size of a char is 1)
    // the number of bits related to it may vary from processor to processor (8bits, 16, 32, 64)
    printf("%lu\n\n", sizeof(recA));

    // here we would expect the size to be 9, since besides the two integers with 4 each
    // we have a single char, which would be 1. Never the less, our processor works with chunks of
    // 4, so this struct size is pared to 12 - 4 to each property, even tough we will not take
    // advantage of 3 allocated to the char property.
    printf("%lu\n\n", sizeof(recC));

    // print the size of a single charater - one, as expected above
    char test = 'c';
    printf("%lu\n", sizeof(test));

    struct test d;
    printf("%lu\n", sizeof(d));
}
