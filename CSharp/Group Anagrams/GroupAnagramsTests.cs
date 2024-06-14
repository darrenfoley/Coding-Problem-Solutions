namespace CSharp.Group_Anagrams
{
    public class GroupAnagramsTests
    {
        public static IList<IList<string>> GroupAnagrams(string[] strs)
        {
            Dictionary<string, IList<string>> countsToGroups = [];

            foreach (string str in strs)
            {
                char[] counts = new char[26];
                foreach (char ch in str)
                {
                    ++counts[ch - 'a'];
                }
                string key = new(counts);
                if (!countsToGroups.TryGetValue(key, out IList<string>? group))
                {
                    group = new List<string>();
                    countsToGroups[key] = group;
                }
                group.Add(str);
            }

            return countsToGroups.Values.ToList();
        }

        [Fact]
        public void Test1()
        {
            IList<IList<string>> expected = [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]];
            IList<IList<string>> actual = GroupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test2()
        {
            IList<IList<string>> expected = [[""]];
            IList<IList<string>> actual = GroupAnagrams([""]);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test3()
        {
            IList<IList<string>> expected = [["a"]];
            IList<IList<string>> actual = GroupAnagrams(["a"]);
            Assert.Equivalent(expected, actual, true);
        }

        [Fact]
        public void Test4()
        {
            IList<IList<string>> expected = [];
            IList<IList<string>> actual = GroupAnagrams([]);
            Assert.Equivalent(expected, actual, true);
        }
    }
}
