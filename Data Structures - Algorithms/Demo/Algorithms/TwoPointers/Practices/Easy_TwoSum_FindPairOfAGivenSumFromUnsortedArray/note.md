## Problem
Given an array `arr[]` of `n` integers and a target value, check if there exists a pair whose sum equals the target. 
This is a variation of the 2Sum problem.

Examples: 
Input: arr[] = [0, -1, 2, -3, 1], target = -2
Output: true
Explanation: There is a pair (1, -3) with the sum equal to given target, 1 + (-3) = -2.

Input: arr[] = [1, -2, 1, 0, 5], target = 0
Output: false
Explanation: There is no pair with sum equals to given target.

## Solution
Rather than checking every possible pair, we store each number in an unordered set during iterating over the array's elements. For each number, we calculate its complement (i.e., target - current number) and check if this complement exists in the set. If it does, we have successfully found the pair that sums to the target. 

- Time: O(n), space: O(n)
	+ unorder_set.find() and .insert() takes only O(1)

### Analysis
Input: arr[] = [0, -1, 2, -3, 1], target = -2

unordered_set set = []
i=0:
	arr[i]=0
	num = target - arr[i] = -2 - 0 = -2
	arr[i] does not exist in set
	add num to set: set[]=[-2]
i=1:
	arr[i]=-1
	num = target - arr[i] = -2 - (-1) = -1
	arr[i] does not exist in set
	add num to set: set[]=[-2, -1]
i=2:
	arr[i]=2
	num = target - arr[i] = -2 - (2) = -4
	arr[i] does not exist in set
	add num to set: set[]=[-2, -1, -4]
i=3:
	arr[i]=-3
	num = target - arr[i] = -2 - (-3) = 1
	arr[i] does not exist in set
	add num to set: set[]=[-2, -1, -4, 1]
i=4:
	arr[i]=1
	num = target - arr[i] = -2 - (1) = -3
	arr[i] exists in set
		return true

### Snippet
num=0
unordered_set set = []
loop i=0 -> size-1:
	num=target - arr[i]
	if arr[i] exists in set (set.find(arr[i])):
		return true and end program
	add num to set (set.insert(num))
return false