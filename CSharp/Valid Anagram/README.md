# Valid Anagram
https://leetcode.com/problems/valid-anagram/

## Strategy
Start by checking that the strings are the same length. Then, create a `count` array of length 26, for which `letter - 'a'` will be the index. Next, loop over the characters of the strings, incrementing `count[string1Letter - 'a']` for one string and decrementing `count[string2Letter - 'a'`] for the other string. Finally, check that all values in the `count` array are equal to `0`.

## Complexity
#### Time: O(n)
In the best case, the strings aren't equal length and it's O(1) time.

Otherwise, we loop through the strings once to count the occurences of each letter which is O(n). Then we check if the `count` array only contains `0`s, which is O(1) since the length is always 26. This simplifies to O(n) overall.

#### Space: O(1)
We use a count array of constant size 26, so O(1).
