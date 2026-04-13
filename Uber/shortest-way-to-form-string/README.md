# Shortest Way to Form String (LC 1055 variant)

**Difficulty:** Medium  
**Based on:** [LeetCode 1055 - Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/)

## Problem

Given strings `s` (source) and `t` (target), return the minimum number of subsequences of `s` that concatenate to form `t`. Return `-1` if impossible.

## Examples

```
s="abc", t="abcbc"  -> 2   ("abc" + "bc")
s="abc", t="acdbc"  -> -1  ('d' not in s)
s="xyz", t="xzyxz"  -> 3   ("xz" + "y" + "xz")
```

## Constraints

- `1 <= s.length, t.length <= 10^4`
- lowercase English letters only

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- If any char in `t` doesn't exist in `s`, immediately return -1
- Greedily scan through `s` matching chars of `t`; each full scan of `s` = one copy
- Count how many full scans you need to exhaust `t`
