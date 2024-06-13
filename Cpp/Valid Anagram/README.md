# Valid Anagram
https://leetcode.com/problems/valid-anagram/

## Strategy
Start by checking that the strings are the same length. Then, loop over the characters of the strings, counting the occurences of each letter and storing them in arrays of length 26, using `letter - 'a'` as the index. Finally, use `std::equal` to compare the 2 arrays, or just loop over them and compare them yourself.

## Complexity
#### Time: O(n)
In the best case, the strings aren't equal length and it's O(1) time.

Otherwise, we loop through the strings once to count the occurences of each letter which is O(n). Then we call `std::equals` or loop over the arrays, which is O(26) or O(1). This simplifies to O(n) overall.

#### Space: O(1)
We use 2 arrays of constant size 26 each, so O(1).
