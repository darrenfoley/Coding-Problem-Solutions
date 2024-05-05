# Group Anagrams
https://leetcode.com/problems/group-anagrams/

## Strategy
Generate a key for each input string based on its character counts, grouping the strings with the same key together using a `std::unordered_map` from key to anagram group.

## Complexity
#### Time: O(mn)
We have an outer loop iterating over the input strings and an inner loop iterating over the characters in each string, so we have O(mn) where m is the number of input strings and n is the length of the longest string.

#### Space: O(mn)
We have a `std::unordered_map` to hold the mappings from counts to anagram groups. In the worst case each group will contain only one string so the space complexity will be O(m(n + 26)), where m is the number of input strings, n is the length of the longest string, and 26 is the size of each of the count strings used as keys. This simplifies to O(mn).

We also have a `std::vector` to hold the anagram groups for return. However, we use std::move here, meaning we're not actually creating a new copy of the group, so we can ignore this.
