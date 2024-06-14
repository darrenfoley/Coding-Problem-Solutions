namespace CSharp
{
    public class TopKFrequentElementsTests
    {
        public static int[] TopKFrequent(int[] nums, int k)
        {
            Dictionary<int, int> numsToCounts = new(nums.Length);

            foreach (int num in nums)
            {
                numsToCounts.TryAdd(num, 0);
                ++numsToCounts[num];
            }

            PriorityQueue<int, int> priorityQueue = new(nums.Length);
            foreach (KeyValuePair<int, int> kv in numsToCounts)
            {
                priorityQueue.Enqueue(kv.Key, -kv.Value);
            }

            List<int> answer = [];
            while (priorityQueue.Count > 0)
            {
                answer.Add(priorityQueue.Dequeue());
                if (answer.Count == k)
                {
                    break;
                }
            }

            return answer.ToArray();
        }

        [Fact]
        public void Test1()
        {
            int[] expected = [1, 2];
            int[] actual = TopKFrequent([1, 1, 1, 2, 2, 3], 2);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test2()
        {
            int[] expected = [1];
            int[] actual = TopKFrequent([1], 1);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test3()
        {
            int[] expected = [3, 1, -500];
            int[] actual = TopKFrequent([1, 3, 4, 2, 3, 99, 760, 1, -500, 1, -500], 3);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test4()
        {
            int[] expected = [6, -50, 1, 2, 4, -1032, 10000, 5, -10000];
            int[] actual = TopKFrequent([1, 6, -50, 2, -1032, 4, -10000, 10000, 5], 9);
            Assert.Equivalent(expected, actual, true);
        }
    }
}
