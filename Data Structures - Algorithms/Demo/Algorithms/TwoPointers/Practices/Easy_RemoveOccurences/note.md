## Problem
Given an integer array `arr[]` and an integer `ele`.
Remove all occurrences of `ele` from `arr[]` in-place and return the number of elements which are not equal to `ele`.
If there are `k` number of elements which are not equal to `ele` then the input array `arr[]` should be modified such that the first `k` elements should contain the elements which are not equal to `ele` and then the remaining elements.

Note: The order of first `k` elements may be changed.

## Examples
Input: arr[] = [3, 2, 1, 3], ele = 3
Output: 2, modifiedArr[] = [2, 1, _, _]

Input: arr[] = [0, 1, 3, 0, 2, 2, 4, 2], ele = 2
Output: 5, modifiedArr[] = [0, 1, 3, 0, 4, _, _, _]

## Solution
The idea is to iterate over the array while maintaining a subarray at the beginning that contains only the elements which are not equal to ele. So, we can use a counter, say k to track the ending point of this subarray and whenever we encounter an element which is not equal to ele, we can add the element at kth index and increment the value of k.

Space complexity: O(n)
Time complexity: O(n)

## Steps
### Example
Input: arr[] = [3, 2, 1, 3], ele = 3
- k=0
- i=0
	arr[i]=3  ==  ele
		do nothing

- i=1
	arr[i]=2  !=  ele
		arr[k]=arr[i]		--> modifiedArr[] = [2]
		k++
- i=2
	arr[i]=1  !=  ele
		arr[k]=arr[i]		--> modifiedArr[] = [2, 1]
		k++

- i=3
	arr[i]=3  ==  ele
		do nothing
