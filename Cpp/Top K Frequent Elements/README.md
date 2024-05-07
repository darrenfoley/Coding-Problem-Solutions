# Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/

## Strategy
Get the frequencies of the input numbers, then place them into a `std::vector` of count buckets, where the index is the count. Finally, iterate over the count buckets in reverse order until you have `k` elements.

## Complexity
#### Time: O(n)
1. We loop through `nums` once to count them - O(n).
2. We loop through the counted nums once to put them in `countBuckets` - O(n).
3. We loop through the countsToNums `std::vector` which is the same size as `nums`. In the worst case, all the numbers are in the final bucket (count 1) - O(n).
4. We insert into `k` elements into `answer`. `k` is at most the same size as `nums` - O(n).

This simplifies to O(n).

#### Space: O(n)
1. We have `numsToCounts`, which has the same number of entries as `nums` - O(n).
2. We have `countBuckets`, which is the same size as `nums` - O(n).
3. We have `answer`, which is at most the same size as `nums` - O(n).

This simplifies to O(n).
