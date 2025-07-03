# Problem
Given an array `arr[]` of `n` integers and an integer target, the task is to find a pair in `arr[]` such that it’s sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:
Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: Out of all the pairs, [20, 5] has sum = 25 which is exactly 25.

Input: arr[] = [8, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target.

Input: arr[] = [10], target = 10
Output: []
Explanation: As the input array has only 1 element, return an empty array.

# Solution
## Good approach
...

Time: O(n)
Space: O(n)

### Analysis
Input: arr[] = [8, 2, 7, 1, 4], target = 10

round 1:
	ordered map m=[]
	chosen num n
	chosen pair p=[]
	i=0:
		arr[i]=8
		diff = target - arr[i] = 10-8 = 3
		arr[i] does not exist in s
		add arr[i] to map: m=[3:8]
	i=1:
		arr[i]=2
		diff = target - arr[i] = 10-2 = 8
		add arr[i] to map: m=[3:8, 8:2]
	i=2:
		arr[i]=7
		diff = target - arr[i] = 10-7 = 3
		add arr[i] to map: m=[3:8, 3:7, 8:2]
	i=3:
		arr[i]=1
		diff = target - arr[i] = 10-1 = 9
		add arr[i] to map: m=[3:8, 3:7, 8:2, 9:1]
	i=4:
		arr[i]=4
		diff = target - arr[i] = 10-4 = 6
		add arr[i] to map: m=[3:8, 3:7, 6:4, 8:2, 9:1]
	==> p = [3:7]
		n = 7	(because 3 is the smallest key in the map)
round 2:
	ordered multi map m2=[]
	i=0:
		arr[i]=8
		abs = |chosen - arr[i]| = |3 - 8| = 5
		add abs to map: m2=[5:5]
	i=1:
		arr[i]=2
		abs = |chosen - arr[i]| = |3 - 2| = 1
		add abs to map: m2=[1:2, 5:5]
	i=2:
		arr[i]=7
		abs = |chosen - arr[i]| = |3 - 7| = 4
		add abs to map: m2=[1:2, 4:7, 5:5]
	i=3:
		arr[i]=1
		abs = |chosen - arr[i]| = |3 - 1| = 2
		add abs to map: m2=[1:2, 2:1, 4:7, 5:5]
	i=4:
		arr[i]=4
		abs = |chosen - arr[i]| = |3 - 4| = 1
		add abs to map: m2=[1:2, 1:4, 2:1, 4:7, 5:5]
	==> p = [1:2, 1:4]
		m = 2 or 4
round 3:
	[1:2]
		abs = [7 - 2] = 5
		m3 = [5:2]
	[1:4]
		abs = [7 - 4] = 3
		m3 = [3:4]
	==> m = 4

summary: n = 7, m = 4



## Best approach
The idea is to sort the array and use Two Pointer Technique to find the pair with sum closest to target. 
Initialize a pointer left to the beginning of the array and another pointer right to the end of the array.
Now, compare the sum at both the pointers to find the pair sum closest to target:

If arr[left] + arr[right] < target: We need to increase the pair sum, so move left to higher value.
If arr[left] + arr[right] > target: We need to decrease the pair sum, so move right to smaller value.
If arr[left] + arr[right] == target: We have found a pair with sum = target, so we can return the pair.

Time: O(nlogn + n)
Space: O(1)

### Analysis
Input: arr[] = [8, 2, 7, 1, 4], target = 10

sorted arr[] = [1, 2, 4, 7, 8]
diff = INT_MAX
abs = INT_MIN
num1 = 0
num2 = 0
i=0, j=4
	arr[i]=1
	arr[j]=7
	sum = arr[i] + arr[j] = 1 + 7 = 8
		sum < 10  --> i++
	tmpDiff = target - sum = 10 - 8 = 2
	tmpDiff < diff
		diff = 2
		num1 = 1, num2 = 7
i=1, j=4
	arr[i]=2
	arr[j]=7
	sum = arr[i] + arr[j] = 2 + 7 = 9
		sum < 10  --> i++
	tmpDiff = target - sum = 10 - 9 = 1
	tmpDiff < diff
		diff = tempDiff = 1
		tmpAbs = |arr[i] - arr[j]| = 5
		tmpAbs > abs
			abs = tmpAbs
			num1 = 2, num2 = 7
i=2, j=4
	arr[i]=4
	arr[j]=8
	sum = arr[i] + arr[j] = 4 + 8 = 12
		sum > 10  --> j--
	tmpDiff = target - sum = |10 - 12| = 2
	tmpDiff > diff
		do nothing
i=2, j=3
	arr[i]=4
	arr[j]=7
	sum = arr[i] + arr[j] = 4 + 7 = 9
		sum < 10  --> i++
	tmpDiff = target - sum = |10 - 9| = 1
	tmpDiff == diff
		tmpAbs = |arr[i] - arr[j]| = 3
		tmpAbs < abs
			--> do nothing
i=3, j=3
	stop

### Snippet

sorted arr

i = 0
j = arr.size
diff = INT_MAX
abs = INT_MIN
num1 = 0
num2 = 0

loop i < j:
	sum = arr[i] + arr[j]
	if sum < target:
		i++
	else sum > target:
		j--
	else
		num1 = arr[i], num2 = arr[j]
		return

	tmpDiff = abs(target - sum)
	if tmpDiff <= diff:
		diff = tmpDiff
		tmpAbs = abs(arr[i] - arr[j])
		if tmpAbs >= abs:
			abs = tmpAbs
			num1 = arr[i], num2 = arr[j]