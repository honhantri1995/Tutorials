# Problem
Given an array of strings (aka dictionary) `arr[]`, and two different strings `start` and `target`, representing two words.
The task is to find the length of the smallest chain from string `start` to `target`, such that only one character of the adjacent words differs and each word exists in `arr[]`.

Note: Print `0` if it is not possible to form a chain. Each word in array `arr[]` is of same size `m` and contains only lowercase English alphabets.

## Examples:
``` python
Input: start = "toon", target = "plea", arr[] = ["poon", "plee", "same", "zoon", "poie", "plea", "ponn", "plie", "poin"]
Output: 7
Explanation: "toon" → "poon" → "poin" → "poie" → "plie" → "plee" → "plea"
```

``` python
Input: start = "abcv", target = "ebad", arr[] = ["abcd", "ebad", "ebcd", "xyza"]
Output: 4
Explanation: "abcv" → "abcd" → "ebcd" → "ebad"
```

# Solution
## BFS
- Create a queue words to store the word to visit and push `start` initially.
- At each level, go through all the words stored in queue, and for each word, check if the new word (with only one character differs) is in `arr[]` or not.
- If found, push the new word in queue, else continue.
- Each level of queue defines the length of chain, and once the target is found return the value of that level +1. If the target is never found, return -1.

### Explanation
``` c
- queue = ["toon"]
- found adjacent		=> push "poon" and "zoon", pop "toon"	=> queue = ["poon", "zoon"]				--> return value = 1
- found adjacent		=> push "ponn" and "poin", pop "poon"	=> queue = ["zoon", "ponn", "poin"]		--> return value = 2
- not found adjacent	=> pop "zoon"							=> queue = ["ponn", "poin"]
- not found adjacent	=> pop "ponn"							=> queue = ["poin"]
- found adjacent		=> push "poie", pop "poin"				=> queue = ["poie"]						--> return value = 3
- found adjacent		=> push "plie", pop "poie"				=> queue = ["plie"]						--> return value = 4
- found adjacent		=> push "plee", pop "plie"				=> queue = ["plee"]						--> return value = 5
- found adjacent		=> push "plea", pop "plee"				=> queue = ["plea"]						--> return value = 6
- "plea" is the target	 																				--> return value = 7
```

### Snippet
#### How to check if the new word (with only one character differs) is in `arr[]` or not
- Solution 1: Alter all of inputted word character for 'a' to 'z' and one-by-one compare with words in the dictionary
	``` c
	findAdjWords(inputWord, &outputWords):		// O(m*n*k)
		outputWords = []
		for (letterIdx, letterIdx < inputWord.size(), letterIdx++):
			for (character : alphabet):			// for (char c = 'a'; c <= 'z'; ++c)
				newWord = inputWord; newWord[letterIdx] = character
				if dictionary.find(newWord):
					outputWords.add(newWord)
	```

- Solution 2: Check if there are `word.size() - 1` characters in the inputted word and the word in the dictionary
	``` c
	findAdjWords(inputWord, &outputWords):		// O(m*n*k)
		outputWords = []
		for (sampleWord : dictonary):
			for (letterIdx, letterIdx < inputWord.size(), letterIdx++):
				for (character : sampleWord):
					if sampleWord.size() == inputWord.size():
						count = 0
						if inputWord[letterIdx] == charcter:
							count++
							if count == inputWord.size() - 1:
								outputWords.add(sampleWord)
					else:
						break
	```