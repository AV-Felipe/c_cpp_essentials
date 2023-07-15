# Time and space complexity

## Time complexity

Time complexity is the relation of time taken to perform some work in function of the amount of data to operate on. We think in terms of number of times we will have to do something, where this something we will have to do takes a more or less fixed time for each execution.

For instance, from the less time complex to the more time complex:

- **logarithmic time**: if we have an **ordered list** of n elements and we want to find a value by splitting the list in halves and halves of halves until we pinpoint the desired value, we have a problem with an *order of complexity of log n* or **O(log n)**
In code we usually have something like:
```c
for (int i = n; i > 1; i/2)
{
    # some code
}
```
- **linear time**: if we have a list of n elements and we want to find a value by visiting each subsequent element successively, we have a problem with an *order of complexity of n* or **O(n)**
In code we usually have something like:
```c
for (int i = 0; i < n; i++)
{
    # some code
}
```
- **polynomial time**: if we have a list o n elements and we want to sort these elements in a crescent order, for instance, for each element we will have to visit the entire list one time, in the worst scenario, we have a problem with an *order of complexity of n²* or **O(n²)**
In code we usually have something like:
```c
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        # some code
    }
}
```

A special time complexity case is for constant functions, functions that alway execute in the same time, for instance a if we want o retrieve the element on index y of a list with n elements, regardless of the size of the list, we will alway take the same amount of time, we have a problem with an *order of complexity of 1* or **O(1)**

## Space complexity

Here the question is related to how much space is consumed in main memory during the execution of a program.

It will be a function of the data we are operating on, so it will generally range from n to some polynomial case of n^m , for a matrix data set
