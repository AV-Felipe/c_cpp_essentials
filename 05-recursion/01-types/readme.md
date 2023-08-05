# types of recursion

- tail recursion
- head recursion
- tree recursion
- indirect recursion
- nested recursion

## Tail recursion

When the recursive call is the last call in the function. every thing is performed at calling time, nothing a returning time. It has the following format:

```c
Type myRecFun(param)
{
    if(condition) // method for terminating the recursion
    {
        ... // calling time execution
        myRecFun(param); // returning time - no more executions from this scope
    }
}
```

- This type of recursion can easily be converted into a **loop**
- considering the *time complexity* a loop and this function are equivalent
- considering the *space complexity* the loop is more efficient, since it will not create a new stack activation record for each successive execution (this is not true for all languages, some languages actually benefits from tail recursion by compiler technics, Python would be susceptible to stack overflow, whereas Haskell would take advantage of a tail recursion by a technique called Tail Call Optimization)