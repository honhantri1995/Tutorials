## Problem
Given an array of integers `arr[]`, the task is to move all the zeros to the end of the array while maintaining the relative order of all non-zero elements.

## Examples
Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: arr[] = [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.

Input: arr[] = [10, 20, 30]
Output: arr[] = [10, 20, 30]
Explanation: No change in array as there are no 0s.

Input: arr[] = [0, 0]
Output: arr[] = [0, 0]
Explanation: No change in array as there are all 0s.

## Solution
### Native Approach
Using Temporary Array - O(n) Time and O(n) Space

The idea is to create a temporary array of same size as the input array arr[]. 
First, copy all non-zero elements from arr[] to the temporary array. 
Then, fill all the remaining positions in temporary array with 0.
Finally, copy all the elements from temporary array to arr[].

### Better Approach
Two Traversals - O(n) Time and O(1) Space
The idea is to move all the zeros by traversing the array twice.

First Traversal: Shift non-zero elements
	Traverse the array and maintain the count of non-zero elements. This count is initialized with 0 and keeps track of where the next non-zero element should be placed in the array.
	If the element is non-zero, place it at `arr[count]` and increment count by 1.
	After traversing all the elements, all non-zero elements will be shifted to the front while maintaining their original order.

Second Traversal: Fill remaining positions with zeros
	Iterate from count to the end of array and fill all indices with 0.

### Best Approach
One Traversal - O(n) Time and O(1) Space
The idea is similar to the previous approach where we took a pointer.
However, on encountering a non-zero element, instead of directly placing the non-zero element at `arr[count]`, we will swap the non-zero element with `arr[count]`. This will ensure that if there is any zero present at `arr[count]`, it is pushed towards the end of array and is not overwritten.

#### Analysis
[1, 2, 0, 4, 3, 0, 5, 0]
count=0
i = 0
	arr[i]=1
	arr[count]=0
	arr[i] != 0
		-> swap arr[count] and arr[i]
		-> new arr[]=[1, 2, 0, 4, 3, 0, 5, 0]
		count++		--> count=1
i = 1
	arr[i]=2
	arr[count]=2
	arr[i] != 0
		-> swap arr[count] and arr[i]
		-> new arr[]=[1, 2, 0, 4, 3, 0, 5, 0]
		count++		--> count=2
i = 2
	arr[i]=0
	arr[count]=0
	arr[i] == 0		--> do nothing
i = 3
	arr[i]=4
	arr[count]=0
	arr[i] != 0
		-> swap arr[count] and arr[i]
		-> new arr[]=[1, 2, 4, 0, 3, 0, 5, 0]
		count++	   		--> count=3
i = 4
	arr[i]=3
	arr[count]=0
	arr[i] != 0
		-> swap arr[count] and arr[i]
		-> new arr[]=[1, 2, 4, 3, 0, 0, 5, 0]
		count++	   		--> count=4
i = 5
	arr[i]=0
	arr[count]=0
	arr[i] == 0	--> do nothing
i = 6
	arr[i]=5
	arr[count]=0
	arr[i] != 0
		-> swap arr[count] and arr[i]
		-> new arr[]=[1, 2, 4, 3, 5, 0, 0, 0]
		-> count++	   		--> count=5
i = 7
	arr[i]=0
	arr[count]=0
	arr[count]=0 == 0
	arr[i] == 0	--> do nothing
i = 8
	stop

#### Snippet
count = 0
loop i = 0 to arr.size()-1:
	if arr[i] != 0
		arr[count] = arr[i]
		count++
	i++

### Another Best Approach
https://www.geeksforgeeks.org/stdstable_partition-in-c/

## Ref
https://www.geeksforgeeks.org/dsa/move-zeroes-end-array/