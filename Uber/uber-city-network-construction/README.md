# Uber City Network Construction (MST)

**Difficulty:** Medium

## Problem

Given `n` cities and a list of weighted undirected edges, find the minimum total cost to connect all cities. Return -1 if impossible.

## Examples

```
n=4, edges={{0,1,1},{0,2,4},{1,2,2},{2,3,3}} -> 6
n=3, edges={{0,1,5},{1,2,3}}                  -> 8
n=3, edges={{0,1,2}}                          -> -1
```

## Constraints

- `1 <= n <= 10^4`
- `0 <= edges.length <= 10^5`
- `edges[i] = {u, v, cost}`, `1 <= cost <= 10^6`
- 0-indexed cities

## Compile & Run

```bash
g++ -std=c++17 -o solution solution.cpp && ./solution
```

## Key Observations

- Classic MST — Kruskal's (sort + union-find) or Prim's (min-heap)
- Kruskal's: sort edges by weight, greedily add if it doesn't form a cycle
- Need exactly `n-1` edges for a spanning tree; if fewer, graph is disconnected
- Union-Find with path compression + union by rank gives near O(1) per operation
