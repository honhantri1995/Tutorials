[Medium] Permutations of a String

## Problem:
Given a string s, which may contain duplicate characters. Generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:
Input         Output
s = "ABC"     ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
s = "ABSG"    ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
s = "AAA"     ["AAA"]

Constraints:
- 1 <= s.size() <= 9
- s contains only Uppercase english alphabets


## Ver1 - Using iterative
O(n^2)
FIXME: Output is wrong

## Ver2 - Using recursion
### Idea:
The idea is to use backtracking to generate all possible permutations of given string s. 
To do so, first initialize an array of string ans[] to store all the permutations. 
Start from the 0th index and for each index i, swap the value s[i] with all the elements in its right i.e. from i+1 to n-1, and recur to the index i + 1. 
If the index i is equal to n, store the resultant string in ans[], else keep operating similarly for all other indices. Thereafter, swap back the values to original values to initiate backtracking. 
At last sort the array ans[].

O(n!)