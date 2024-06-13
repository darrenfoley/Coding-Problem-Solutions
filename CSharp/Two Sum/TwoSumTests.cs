namespace CSharp
{
    public class TwoSumTests
    {
        public static int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, int> numsToIndex = new();

            for (int i = 0; i < nums.Length; ++i)
            {
                int difference = target - nums[i];
                if (numsToIndex.TryGetValue(difference, out int otherIndex))
                {
                    return [i, otherIndex];
                }
                numsToIndex[nums[i]] = i;
            }

            return []; // no answer found
        }

        [Fact]
        public void Test1()
        {
            int[] expected = [0, 1];
            int[] actual = TwoSum([2, 7, 11, 15], 9);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test2()
        {
            int[] expected = [1, 2];
            int[] actual = TwoSum([3, 2, 4], 6);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test3()
        {
            int[] expected = [0, 1];
            int[] actual = TwoSum([3, 3], 6);
            Assert.Equivalent(expected, actual, true);
        }
    }
}
