#include "gtest/gtest.h"

#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums)
{
  std::vector<int> prefix(nums.size());
  std::vector<int> suffix(nums.size());

  prefix[0] = nums[0];
  suffix[suffix.size() - 1] = nums[nums.size() - 1];
  for (int i = 1; i < nums.size() - 1; ++i)
  {
    prefix[i] = prefix[i - 1] * nums[i];
    int suffixIndex = suffix.size() - 1 - i;
    suffix[suffixIndex] = suffix[suffixIndex + 1] * nums[suffixIndex];
  }

  std::vector<int> answer(nums.size());
  for (int i = 0; i < answer.size(); ++i)
  {
    int curPrefix = i == 0 ? 1 : prefix[i - 1];
    int curSuffix = i == suffix.size() - 1 ? 1 : suffix[i + 1];
    answer[i] = curPrefix * curSuffix;
  }

  return answer;
}

TEST(ProductOfArrayExceptSelf, Test1) {
  std::vector<int> expected = { 24, 12, 8, 6 };
  std::vector<int> actual = productExceptSelf({ 1, 2, 3, 4 });
  EXPECT_EQ(expected, actual);
}

TEST(ProductOfArrayExceptSelf, Test2) {
  std::vector<int> expected = { 0, 0, 9, 0, 0 };
  std::vector<int> actual = productExceptSelf({ -1, 1, 0, -3, 3 });
  EXPECT_EQ(expected, actual);
}
