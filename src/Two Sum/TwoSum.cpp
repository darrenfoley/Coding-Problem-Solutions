#include <iostream>
#include <functional>
#include <vector>
#include <string>

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

struct Testcase
{
    int index;
    std::function<std::vector<int>()> func;
    std::vector<int> expectedResult;
    bool GetResult() const
    {
        std::vector<int> result = func();

        return expectedResult.size() == 2
            && result.size() == 2
            // result can be in any order
            && (std::equal(result.begin(), result.end(), expectedResult.begin())
                || std::equal(result.rbegin(), result.rend(), expectedResult.begin()));
    }
};

int main()
{
    std::vector<Testcase> testcases = {
        {1, std::bind(twoSum, std::vector{2, 7, 11, 15}, 9), {0, 1}},
        {2, std::bind(twoSum, std::vector{3, 2, 4}, 6), {1, 2}},
        {3, std::bind(twoSum, std::vector{3, 3}, 6), {0, 1}}
    };

    for (const auto& testcase : testcases)
    {
        std::string result = testcase.GetResult() ? "Passed!" : "Failed!";
        std::cout << "Testcase " << testcase.index << ": " << result << std::endl;
    }

    return 0;
}
