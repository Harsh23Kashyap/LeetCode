# Verifying Text Order Rule

**Difficulty:** Medium  
**Theme:** Pattern / Ordering Validation

## Problem

You are given:

- `order`: a string of distinct lowercase characters describing the allowed character order
- `text`: a long lowercase string

Return `true` if `text` respects `order`, else return `false`.

Rules:

1. Consider only characters in `text` that also appear in `order`.
2. Their mapped positions in `order` must be non-decreasing from left to right.
3. Characters not present in `order` are ignored.

## Examples

```
order = "abc", text = "aaxbbcc"   -> true
order = "abc", text = "abca"      -> false   (a appears after c)
order = "hlo", text = "hello"     -> true
order = "hlo", text = "ohl"       -> false
```

## Constraints

- `1 <= order.length <= 26`
- `1 <= text.length <= 10^5`
- `order` has distinct lowercase letters
- `text` contains lowercase letters

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- Build rank/index for each character in `order`
- Scan `text` once and ignore non-`order` characters
- The seen rank sequence must never decrease
