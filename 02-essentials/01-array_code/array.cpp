#include <iostream>
using namespace std; //includes the default c++ namespace, where all lasses, methods and templates are declared
// concerning namespaces, we can create our own, to avoid redundancies, and then we use them like the above

int main() {

    // to print the string to the default output, ve are not passing an argument to a method
    // we are inserting (<< this is the insertion operator, it sends bytes to an output stream object)
    // to the default output
    cout << "hello array!\n";

    char MyNameLetters[6] = {'f', 'e', 'l', 'i', 'p', 'e'};

    // the while loop also exists in C and has the same syntax
    int i = 0;
    while (i < 6) {
        cout << MyNameLetters[i];
        if (i == 5) {
            cout << "\n";
        }
        i++;
    }

    int MyArrayA[3];
    MyArrayA[0] = 1;
    MyArrayA[1] = 2;
    MyArrayA[2] = 3;

    // on c++ we can declare the variable for the for loop within the loop definition
    for (int i = 0; i < 3; i++) {
        cout << "element " << i << " is " << MyArrayA[i] << "\n";
    }

    return 0;
}

// When compiling C++ code with gcc, you should use the g++ command instead,
// which automatically links the C++ standard library:
//   g++ array.cpp -o array
// the previous wll compile the code into a bin called array