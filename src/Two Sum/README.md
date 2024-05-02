# Two Sum
https://leetcode.com/problems/two-sum/

## Strategy
Use a `std::unordered_map` from number to index so that we can do lookups and insertions in O(1) time.

We loop through the input, checking if the difference between `target` and the current number has already been seen. If it has, we return the indices. Otherwise, store the current number and its index in the map.

## Complexity
#### Time: O(n)
We loop through the input once, performing O(1) operations in each iteration.

#### Space: O(n)
The `std::unordered_map` could contain up to n-1 elements if one of the solution numbers appears last in the input.
