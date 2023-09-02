# Exercises

For recursive problems we generally approach the problems by two basic steps:

- finding a recursive definition: for determining what should be passed to the recursive call
- setting the maximum and the minimum scenarios: to determine the condition for the recursion

## Example:

Finding the sum of the first n natural numbers:

- Example case: $$ s = 1+2+3+4+5+6+7 $$

- Generalization: $$ s = 1+2+3+...+(n-1)+(n) $$

- Recursive definition: $$ sum(n) = sum(n-1) + n $$

- Setting the extremities: 
  - `0` when  `n = 0` 
  - `sum(n-1) + n` when `n > 0`

With this we can make the following code:

```c
int sumUntil(int value)
{
    if (value == 0)
    {
        return 0;
    }
    else
    {
        return sumUntil(value - 1) + value;
    }
}
```

In this case the more appropriate would be to use the mathematical formula $$ n\times(n+1) \over 2$$ that, if implemented, would be a code with time complexity of order of 1 - O(1) - or a a loop, depending on the language, that would have a time complexity of the order of n - O(n) - but with an space complexity of order of 1 - O(1)- whereas the recursive function, in some programming languages would have a space complexity of the order of n - O(n) - the time complexity would be order of n, since in loop and in recursion we would have n calls, according to the passed value.