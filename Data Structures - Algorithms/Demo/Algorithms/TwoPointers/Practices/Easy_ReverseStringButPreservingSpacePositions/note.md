## Problem
Reverse a string preserving space positions
Given a string s, the task is to reverse the given string while preserving the position of spaces.

Examples: 
Input: abc de
Output: edc ba

Input: Help others
Output: sreh topleH

## Examples
## Solution
### Expected Approach
Using two Pointers - O(n) Time and O(1) Space
The idea is to use two pointers pointing at start and end of the string. If character at start or end is space, we move the pointer pointing to the space to the next position and swap only if both pointer point to a character. 

### Analysis
Help others

i=0, j=10
	arr[i] and arr[j] are not space
		--> swap them: selp otherH
			i++; j--
i=1, j=9
	arr[i] and arr[j] are not space
		--> swap them: srlp otheeH
			i++; j--
i=2, j=8
	arr[i] and arr[j] are not space
		--> swap them: srep othleH
			i++; j--
i=3, j=7
	arr[i] and arr[j] are not space
		--> swap them: sreh otpleH
			i++; j--
i=4, j=6
	arr[i] is a space
		--> i++
i=5, j=6
	arr[i] and arr[j] are not space
		--> swap them: sreh topleH
i=6, j=5
	stop

### Snippet
i = 0
j = size()-1

loop i <= j:
	if arr[i] != "" and arr[j] != "":
		swap arr[i] and arr[j]
		i++
		j--
	else arr[i] == "":
		i++
	else arr[j] == "":
		j--