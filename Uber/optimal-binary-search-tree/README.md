# 13. Optimal Binary Search Tree (DP on trees)

**Difficulty:** Hard  
**Classic:** Knuth's Optimal BST

## Problem

Given `n` sorted keys and their search frequencies, find the minimum total weighted search cost of a BST, where cost = `sum(freq[i] * depth(key[i]))` with root at depth 1.

## Examples

```
keys=[10,12,20], freq=[34,8,50]  -> 142
  Tree: 20 root, 10 left, 12 right-of-10
  Cost: 50*1 + 34*2 + 8*3 = 142

keys=[10,12], freq=[34,50]  -> 118
keys=[1,2,3,4], freq=[1,1,1,1]  -> 8
```

## Constraints

- `1 <= n <= 500`
- `1 <= freq[i] <= 10^4`

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- `dp[i][j]` = min cost BST for keys `i..j`
- Try each key `r` in `[i..j]` as root: `cost = sum(freq[i..j]) + dp[i][r-1] + dp[r+1][j]`
- The `sum(freq)` term accounts for all nodes going one level deeper when placed under root `r`
- Prefix sums speed up range frequency queries
- O(n^3) time, O(n^2) space. Knuth's optimization can reduce to O(n^2)
