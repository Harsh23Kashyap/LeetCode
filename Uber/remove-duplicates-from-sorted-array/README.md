# 26. Remove Duplicates from Sorted Array

**Difficulty:** Easy  
**LeetCode:** [Problem Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

## Problem

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates **in-place** such that each unique element appears only once. The relative order of the elements should be kept the same. Return the number of unique elements `k`.

The first `k` elements of `nums` must contain the unique values in their original order. Elements beyond index `k` don't matter.

## Examples

```
Input:  nums = [1,1,2]
Output: k = 2, nums = [1,2,_]

Input:  nums = [0,0,1,1,1,2,2,3,3,4]
Output: k = 5, nums = [0,1,2,3,4,_,_,_,_,_]
```

## Constraints

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` is sorted in non-decreasing order

## How to Use

```bash
# Compile
g++ -std=c++17 -o solution solution.cpp

# Run
./solution
```

1. Open `solution.cpp`
2. Implement the `removeDuplicates` function
3. Compile and run to validate against the reference solution

## Key Observations

- The array is already sorted — duplicates are adjacent
- Must be done in-place (O(1) extra memory)
- Think about what pointer(s) you need to track placement
