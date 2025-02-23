## Problem
Given an array arr[] of n elements, write a function to sort this array in an ascending order.

## Idea
Quick sort is a recursive algorithm based on Divide and Conquer technique. It's similar to Merge sort, but smarter.
It picks an element as pivot and partitions the array around that pivot. The pivot can be picked in different ways:
- Always pick first element as pivot.
- Always pick last element as pivot (illustration below).
- Pick a random element as pivot.
- Pick median as pivot.

The key process in quick sort is partition: put all smaller elements (than the pivot) before the pivot (if ascending order), and put all greater elements (than the pivot) after the pivot. All this should be done in linear time. Then place the pivot at its correct place.

## Time complexity

## Space complexity
