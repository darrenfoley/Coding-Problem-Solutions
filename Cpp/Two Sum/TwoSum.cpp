#include "gtest/gtest.h"

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> numsToIndex;

    for (int i = 0; i < nums.size(); ++i)
    {
        int difference = target - nums[i];
        auto it = numsToIndex.find(difference);
        if (it != numsToIndex.end())
        {
            return { it->second, i };
        }

        numsToIndex[nums[i]] = i;
    }

    // No solution found
    return {};
}

TEST(TwoSum, Test1) {
  std::vector<int> expected = { 0, 1 };
  std::vector<int> actual = twoSum({ 2, 7, 11, 15 }, 9);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}

TEST(TwoSum, Test2) {
  std::vector<int> expected = { 1, 2 };
  std::vector<int> actual = twoSum({ 3, 2, 4 }, 6);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}

TEST(TwoSum, Test3) {
  std::vector<int> expected = { 0, 1 };
  std::vector<int> actual = twoSum({ 3, 3 }, 6);
  EXPECT_TRUE(std::is_permutation(expected.begin(), expected.end(), actual.begin(), actual.end()));
}
