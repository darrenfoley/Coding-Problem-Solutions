#include "gtest/gtest.h"

#include <vector>
#include <unordered_map>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k)
{
  std::unordered_map<int, int> numsToCounts;
  for (const auto& num : nums)
  {
    ++numsToCounts[num];
  }

  std::vector<std::vector<int>> countBuckets(nums.size());
  for (const auto& kv : numsToCounts)
  {
    // Subtract one from count since vector starts at 0 and goes up to k - 1
    countBuckets[kv.second - 1].push_back(kv.first);
  }

  std::vector<int> answer;
  for (int i = countBuckets.size() - 1; i >= 0; --i)
  {
    answer.insert(answer.end(), countBuckets[i].begin(), countBuckets[i].end());
    if (answer.size() == k)
    {
      return answer;
    }
  }

  // Didn't find k different elements - invalid input
  return {};
}

TEST(TopKFrequentElements, Test1) {
  std::vector<int> expected = { 1, 2 };
  std::vector<int> actual = topKFrequent({ 1, 1, 1, 2, 2, 3 }, 2);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}

TEST(TopKFrequentElements, Test2) {
  std::vector<int> expected = { 1 };
  std::vector<int> actual = topKFrequent({ 1 }, 1);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}

TEST(TopKFrequentElements, Test3) {
  std::vector<int> expected = { 3, 1, -500 };
  std::vector<int> actual = topKFrequent({ 1, 3, 4, 2, 3, 99, 760, 1, -500, 1, -500 }, 3);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}

TEST(TopKFrequentElements, Test4) {
  std::vector<int> expected = { 6, -50, 1, 2, 4, -1032, 10000, 5, -10000 };
  std::vector<int> actual = topKFrequent({ 1, 6, -50, 2, -1032, 4, -10000, 10000, 5 }, 9);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}
