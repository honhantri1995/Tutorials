# Problem
Count pairs with absolute difference equal to `k`
Given an array `arr[]` and a positive integer `k`, 
the task is to count all pairs (i, j) such that i < j and absolute value of (arr[i] - arr[j]) is equal to k. 

Examples: 
Input: arr[] = [1, 4, 1, 4, 5, 6, 10], k = 3
Output: 4
Explanation: There are 4 pairs with absolute difference 3, the pairs are [1, 4], [1, 4], [1, 4] and [4, 1]

Input: arr[] = [8, 16, 12, 16, 4, 0], k = 4
Output: 5
Explanation: There are 5 pairs with absolute difference 4, the pairs are [8, 12], [8, 4], [16, 12], [12, 16], [4, 0]

# Solution
### Best Approach (Sorting and Two Pointer Technique)
Time: O(nlogn)
Space: O(1)

- Sort the array in ascending order
- Use the two-pointer technique by maintaining two pointers, say i and j and initialize them to the beginning of the array.
  According to the sum of the elements, we can have three cases:
	arr[i] - arr[j] < target: We need to increase the difference between the elements, move the j pointer towards right.
	arr[i] - arr[j] > target: We need to decrease the difference between the elements, move the i pointer towards right.
	arr[i] - arr[j] = target: We have found a pair whose difference is equal to target. We can find the product of the count of both the elements and add them to the result.

### Analysis
arr[] = [1, 1, 4, 4, 5, 6, 10]
i=0, j=i+1=1
count = 0

i=0, j=1
	arr[i]=1
	arr[j]=1
	diff = |1-1| = 0
	diff < k
		j++
i=0, j=2
	arr[i]=1
	arr[j]=4
	diff = |1-4| = 3
	diff == k
		count++ = 1
		j++
			j=3
			arr[j]=4
			diff = |1-4| = 3
			diff == k
				count++ = 2
			j++
			arr[j]=5
			diff != k
				break
...

### Snippet
i = 0
j = i + 1 = 1
count = 0

sort array in ascending order
loop j < arr.size or i < arr.size:
	diff = abs(arr[i], arr[j])
	if diff < k:
		j++		// if array is ascending order
	else diff > k:
		i++		// if array is descending order
	else diff == k
		item = arr[j]
		loop j < arr.size() and arr[j] == item:
			count++
			j++