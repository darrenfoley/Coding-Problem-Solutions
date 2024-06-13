namespace CSharp
{
    public class ValidAnagramTests
    {
        public static bool IsAnagram(string s, string t)
        {
            if (s.Length != t.Length)
            {
                return false;
            }

            int[] counts = new int[26];

            for (int i = 0; i < s.Length; ++i)
            {
                ++counts[s[i] - 'a'];
                --counts[t[i] - 'a'];
            }

            return counts.All(count => count == 0);
        }

        [Fact]
        public void Test1() => Assert.True(IsAnagram("anagram", "nagaram"));

        [Fact]
        public void Test2() => Assert.False(IsAnagram("rat", "car"));

        [Fact]
        public void Test3() => Assert.False(IsAnagram("banana", "banan"));

        [Fact]
        public void Test4() => Assert.False(IsAnagram("anana", "banana"));

        [Fact]
        public void Test5() => Assert.True(IsAnagram("abcd", "abcd"));
    }
}
