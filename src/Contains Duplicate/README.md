# Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

## Strategy
Iterate over the input once, inserting each element into a `std::unordered_set`. If ever an insertion fails, that means the set already contains that element and the input has at least 1 duplicate. However, if we make it through the entire input without a failed insertion, then we know no duplicates are present.

## Complexity
#### Time: O(n)

In the worst case, we iterate over all n elements of the input once. In each iteration, we call `std::unordered_set::insert`, which is O(1) on average.

#### Space: O(n)

We use a `std::unordered_set` that contains at most n elements.
