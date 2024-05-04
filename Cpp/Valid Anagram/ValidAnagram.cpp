#include "gtest/gtest.h"

#include <iostream>
#include <functional>
#include <tuple>
#include <string>
#include <vector>

bool isAnagram(const std::string& s, const std::string& t)
{
    // If they aren't the same length, they can't be anagrams
    if (s.length() != t.length())
    {
        return false;
    }

    int sCounts[26] = { 0 };
    int tCounts[26] = { 0 };

    for (int i = 0; i < s.length(); ++i)
    {
        ++sCounts[s[i] - 'a'];
        ++tCounts[t[i] - 'a'];
    }

    return std::equal(sCounts, std::end(sCounts), tCounts);
}

TEST(ValidAnagram, Test1) {
  EXPECT_TRUE(isAnagram("anagram", "nagaram"));
}

TEST(ValidAnagram, Test2) {
  EXPECT_FALSE(isAnagram("rat", "car"));
}

TEST(ValidAnagram, Test3) {
  EXPECT_FALSE(isAnagram("banana", "banan"));
}

TEST(ValidAnagram, Test4) {
  EXPECT_FALSE(isAnagram("anana", "banana"));
}

TEST(ValidAnagram, Test5) {
  EXPECT_TRUE(isAnagram("abcd", "abcd"));
}
