[Medium] Remove Adjacent Duplicates

## Problem
Given a string s, remove all its adjacent duplicate characters recursively, until there are no adjacent duplicate characters left. If the resultant string becomes empty, return an empty string.

Examples:
	- Input: s = "geeksforgeek". Output: "gksforgk"
	- Input: s = "abccbccba". Output: ""
	- Input: s = "abcd". Output: "abcd"

Constraints:
1<= s.size() <= 105

## Ver1
The idea is to first iteratively build a new string in result by removing adjacent duplicates. 
After one full pass, if the length of the string of result remains as original string, returns the result. 
If changes were made (meaning some duplicates were removed), simply calls itself recursively on the newly formed string. 
This ensures that any new adjacent duplicates formed by the removal of previous ones are also eliminated. 
The idea is to gradually “peel off” the duplicates layer by layer until no adjacent duplicates are left

Time Complexity: O(n2), In the worst case, the function may need to iterate almost through the entire string for each recursion, which makes the time complexity as O(N2).
Auxiliary Space: O(n2), as we are storing the new string in each recursive call and there can be n recursive call in the worst case.

## Ver2
This solution also removes adjacent duplicates but it does this by modifying the string in place. It uses an index to track where to place non-duplicate characters. It skips over duplicate characters and moves only unique characters forward. After processing the original string, trims the original string to remove extra characters. If any adjacent duplicates were removed in this process then recursively call the function itself to repeat this process again. This approach is efficient because it modifies the string directly without creating new ones.

Time Complexity: O(n2), In the worst case, the function may need to iterate almost through the entire string for each recursion, which makes the time complexity as O(n2).
Auxiliary Space: O(n), considering the recursive call stack