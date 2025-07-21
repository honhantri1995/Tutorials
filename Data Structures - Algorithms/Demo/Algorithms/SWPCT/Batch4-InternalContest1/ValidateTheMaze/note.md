# Problem
There are many algorithms to generate maze. (maze generation algorithm).
After generating the maze we’ve to validate whether it’s a valid maze or not.
A valid maze has exactly one entry point and exactly one exit point (exactly 2 openings in the edges) and there must be at least one path from the entry point to exit point.

Given a maze, just find whether the maze is "valid" or "invalid".

time_limit: 1000 ms
mem_limit: 1572864 kB

## Input
The first line consists of an integer `t` - the number of test cases.
For each test case, the first line consists of two integers `m` and `n`, the number of rows and columns in the maze. Then contains the description of the matrix `M` of order `m×n`. `M[i][j] = #` represents a wall and `M[i][j] = '.'` represents a space.

## Output
For each test case find whether the maze is "valid" or "invalid".

Constraints
1 ≤ t ≤ 10000
1 ≤ m ≤ 20
1 ≤ n ≤ 20

## Example
``` python
Input:
	6
	4 4
	####
	#...
	#.##
	#.##
	5 5
	#.###
	#..##
	##..#
	#.#.#
	###.#
	1 1
	.
	5 1
	#
	#
	.
	.
	#
	2 2
	#.
	.#
	3 4
	#..#
	#.##
	#.##

Output:
	valid
	valid
	invalid
	valid
	invalid
	invalid
```

# Solution