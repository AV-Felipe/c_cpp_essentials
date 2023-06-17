#include<iostream>

using namespace std;

int main()
{
    int valueA = 10;

    // we declare and initialize a reference to the value variable.
    int &ref = valueA;

    cout << valueA << endl;
    cout << ref << endl;

    // ref is not a variable per se, but is a reference to variable valueA, so if we set it to
    //a new value, actually we will be setting valueA to that value
    int valueB = 25;
    ref = valueB;

    cout << valueA << endl;
    cout << ref << endl;

    return 0;
}