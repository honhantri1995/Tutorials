# Problem
Given a snake and ladder board, find **the minimum number of dice throws required to reach the destination**.
Basically, the player has total control over the outcome of the dice throw (you can pick from 1 to 6 points each time).
If the player reaches a cell which is the base of a ladder, the player can immediately climb up that ladder. No extra throw needed.
If the player reaches a cell which is the mouth of the snake, the player has to go down to the tail of the snake without a dice throw. Also no extra throw.

## Examples:
Input: input1.png
board = [
	[25, 26, 27, 28, 29, 30],
	[24, 23, 22, 21, 20, 19],
	[13, 14, 15, 16, 17, 18],
	[12, 11, 10, 09, 08, 07],
	[01, 02, 03, 04, 05, 06]
]
Output: 3
Explanation:
	- Player needs to reach cell #30 (desintation cell) from cell #1 (source cell).
	- Snake mounts are at cell #17, #19, #21, #27.
	- Base cells are #3, #5, #11, #20.
	- The challenge is choosing the smartest moves to avoid snakes and take advantage of ladders.
	- Steps:
		- Player is originally at cell #1.
		- Player throws a dice throw (with 2 points) to reach cell #3.		==> number of dice throws: 1
		- Player ladders to reach cell #22. No extra dice throw.
		- Player throws a dice (with 6 points) to reach cell #28.			==> number of dice throws: 2
		- Player throws a dice (with 2 points) to reach cell #30.			==> number of dice throws: 3

	NOTE: There can be other solutions as well likes:
		- ✅ Dice throw 2 points to reach cell #3 -> ladder to reach cell #22 -> Dice throw 2 points to reach cell #24 -> Dice throw 6 points to reach cell #30
		- ✅ Dice throw 2 points to reach cell #3 -> ladder to reach cell #22 -> Dice throw 4 points to reach cell #26 -> Dice throw 4 points to reach cell #30
		- ✅ Dice throw 2 points to reach cell #3 -> ladder to reach cell #22 -> Dice throw 3 points to reach cell #25 -> Dice throw 5 points to reach cell #30
		- ✅ Dice throw 4 points to reach cell #5 -> ladder to reach cell #8  -> Dice throw 3 points to reach cell #11 -> ladder to reach cell #26 -> Dice throw 4 points to reach cell #30
		- ❌ Dice throw 10 points to reach cell #11	: IMPOSSIBLE because max point of a dice is only 6

# Solution
## BFS - But code is not clean because graph is not presented well
### Explanation
``` python
vector of pair: ladders = [
	[3, 22],	# base and top
	[5, 8],
	[11, 26],
	[20, 29]
]
vector of pair: snakes = [
	[1, 27],	# tail and mount
	[4, 17],
	[9, 21],
	[8, 19]
]
soure = 1
dest = 30
boardSize = 30

- queue = [1]
- queue.top=1
	--> Among 7,6,5,4,3,2, we have 3 and 5 as the ladder bases
	--> top of ladder 3 is 22 -> not a snake mount
	    top of ladder 5 is 8  -> not a snake mount
	--> push 22 and 8 to queue and pop 1: queue = [22, 8]
	--> min dice throw: 1
- queue.top=22
	--> Among 28,27,26,25,24,23, we have 28 is not the snake mount
	--> choose 28
	--> push 28 to queue and pop 22: queue = [8, 28]
	--> min dice throw: 2
- queue.top=8
	--> Among 14,13,12,11,9, we have 11 as the ladder base
	--> top of ladder 11 is 26 -> not a snake mount
	--> choose 26
	--> push 26 to queue and pop 8: queue = [28,26]
	--> min dice throw: 2
- queue.top=28
	--> Among 30,29, we have 30 is the destination
	--> min dice throw: 3
	--> end program
```
### Implementation
ver1.cpp

## BFS - And code is much more clean
This is a **shortest path problem**:
- Each cell is a node
- Dice throws, ladders and snakes represent edges.
- When you land on a cell with a ladder or snake, you're **teleported** to a new cell. This effectively changes the destination node of that edge.
- Use BFS to explore the fewest moves to reach cell 30. It tries all valid dice throws from each cell, always expanding to the lowest-throw path first.

https://www.geeksforgeeks.org/dsa/snake-ladder-problem-2/

TODO: The below is not correct. I have to practice this problem again.

<!-- 
### Explanation
``` python
vector of int:
	ladder[3]  = 22,	# base and top
	ladder[5]  = 8,
	ladder[11] = 26,
	ladder[20] = 29,
vector of int:
	snake[27] = 1,		# mount and tail
	snake[17] = 4,
	snake[21] = 9,
	snake[19] = 8,
soure = 1
dest = 30
boardSize = 30

- queue = [1]
- queue.top=1
	--> 1 is not found in vector ladder
	--> Among 7,6,5,4,3,2, we have 3 and 5 as the ladder bases
	--> top of ladder 3 is 22
	    top of ladder 5 is 8
	--> push 22 and 8 to queue and pop 1: queue = [22, 8]
	--> min dice throw: 1
- queue.top=22
	--> Among 28,27,26,25,24,23, we have 28 at the front
	--> choose 28
	--> push 28 to queue and pop 22: queue = [8, 28]
	--> min dice throw: 2
- queue.top=8
	--> Among 14,13,12,11,9, we have 11 as the ladder base
	--> top of ladder 11 is 26
	--> choose 26
	--> push 26 to queue and pop 8: queue = [28,26]
	--> min dice throw: 2
- queue.top=28
	--> Among 30,29, we have 30 is the destination
	--> min dice throw: 3
	--> end program
```

while (queue is not empty):
	node = queue.front
	if node is not visited:
		if ladder.find(node):
			node = ladder[node]		// teleport
		else:
			for (dice = 1 to 6):
				if node+dice not visited:
					queue.push(node + dice) -->