# Concepts

- C and C++ commons:
  - arrays
  - structures
  - pointers
  - references
  - parameter passing
- C++ specifics:
  - classes
  - constructors
  - templates

## Memory layout of a code in C

Generally a C program can be divided in **text segment** (which is the code section), **uninitialized data segment** (also called bdd, which means block started by symbol), **initialized data**.

### Memory division

Basically, on code execution, we may divide the memory in two blocks **stack** and **heap**.

- Stack: a very fast address set consumed in a LIFO order. It is closely related to the code being executed.
- Heap: a larger address set used to store data dynamically, usually something is stored in the heap and a reference to it is placed on the stack. Something in the heap may be available for global use and is not necessarily related to the code instructions being execute at the moment.

When we start a program, all classes or functions declared at run time are stored on the heap, the main function, which is the execution entry point, is stored int the stack, references to all the variables in this function will be there in the stack (the values of local variables will be in the stack) and after its execution the stack will be free of all data.

The main function is stored in a stack frame, a place in the the stack to operate this function.

## Arrays

Collection of **similar** data elements (a group of integers, a group of floats, a group of user defined structures ...)

```c
int A[3];
```

|            |   array A  |            |
|:----------:|:----------:|:----------:|
| position 0 | position 1 | position 2 |
| value 1    | value 2    | value 3    |

The main memory is composed of **Heap**, **Stack** and the **code section**.
When an array is created, it is placed in the stack frame of the function instantiating it.

## Structure

Collection of **dissimilar** data items under one name, they may or may not be of similar data type. It is used for defining custom data types, based on the primitive types available in the language.

When an structure is created, it is placed in the stack frame of the function instantiating it.

Inside structure a process called **paring** occurs. Suppose a structure with two integers, each with 4 bytes, and a character, which consists of 1 byte, we would assume it to have 9 bytes in size, never the less, if our processor works with chunks of 4 bytes a time, this structure will have 12 bytes, since 4 bytes will be allocated for the char, even tough it uses only one. This has to do with the way the processor handles the data.

|   Struct student  | size in bytes | actual allocated size |
|:-----------------:|:-------------:|-----------------------|
| int rool          | 4             | 4                     |
| char name[25]     | 25            | 25                    |
| char dept[10]     | 10            | 10                    |
| char address[50]  | 50            | 50                    |
|                   |               |                       |
| total struct size | 89            | 92                    |

In the above example, the processor allocates the memory based in values that are multiple of 4 bytes, so, the next multiple of 4, after 89 is 92 - this structure will allocate 92 bytes, when instantiated.

## Pointers

A pointer is a address variable meant for storing address of data - normal variables are values, the data it self. Pointers are used to indirectly accessing the data - programs can only access, directly, the code section and the stack section of memory, the heap can only be accessed indirectly.

Pointers are used to access the resources outside the program memory. This may be data in the heap or in the hard-drive, a keyboard, the monitor, all this resources outside the program memory are accessible by pointers.

```c
int number = 10; //this is a variable with an integer value

int *pointer; // this declares a variable that will hold a pointer to an integer

pointer = &number; // this initializes the variable with the reference (the address) of an integer

printf("%p\n", pointer); // here we are printing the pointer, will show the address it is pointing to

printf("%d\n", *pointer); // here we are dereferencing - accessing the value of the pointer reference - will show 10
``` 

Major uses of pointers:

- accessing the heap
- accessing external resources
- passing parameters

## References - C++ only

Reference is a way to provide another name to an already existing variable. It is like an already dereferenced pointer - a pointer can be treated in terms of the address it is pointing to or the value within that address, a reference can only point to one address and only refers to the value there stored.

The difference with pointer is that reference does not consumes any memory, it is implemented by the compiler an may vary from one compiler to the other.

It's useful and closely related to parameter passing - for improving function performance with a simpler syntax.

We cannot declare a reference and leave the initialization for later, it must be declared and initialized.

```c++
int value = 10; //this is a variable with an integer value

int &ref = value; // this is the declaration and initialization of a reference to value
```

## Functions

Group of related instructions that perform a specific task. Functions are also called modules or procedures.

- monolithic programming: everything direct into the main function
- modular / procedural programming: each task is separated from the body of main into smaller functions
- [object orientation: is another step further, adopted by C++, nesting functions into classes]

### Parameters passing

An important distinction here is that between **actual parameters** and **formal parameters**.

- formal parameters: the **parameters** defined in the function signature, which are manipulated within the function scoop
- actual parameters: the **arguments** that are passed upon the function call

- Call by value: actual values are not modified if changes are done to formal parameters - the values are copied. It is suitable for functions that return values (functions that don't modify the actual parameter)
  - arrays **cannot** be passed as values
  - structures **can** be passed as values - an structure with a property that is an array can be passed as value (this is an expensive operation, depending on the size of the array)
```c
// this function takes two values - they are copied to it's scope - and returns a third value
int sum(int a, int b){
  int c = a + b;
  return c;
}
```

- Call by address: actual values are address and formal parameters are pointers. Any change done to formal parameters is reflected to actual parameters - it may generate a side effect, a change on things outside the function scope
  - arrays: are only passed by address, on C or C++, we don't use any special notation, but within the function scope they are are references to the actual array in the memory
```c
// this function take two pointers - after its execution the values the pointer are referencing will not be the same - on calling this function, if we are passing values from variables that actually hold values, not pointer, we must reference them (&variable_name) to get the address to the value
void swap(int *a, int *b){
  int temp = *a; // the value of a is stored in the temp variable
  *a = *b; // the value of a is replaced by the value of b
  *b = temp; // the value of b is replaced by the value of temp
}
```
- [Call by reference: only available in C++. It brings the effects of call by address but with a syntax very much like the one of call by value, taking advantage of the concept of reference from C++]
  - with the call by reference approach we have the effect that the source code will be modular, in the other hand the machine code will behave as a monolithic code, no separate frame for the called function will be instantiated in the stack, but the called function will exist within the same stack frame of the caller function. Because of this, it is not advisable to use call by reference for big and complex functions
```c++
// a and b are simply alias for the arguments that where passed on the function call - on calling the function we just need to make sure we are passing integer type values
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
```

## Object Orientation

C is not an object oriented language, we can adopt an style close to object orientation on it by combining structures and functions: we define structures and initialize and operate on then only by means of functions.

On the other hand, C++ is an object oriented language, we can take advantage of classes and methods on it.