## Problem
Given a sorted array arr (sorted in ascending order) and a target, find if there exists any pair of elements (arr[i], arr[j]) such that their sum is equal to the target.

## Examples
1. Input: arr[] = {10, 20, 35, 50}, target =70
Output:  Yes
Explanation: There is a pair (20, 50) with given target.
2. Input: arr[] = {10, 20, 30}, target =70
Output :  No
Explanation: There is no pair with sum 70.

## Solution
- Initialize: left = 0, right = n – 1
- Run a loop while left < right, do the following inside the loop:
	+ Compute current sum, sum = arr[left] + arr[right]
	+ If the sum equals the target, we’ve found the pair.
	+ If the sum is less than the target, move the left pointer to the right to increase the sum.
	+ If the sum is greater than the target, move the right pointer to the left to decrease the sum.

Time complexity: O(n) as the loops runs at most n times. We either increase left, or decrease right or stop the loop.
Space complexity: O(1)
