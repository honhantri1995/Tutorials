## Problem
Write a function that calculates the n-th Fibonacci number using the following constraints:
- If n is less than 0, return -1.
- If n is 0, return 0.
- If n is 1, return 1.
- For n greater than 1, use an iterative approach to calculate the Fibonacci number.

Example:
- Input: n = 6
- Output: 8 (the Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8 ...)

## Solution
### Ver1
First calculate Fibonacci using recursion like the traditional way.
But add an additional step to save the number and the result to a table.
Then add a condition to check if the number is tranversed before. If so, use the result corresponding to this number. Otherwise, call recursive function.

This verion is straightforward to understand. However, the implementation is not neat at all.

### Ver2
Do not use recursion.

This version has very neat implementation.