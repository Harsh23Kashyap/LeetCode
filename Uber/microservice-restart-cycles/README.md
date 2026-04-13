# Microservice Restart Cycles (LC 210 variant)

**Difficulty:** Medium  
**Based on:** [LeetCode 210 - Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)

## Problem

Given `n` microservices and dependency pairs `[a, b]` (b must start before a), return a valid startup order. Return empty array if circular dependency exists.

## Examples

```
n=4, deps=[[1,0],[2,0],[3,1],[3,2]] -> [0,1,2,3] or [0,2,1,3]
n=2, deps=[[1,0],[0,1]]             -> [] (cycle)
n=3, deps=[]                         -> [0,1,2] (any order)
```

## Constraints

- `1 <= n <= 2000`
- `0 <= deps.length <= 5000`

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- This is topological sort — BFS (Kahn's) or DFS
- Build adjacency list + in-degree array
- Start with nodes that have no dependencies (in-degree 0)
- If result size < n, there's a cycle
