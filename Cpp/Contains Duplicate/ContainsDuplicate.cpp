#include "gtest/gtest.h"

#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums)
{
    std::unordered_set<int> seen;

    for (const int& num : nums)
    {
        auto [it, inserted] = seen.insert(num);
        if (!inserted)
        {
            return true;
        }
    }

    return false;
}

TEST(ContainsDuplicate, Test1) {
  EXPECT_TRUE(containsDuplicate({ 1, 2, 3, 1 }));
}

TEST(ContainsDuplicate, Test2) {
  EXPECT_FALSE(containsDuplicate({ 1, 2, 3, 4 }));
}

TEST(ContainsDuplicate, Test3) {
  EXPECT_TRUE(containsDuplicate({ 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 }));
}
