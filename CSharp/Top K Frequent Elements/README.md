# Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/

## Strategy
Get the frequencies of the input numbers, then place them into a `PriorityQueue` where the priorities are the negated counts. Finally, Dequeue elements from the `PriorityQueue` until you have `k` elements.

## Complexity
#### Time: O(n)
1. We loop through `nums` once to count them - O(n).
2. We loop through the counted nums once to `Enqueue` them in the `PriorityQueue` - O(n).
3. We `Dequeue` elements from the `PriorityQueue` and insert them into `answer` (a `List`) at most n times (if `k == nums.Length`) - O(n).
4. We convert `answer` to an array - O(n).

This simplifies to O(n).

#### Space: O(n)
1. We have `numsToCounts`, which has the same number of elements as `nums` - O(n).
2. We have `priorityQueue`, which has the same number of elements as `nums` - O(n).
3. We have `answer`, which is at most the same size as `nums` - O(n).

This simplifies to O(n).
