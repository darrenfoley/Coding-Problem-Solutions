#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int main()
{
    std::vector<std::pair<int, std::pair<std::vector<int>, bool>>> testcases = {
        {1, {{1, 2, 3, 1}, true}},
        {2, {{1, 2, 3, 4}, false}},
        {3, {{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true}}
    };

    for (const auto& testcase : testcases)
    {
        const int& testcaseNum = testcase.first;
        const std::pair<std::vector<int>, bool>& inputToExpectedResult = testcase.second;
        bool duplicateFound = containsDuplicate(inputToExpectedResult.first);
        std::string result = duplicateFound == inputToExpectedResult.second ? "Passed!" : "Failed!";
        std::cout << "Testcase " << testcaseNum << ": " << result << std::endl;
    }

    return 0;
}
