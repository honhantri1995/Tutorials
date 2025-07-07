# Problem
Given a string `s` and a non negative integer `k`, find the length of the longest substring that contains exactly `k` distinct characters.
If no such substring exists, return -1.

Examples:
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.

Input: s = "aaaa", k = 2
Output: -1
Explanation: The string contains only one unique character, so there's no substring with 2 distinct characters.

Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.

# Solution
## Brute Force
- Using two loops to iterate the whole array
- Using an unordered set to store 

### Analysis
Input: s = "aabacbebebe", k = 3

i=0
	j=0
		set = [a]
	j=1
		set = [a]
	j=2
		set = [a, b]
	j=3
		set = [a, b]
	j=4
		set = [a, b, c]
		set.size=3 == k:
			output = max(output, j-i=4) = 3
	j=5
		set = [a, b, c]
		set.size=3 == k:
			output = max(output, j-i=5) = 5
	j=6
		set = [a, b, c, e]
		set.size=4 > k:
			break
i=1
	...
i=2
	...
i=3
	...
i=4
	j=4
		set = [c]
	j=5
		set = [c]
	j=6
		set = [c, b]
	j=7
		set = [c, b,e]
	j=8
		set = [c, b,e]
	j=9
		set = [c, b,e]
	j=10
		set = [c, b, e]
		j = arr.size:
			output = max(output, j-i+1 = 10-4+1) = 7
			return

### Snippet
loop i
	loop j=i
		set.insert(arr[j])
			if set.size == k:
				output = max(output, j-i)
			else:
				break

## Two Pointer Technique
- Use a nested loop wih i and j index, both starts from begining of the array.
- Create an unordered set to store distint characters
- In each outter-loop iteration, iterate items with inner loops
- In each inner-loop iteration, save the item to the set.
	+ If the set size exceeds k, clear the set and break the inner loop
	+ Else increase the counter of k distint characters 

### Analysis
i=0:
	set=[]
	j=0: arr[j]=a, set=[a]
	j=1: arr[j]=a, set=[a]
	j=2: arr[j]=b, set=[a, b]
	j=3: arr[j]=a, set=[a, b]
	j=4: arr[j]=c, set=[a, b, c]	--> size=3 --> i=j-1=3
	j=5: arr[j]=b, set=[a, b, c]	--> size=3 --> i=j-1=4
	j=6: arr[j]=e, set=[a, b, c, e] --> size=4 > k=3
			--> break
i=4
	set=[]
	j=4: arr[j]=c, set=[c]
	j=5: arr[j]=c, set=[c, b]
	...
	j=10: arr[j]=c, set=[c, b, e]
		  j = size --> return

result: cbebebe (size = 7)

### Snippet
unorderd_set s=[]
max_count = 0
tmp_count = 0
for i=0 to arr.size
	for j=i to arr.size
		s.insert(arr[i])
		if s.size <= k:
			tmp_count++
			max_count = max(max_count, tmp_count)
			if s.size == k
				i=j-1
		else
			s.clear
			tmp_count = 0
			break

## Sliding Window Technique + Two Pointer Technique