## Problem
Given a sorted array `arr[]` of size `n`, the goal is to re-arrange the array so that all distinct elements appear at the beginning in sorted order. Additionally, return the length of this distinct sorted subarray.
Note: The elements after the distinct ones can be in any order and hold any value, as they don't affect the result.

Examples: 
Input: arr[] = [2, 2, 2, 2, 2]
Output: [2]
Explanation: All the elements are 2, So only keep one instance of 2.

Input: arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
Output: [1, 2, 3, 4, 5]

Input: arr[] = [1, 2, 3]
Output: [1, 2, 3]
Explanation : No change as all elements are distinct.

## Examples

## Solution
### Expected Approach
O(n) Time and O(1) Space
Since the array is sorted, all occurrences of an element would be consecutive. 
So we mainly need to check if the current element is same as the previous element or not. 

### Analysis 1
arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]
i=1
j=0
subarr[] = [1]

i=1
	arr[i]=2
	subarr[j]=1
	arr[i] != subarr[j]
		j++		=> j=1
		subarr[] = [1, 2]
i=2
	arr[i]=2
	subarr[j]=2
	arr[i] == subarr[j]
i=3
	arr[i]=3
	subarr[j]=2
	arr[i] != subarr[j]
		j++		=> j=2
		subarr[] = [1, 2, 3]
i=4
	arr[i]=4
	subarr[j]=2
	arr[i] != subarr[j]
		j++		=> j=3
		subarr[] = [1, 2, 3, 4]
i=5
	arr[i]=4
	subarr[j]=4
	arr[i] == subarr[j]
...

### Snippet 1
i = 1
j = 0
subarr[] = arr[j]

for i : size-1:
	if arr[i] != subarr[j]:
		j++
		subarr.add(arr[i])


### Analysis 2
arr[] = [1, 2, 2, 3, 4, 4, 4, 5, 5]

subarr[] = []
i=1
j=i-1

i=1, j=0
	arr[i]=2
	arr[j]=1
	arr[i] != arr[j]
		subarr[] = [1, 2]
i=2, j=1
	arr[i]=2
	arr[j]=2
	arr[i] == arr[j]
i=3, j=2
	arr[i]=3
	arr[j]=2
	arr[i] != arr[j]
		subarr[] = [1, 2, 3]
...

### Snippet 2
i = 1
j = i-1
subarr[] = arr[j]

for i : size-1:
	if arr[i] != arr[j]:
		subarr.add(arr[i])
	i++; j++
