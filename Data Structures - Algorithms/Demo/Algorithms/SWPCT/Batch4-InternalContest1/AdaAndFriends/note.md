# Problem
Ada has many friends. They always celebrate something and Ada has to buy them gifts. It is pretty costly so she have decided to unfriend some of them. What is the maximum of money she can spare?

### Input
The first line of each test-case will contain two integers `1 ≤ Q K ≤ 10^5`, the number of celebrations (`Q`) and the maximum number of friends Ada wants to unfriend (`K`).
The next `Q` lines will contain `s` (the name of friend to whom Ada will buy gift) and `1 ≤ E ≤ 10^9+1` (the expenses).

Names will contain at most 40 lowercase English letters.

time_limit: 2000 ms
mem_limit: 1572864 kB

### Output
For each test-case, print the number of money Ada could spare.

### Example
#### 1
Input:
	6 1
	uvuvwevwevweonyetenyevweugwemubwemossas 10
	ryuk 11
	uvuvwevwevweonyetenyevweugwemubwemossas 5
	fegla 3
	tenshikanade 7
	fegla 2
Output:
	15

#### 2
Input:
	4 3
	frodo 1
	harrypotter 2
	frodo 2
	harrypotter 2
Output:
	7

### 3
Input:
	7 2
	waynebot 7
	lhic 4
	petr 5
	umnik 9
	izrak 6
	tourist 11
	zlobobber 9
Output:
	20


# Solution
- Iterate all celebrations Q
  Put all unique celebrations in a map (key: friend name, value: expense)
- Copy map to vector
- Sort the vector in descending order
- Get K items from the sorted list
- Sum K items