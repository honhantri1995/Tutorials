## Problem
Given an array arr[] of n elements, write a function to sort this array in an ascending order.

## Idea
Merge sort is a recursive algorithm based on Divide and Conquer technique.
It continuously splits the array in half until it cannot be further divided i.e., the array has only one element left (an array with one element is always sorted). Then the sorted subarrays are merged into one sorted array.

Example: arr[] = {38, 27, 43, 10}
	Dividing step:
		1st dividing: {38, 27, 43, 10} -> {38, 27} and {43, 10}
		2nd dividing: {38, 27} -> {38} and {27};      {43, 10} -> {43} and {10}
		Stop dividing because now no longer be divided more.
	Merging step:
		Sorted subarrays are merged together: {27, 38}, {10, 43}
		Continuing mergeing until the sorted array is built from the smaller subarrays.: {10, 27, 38, 43}

## Time complexity
O(nlogn) – The array is divided into halves O(logn), and merging takes linear time O(n).

## Space complexity
O(n) – Additional space is used for the temporary arrays during the merge process.


## Ver1:
Merge sort + bubble sort O(n^2 logn)

## Ver2:
Merge sort O(nlogn)