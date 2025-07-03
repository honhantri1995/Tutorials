# Problem
Given an even-sized array `arr[]` of length `n`. A dominant pair (i, j) is defined as:
`i` belongs to the first half of the array, `(0 <= i < n/2)`
`j` belongs to the second half of the array, `(n/2 <= j < n)`
The value at index `i` is at least five times the value at index `j`, `(arr[i] >= 5 * arr[j])`
The task is to find the count of total number of dominant pairs in the array.

Examples:
Input: arr[] = [10, 2, 2, 1]
Output: 2
Explanation: First half: [10, 2], Second half: [2, 1]. So valid pairs are: 
	10 >= 5 × 2
	10 >= 5 × 1
So, total dominant pairs = 2.

Input: arr[] = [10, 8, 2, 1, 1, 2]
Output: 5
Explanation: First half: [10, 8, 2], Second half: [1, 1, 2]. So valid pairs are:
	10 >= 5 × 1
	10 >= 5 × 1
	10 >= 5 × 2
	8  >= 5 × 1
	8  >= 5 × 1
So, total dominant pairs = 5.

# Solution
## Brute Force Approach (but not iterating all items)
- Split the array into two subarrays: first half and second half
- Sort first-half subarray in descending order
- Sort second-haft subarray in ascending order
- Using two loops:
	+ Outer loop is for first-half subarray
	+ Inner loop is for second-half subarray
	+ Find until there is no dominant pair, break the loop (because subarrays are ordered, we can stop without having to iterating all items in array)

Time: O(n + nlogn + n^2) = O(n^2)

## Best Approach (Sorting + Two Pointers)
Time: O(nlogn)
Space: O(1)

- Sort original array with middle pivot. First half is in decreasing order, second half is in ascending order
- Using two pointers. Left one starts from index 0, second one start from index size-1
- Iterate, each time move the left pointer or right pointer corresponding
  If the dominance condition is satisfied, count the dominant pairs ...

### Analysis
[10, 8, 2, 1, 1, 2]

Sorted arr: [10, 8, 2, 1, 1, 2]
pivot index: pi = 2
dominant pair count c = 0

i=0, j=5
	arr[i]=10
	arr[j]=2
	arr[i] >= 5 x arr[j]:
		c += j - pi += 5-2 = 3
		i++
i=1, j=5
	arr[i]=8
	arr[j]=2
	arr[i] < 5 x arr[j]:
		j--
i=1, j=4
	arr[i]=8
	arr[j]=1
	arr[i] >= 5 x arr[j]:
		c += j - pi += 4-2 = 3+2=5
		i++
i=2, j=4
	arr[i]=2
	arr[j]=1
	arr[i] < 5 x arr[j]:
		j--
i=2, j=3
	arr[i]=2
	arr[j]=1
	arr[i] < 5 x arr[j]:
		j--
i=2, j=2
	stop

### Snippet
i = 0
j = arr.size
pi = j / 2
c = 0
loop i < j:
	if arr[i] >= 5 x arr[j]:
		c += j - pi
		i++
	else:
		j--