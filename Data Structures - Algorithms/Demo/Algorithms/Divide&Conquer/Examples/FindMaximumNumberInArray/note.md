## Problem
Given an array arr = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3]. Find the maximum element in the array.

## Idea
Divide the array into two equal-sized subarrays. Then find the maximum of those two individual halves by recursively dividing them into two smaller halves. This is done till we reach subarrays of size 1. Finally, return the maximum element by returning the maximum in each subarray.

## Time complexity
O(n) (linear time due to visiting each element once)

## Space complexity
O(logn) (due to the depth of the recursion stack)
