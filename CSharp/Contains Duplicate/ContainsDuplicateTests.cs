namespace CSharp
{
    public class ContainsDuplicateTests
    {
        public bool ContainsDuplicate(int[] nums)
        {
            HashSet<int> set = new();

            foreach (int num in nums)
            {
                if (set.Contains(num))
                {
                    return true;
                }
                set.Add(num);
            }

            return false;
        }

        [Fact]
        public void Test1() => Assert.True(ContainsDuplicate([1, 2, 3, 1]));

        [Fact]
        public void Test2() => Assert.False(ContainsDuplicate([1, 2, 3, 4]));

        [Fact]
        public void Test3() => Assert.True(ContainsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]));
    }
}
