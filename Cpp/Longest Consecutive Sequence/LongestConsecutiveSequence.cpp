#include "gtest/gtest.h"

#include <vector>
#include <unordered_set>

int longestConsecutive(const std::vector<int>& nums)
{
  std::unordered_set<int> numSet(nums.begin(), nums.end());

  int longest = 0;
  for (const auto& num : nums)
  {
    // If this is the start of a sequence, check if it is longer than the current longest
    if (!numSet.contains(num - 1))
    {
      int length = 0;
      while (numSet.contains(num + length)) ++length;
      longest = std::max(longest, length);
    }
  }

  return longest;
}

TEST(LongestConsecutiveSequence, Test1) {
  int expected = 4;
  int actual = longestConsecutive({ 100, 4, 200, 1, 3, 2 });
  EXPECT_EQ(expected, actual);
}

TEST(LongestConsecutiveSequence, Test2) {
  int expected = 9;
  int actual = longestConsecutive({ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 });
  EXPECT_EQ(expected, actual);
}
