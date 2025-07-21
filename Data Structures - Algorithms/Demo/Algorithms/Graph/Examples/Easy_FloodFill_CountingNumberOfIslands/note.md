# Problem
Given an `n x m` grid of `W` (Water) and `L` (Land), the task is to **count the number of islands**.  
An island is a group of adjacent `L` cells connected horizontally, vertically, or diagonally, and it is surrounded by water or the grid boundary. The goal is to determine how many distinct islands exist in the grid.

## Examples
``` python
Input: grid[][] = [
	['L', 'L', 'W', 'W', 'W'],
	['W', 'L', 'W', 'W', 'L'],
	['L', 'W', 'W', 'L', 'L'],
	['W', 'W', 'W', 'W', 'W'],
	['L', 'W', 'L', 'L', 'W']
]
Output: 4
Explanation: example1.png
```

``` python
Input: grid[][] = [
	['W', 'L', 'L', 'L', 'W', 'W', 'W'],
	['W', 'W', 'L', 'L', 'W', 'L', 'W']
]
Output: 2
Explanation: example2.png
```

``` python
Input: grid[][] = [
	['W,' 'W'],
	['W', 'W']
]
Output: 0
Explanation: All elements are 0, hence no islands.
```

# Solution
- The grid itself acts as the graph.
- Each land cell in the grid is treated as a vertex. It connects to neighboring land cells in 8 directions (up, down, left, right, and diagonals).
- Edges are implied by adjacency.
We will represent the grid as a 2D matrix (conceptually very close to an adjacency matrix, but not actually).

## BFS - O(n*m) time and O(n*m) space
- Using matrix presentation for graph.
- Find all the lands: O(n*m) time
- For each land, bfs until no more land.
  Visited lands are stored in a matrix.
  At the same time, count the islands: O(n*m) time and O(n*m) space

## BFS - O(n*m) time and O(1) space
- Using matrix presentation for graph.
- Find all the lands: O(n*m) time
- For each land, bfs until no more land.
  Do not use a matrix to store visited lands. Instead, change 'L' to 'W' in the inputted matrix.
  At the same time, count the islands: O(n*m) time and O(1) space