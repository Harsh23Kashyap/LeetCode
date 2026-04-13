# 4. Cab-Sharing Logs (LC 1101 variant)

**Difficulty:** Medium  
**Based on:** [LeetCode 1101 - The Earliest Moment When Everyone Become Friends](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/)

## Problem

Given `n` users and a list of cab-sharing logs `{timestamp, userA, userB}`:

Implement:
1. **earliestAllConnected(n, logs)** — earliest timestamp when all users are in one group (-1 if never)
2. **countGroups(n, logs)** — number of connected groups after processing all logs

Logs may be unsorted by timestamp.

## Examples

```
n=4, logs: (1,0,1) (2,1,2) (3,2,3)  -> earliest=3, groups=1
n=4, logs: (1,0,1) (2,2,3)          -> earliest=-1, groups=2
```

## Constraints

- `2 <= n <= 10^4`
- `1 <= logs.size() <= 10^5`
- `0 <= userA, userB < n`, `userA != userB`

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- Sort logs by timestamp first
- Think Union-Find / DSU
- Track component count as you union
