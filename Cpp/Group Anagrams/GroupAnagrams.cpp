#include "gtest/gtest.h"

#include<vector>
#include<string>
#include<unordered_map>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs)
{
  std::unordered_map<std::string, std::vector<std::string>> countsToGroups;

  for (const std::string& str : strs)
  {
    std::string counts(26, 0); // fill constructor
    for (const char& ch : str)
    {
      ++counts[ch - 'a'];
    }
    countsToGroups[counts].push_back(str);
  }

  std::vector<std::vector<std::string>> groups;
  std::transform(
    countsToGroups.begin(),
    countsToGroups.end(),
    std::back_inserter(groups),
    [](const auto& kv) { return std::move(kv.second); }
  );

  return groups;
}

void nestedVectorSort(std::vector<std::vector<std::string>>& vec)
{
  for (auto& innerVec : vec)
  {
    std::sort(innerVec.begin(), innerVec.end());
  }
  std::sort(vec.begin(), vec.end());
}

TEST(GroupAnagrams, Test1) {
  std::vector<std::vector<std::string>> expected = { {"bat"},{"nat", "tan"},{"ate", "eat", "tea"} };
  std::vector<std::vector<std::string>> actual = groupAnagrams({ "eat", "tea", "tan", "ate", "nat", "bat" });

  // Any order is allowed for inner/outer vectors so we must sort before comparing
  nestedVectorSort(expected);
  nestedVectorSort(actual);

  EXPECT_EQ(expected, actual);
}

TEST(GroupAnagrams, Test2) {
  std::vector<std::vector<std::string>> expected = { {""} };
  std::vector<std::vector<std::string>> actual = groupAnagrams({ "" });

  EXPECT_EQ(expected, actual);
}

TEST(GroupAnagrams, Test3) {
  std::vector<std::vector<std::string>> expected = { {"a"} };
  std::vector<std::vector<std::string>> actual = groupAnagrams({ "a" });

  EXPECT_EQ(expected, actual);
}

TEST(GroupAnagrams, Test4) {
  std::vector<std::vector<std::string>> expected = {};
  std::vector<std::vector<std::string>> actual = groupAnagrams({});

  EXPECT_EQ(expected, actual);
}
