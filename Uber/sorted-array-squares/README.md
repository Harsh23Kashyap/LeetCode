# 5. Reorder Sorted Array by Squares (LC 977 variant)

**Difficulty:** Medium  
**Based on:** [LeetCode 977 - Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)

## Problem

Given a sorted integer array `nums`, return the squares sorted in non-decreasing order.

**Follow-up:** Return the k-th smallest squared element in O(log n) without building the full array.

## Examples

```
nums = [-4,-1,0,3,10]  -> [0,1,9,16,100]
nums = [-7,-3,2,3,11]  -> [4,9,9,49,121]
nums = [-4,-1,0,3,10], k=3 -> 9
```

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in non-decreasing order

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- Squares of negatives are large, squares near zero are small
- The largest square is at one of the two ends
- Two pointers from both ends, filling result from back to front
- For k-th element: binary search on the answer value, count how many squares are <= that value
