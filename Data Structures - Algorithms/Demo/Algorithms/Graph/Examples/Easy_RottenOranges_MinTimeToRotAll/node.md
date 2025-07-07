# Problem
Given a matrix of dimension `M x N`, where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:  
	0: Empty cell
	1: Cells have fresh oranges
	2: Cells have rotten oranges
The task is to find the minimum time required so that all the oranges become rotten. A rotten orange at index `(i,j)` can rot other fresh oranges which are its neighbors (up, down, left, and right).

Note: If it is impossible to rot every orange then simply return -1.

Examples: 

Input: arr[][] = [[2, 1, 0, 2, 1], [1, 0, 1, 2, 1], [1, 0, 0, 2, 1]];
Output: 2
Explanation:
	At 0th time frame:
		[2, 1, 0, 2, 1]
		[1, 0, 1, 2, 1]
		[1, 0, 0, 2, 1]
	At 1st time frame:
		[2, 2, 0, 2, 2]
		[2, 0, 2, 2, 2]
		[1, 0, 0, 2, 2]
	At 2nd time frame:
		[2, 2, 0, 2, 2]
		[2, 0, 2, 2, 2]
		[2, 0, 0, 2, 2]

Input: arr[][] = [[2, 1, 0, 2, 1], [0, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
Output: -1
Explanation:
	At 0th time frame:
		[2, 1, 0, 2, 1]
		[0, 0, 1, 2, 1]
		[1, 0, 0, 2, 1]
	At 1st time frame:
		[2, 2, 0, 2, 2]
		[0, 0, 2, 2, 2]
		[1, 0, 0, 2, 2]
	At 2nd time frame:
		[2, 2, 0, 2, 2]
		[0, 0, 2, 2, 2]
		[1, 0, 0, 2, 2]
	The 1 at the bottom left corner of the matrix is never rotten.

# Solution
## [Naive Approach] - Using Iteration
O((n x m) ^ 2) Time and O(1) Space

## [Better Approach] - Using Depth First Search
O(n x m) Time and O(1) Space

## [Expected Approach] - Using Breadth First Search
O(n x m) Time and O(n x m) Space

Steps:
1. Create a queue to store all the cells that initially contains rotten orange.
2. Now, run a loop until queue is not empty and in each iteration dequeue the top most element, storing the time and indices of cell. Now check all 4-directionally connected cell, if any cell contains a fresh orange, change its state and push the indices in queue and increment the time by 1.
3. After the queue is empty, check if there is any fresh orange remaining, if so print -1, else print the maximum elapsed time.