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

int main()
{
    // tuple: index, isAnagram bound with params, expected result
    std::vector<std::tuple<int, std::function<bool()>, bool>> testcases = {
        {1, std::bind(isAnagram, "anagram", "nagaram"), true},
        {2, std::bind(isAnagram, "rat", "car"), false},
        {3, std::bind(isAnagram, "banana", "banan"), false},
        {4, std::bind(isAnagram, "abcd", "abcd"), true}
    };

    for (const auto& testcase : testcases)
    {
        const int& testcaseNum = std::get<0>(testcase);
        const std::function<bool()>& func = std::get<1>(testcase);
        const bool& expectedResult = std::get<2>(testcase);
        std::string result = func() == expectedResult ? "Passed!" : "Failed!";
        std::cout << "Testcase " << testcaseNum << ": " << result << std::endl;
    }

    return 0;
}
