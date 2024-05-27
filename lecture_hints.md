## important STL

### functions:

- sort
- lower_bound, upper_bound (for binary search)
- next_permutation (use when n <= 50)
- reverse
- max_element
- accumulate

### data structures:

- vector
- map (<key, value>)
- set (unique keys)
- multiset (multiple keys allowed)
- priority_queue (returns max, use greater<> for min)

- list
- string
- deque (double-ended queue)
- queue
- stack
- array
- unordered_map
- multi_map
- tuple
- pair
- unordered_set

### complexity of datastructures

| ds             | random access | search   | insertion | removal  | insert/remove at end/beginning |
|----------------|---------------|----------|-----------|----------|--------------------------------|
| vector         | O(1)          | O(n)     | O(n)      | O(n)     | O(1)                           |
| map            | -             | O(log n) | O(log n)  | O(log n) | -                              |
| set            | -             | O(log n) | O(log n)  | O(log n) | -                              |
| multiset       | -             | O(log n) | O(log n)  | O(log n) | -                              |
| priority queue | -             |          | O(log n)  | O(log n) | -                              |
| deque          | O(1)          | -        | O(n)      | O(n)     | O(1)                           |

## Complexity

- n <= 10 `O(n!)`
- n <= 20 `O(2^n)`
- n <= 500 `O(n^3)`
- n <= 5000 `O(n^2)`
- n <= 10^6 `O(n)` / `O(n log n)`

## Algorithms

### Brute Force

- Filter: enumerate candidates, discard invalid ones
- Generator: generate only valid candidates (usually faster)

### Greedy

- Greedy Construction: create structure step by step, consider best extension of current step
- Scanline: scan linearly over input, handle all "events" appropriately

### DP

- use when
    - optimal solution consists of optimal solutions for sub-problems
    - many overlapping sub-problems (if no overlap: Divide & Conquer)
- 3 steps
    1. recursive approach/formula
    2. store solutions of sub-problems (choose datastructure, e.g. 2D-array)
    3. identify dependencies among sub-problems to find a good evaluation order

### Strings

- input: string `s`, `|s| = n`, string `t`, `|t| = m`
- problem: Find all positions where `s` occurs in `t`.
- `O(m+n)` using prefix or z function of string `s#t`
- prefix function: `p(i)` is the length of the longest proper prefix of `t[0..i]`, that is also a suffix of `t[0..i]`.
    - match if `p(k) = n`, so position of occurrence is `k - n + 1`
- z function: `z(i)` is the length of the longest common prefix of `t` and `t[i..n − 1]`

### Graphs

- adjacency matrix of undirected graph is symmetrical
- adjacency list vs. adjacency matrix (`|N(v)|` = number of outgoing edges of v)
    - memory & BFS/DFS `O(n + m)` vs. `O(n^2)`
    - find outgoing edges `O(|N(v)|)` vs. `O(n)`
    - find incoming edges `O(n + m)` vs. `O(n)`
    - insert/test/delete edge `O(|N(v)|)` vs. `O(1)`
- structure of a Tree DP
    - input
    - write custom `treeDFS`
    - create array `dp(n)`
    - call `treeDFS(graph, 0, -1, dp)`
    - output `dp[0]`
    - ```
  treeDFS(graph, node, parent, dp) {
  // handle a leaf
  for each neighbor x of node {
  if (x != parent) {
  // recursive call
  }
  }
  // compute dp[node]
  return
  }
    ```