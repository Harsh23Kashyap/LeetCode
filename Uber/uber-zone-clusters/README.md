# Uber Zone Clusters

**Difficulty:** Hard  
**Topics:** GCD, Smallest Prime Factor Sieve, Disjoint Set Union (DSU)

## Problem

Each Uber zone has a numeric signature. Two zones can communicate if `gcd(signature_i, signature_j) > 1`. Find the number of connected clusters among all zones.

### Examples

```
Input:  [2, 3, 6, 7, 4, 12, 21, 39]
Output: 1
Explanation: All zones connect through shared prime factors.

Input:  [3, 9, 5]
Output: 2
Explanation: {3,9} share factor 3. {5} is isolated.

Input:  [2, 3, 5, 7, 11]
Output: 5
Explanation: All primes, no shared factors.
```

### Constraints

- `1 <= signatures.length <= 2 * 10^4`
- `1 <= signatures[i] <= 10^5`

## Compile & Run

```bash
g++ -std=c++17 -o solution solution.cpp && ./solution
```

## Key Observations

- Brute-force O(n^2) pairwise GCD is too slow.
- Factor each number using a Smallest Prime Factor (SPF) sieve in O(max_val).
- Union zones that share any prime factor — use DSU keyed on prime factors.
- Each zone's factorization is O(log(val)), so total is O(n log(val) + max_val).
