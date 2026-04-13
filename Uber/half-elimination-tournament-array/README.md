# Half-Elimination Tournament Array

**Difficulty:** Medium  
**Theme:** Simulation / Array

## Problem

Given an integer array `nums`, simulate a tournament in rounds:

- In each round, process players in pairs from left to right.
- For each pair `(a, b)`, eliminate the **higher** value and keep the **lower** value.
- If the round has an odd number of players, the last player advances automatically.
- Continue until one value remains.

Return the last remaining value.

## Examples

```
nums = [8, 3, 5, 2]       -> 2
Round1: (8,3)->3, (5,2)->2 => [3,2]
Round2: (3,2)->2          => [2]

nums = [7, 4, 9, 1, 6]    -> 1
Round1: (7,4)->4, (9,1)->1, 6 advances => [4,1,6]
Round2: (4,1)->1, 6 advances            => [1,6]
Round3: (1,6)->1                        => [1]
```

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## How to Use

```bash
g++ -std=c++17 -o solution solution.cpp
./solution
```

## Key Observations

- Each round can be built into a temporary array of winners
- Winner per pair is `min(a, b)`
- Handle odd-length rounds by carrying the last value
- Time complexity is linear-ish across rounds: `O(n)`
