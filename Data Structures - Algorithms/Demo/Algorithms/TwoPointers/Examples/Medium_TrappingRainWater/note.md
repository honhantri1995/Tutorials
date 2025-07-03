## Problem
Trapping Rain Water Problem
Problem: Given an array of non-negative integers representing the elevation map where each element is the height of a bar, compute how much water can be trapped after raining.

Example:
Input: arr[] = [2, 1, 0, 3, 2, 1, 4, 1, 2]
Output: 7
Explanation: We trap (2 – 1) + (2 – 0) + (2 - 1) + (3 - 2) + (3 - 1) = 7

Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: We trap 0 + 3 + 1 + 3 + 0 = 7.

Input: arr[] = [4, 0, 3, 0, 1, 2]
Output: 6
Explanation: We trap 3 + 2 + 1 = 6.

Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides

## Solution
- Two-pointers technique
- Time: O(n). Space: O(1)

## Example
Arr[] = [2, 1, 0, 3, 2, 1, 4, 1, 2]

- l=0, r=8
	leftmax=2, rightmax=2
- l=1, r=8
	leftmax <= rightmax		--> l+=1
		leftmax  > a[l]=1 --> leftmax unchanges		--> sum = prevsum + (leftmax - a[l]) = prevsum + (2-1) = 1
- l=2, r=8
	leftmax <= rightmax		--> l+=1
		leftmax  > a[l]=0 --> leftmax unchanges		--> sum = prevsum + (leftmax - a[l]) = 1+(2-0) = 3
- l=3, r=8
	leftmax < rightmax		--> l+=1
		leftmax  > a[l]=3 --> leftmax = 3
- l=4, r=8
	leftmax > rightmax 		--> r-=1
		rightmax > a[r]=1 --> rightmax unchanges	--> sum = prevsum + (rightmax - a[r]) = 3 + (2-1) = 4
- l=4, r=7
	leftmax > rightmax 		--> r-=1
		rightmax < a[r]=4 --> rightmax = 4
- l=4, r=6
	leftmax < rightmax 		--> l+=1
		leftmax  > a[l]=2 --> leftmax unchanges		--> sum = prevsum + (leftmax - a[l]) = 4 + (3-2) = 5
- l=5, r=6
	leftmax < rightmax 		--> l+=1
		leftmax  > a[l]=1 --> leftmax unchanges		--> sum = prevsum + (leftmax - a[l]) = 5 + (3-1) = 7
- l=6, r=6
	stop














arr[] = [3, 0, 1, 0, 4, 0, 2]

+ i = 0, j = 6, leftMax = 3, rightMax = 2
+ i = 1, j = 5, leftMax = 3 (because 3 > 0), rightMax = 2 (because 2 > 0)
+ i = 2, j = 4, leftMax = 3 (because 3 > 1), rightMax = 4 (because 2 < 4)
	--> because rightMax is replaced --> find sum of the right part [4 0 2] = 2
+ i = 3, j = 3, leftMax = 3 (because 3 > 0), rightMax = 4 (because 4 > 0)
	--> find sum of the right part between 3 and 4 which is [3, 0, 1, 0, 4] = 3 + 2 + 3 = 8
	--> break (because i = j)
find total sum: 2 + 8 = 10

## Example 3
arr[] = [4, 0, 3, 0, 1, 2]
+ i = 0, j = 5, leftMax = 4, rightMax = 2
+ i = 1, j = 4, leftMax = 4 (because 4 > 0), rightMax = 2 (because 2 > 1)
+ i = 2, j = 3, leftMax = 4 (because 4 > 3), rightMax = 3 (because 3 > 2)      // have to compare leftMax and rightMax
+ i = 3, j = 2
  --> break (because i > j)
  --> find sum of the right part between 3 and 4 which is [3, 0, 1, 0, 4] = 3 + 2 + 3 = 8


## Example 3
arr[] = [4, 0, 5, 3, 0, 1, 2]

+ i = 0, j = 6, leftMax = 4, rightMax = 2
	--> arr[] = [4, 0, 5, 3, 0, 1, 2]
+ i = 1, j = 5, leftMax = 4, rightMax = 2
	--> 0 < leftMax, 1 < rightMax   
	--> no change
	--> find sum = prev sum + (leftMax - 0) + (rightMax - 1)
	--> arr[] = [4, 0, 5, 3, 0, 1, 2]
+ i = 2, j = 4, leftMax = 4, rightMax = 2
	--> 5 > leftMax
	==> cause change  --> arr[] = [5, 3, 0, 1, 2]
					  --> leftMax = 5, rightMax = 2

	--> 0 < rightMax
	--> no change
	--> find sum = prev sum + (rightMax - 0)

+ i = 3, j = 3, leftMax = 5, rightMax = 2
	--> 3 < leftMax
	--> no change

	    But 3 > rightMax
	--> rightMax = 3


	--> find sum = prev sum + (rightMax - 0)