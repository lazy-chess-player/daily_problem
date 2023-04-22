#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;


//class Solution
//{
//public:
//    vector<int> dp;
//    int dfs(vector<int> nums, int i)
//    {
//        if (dp[i])
//            return dp[i];
//        if (i == nums.size() - 1)
//            return 1;
//        int max_len = 1;
//        for (int j = i + 1; j < nums.size(); j++)
//        {
//            if (nums[j] > nums[i])
//                max_len = max(max_len, dfs(nums, j) + 1);
//        }
//        dp[i] = max_len;
//        return max_len;
//    }
//    int lengthOfLIS(vector<int>& nums)
//    {
//        int n = nums.size();
//        dp.resize(n);
//        int ans = 1;
//        for (int i = 0; i < n; i++)
//        {
//            ans = max(ans, dfs(nums, i));
//        }
//        return ans;
//    }
//};

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n - 1; i > -1; i--)
        {
            for (int j = i+1; j < n; j++)
            {
                if (nums[j] > nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


void testLengthOfLIS()
{
    Solution s;
    vector<vector<int>> testCases
    {
        {10,9,2,5,3,7,101,18}, // expected output: 4
        {5,3,4,8,6,7,9}, // expected output: 5
        {0,1,0,3,2,3}, // expected output: 4
        {7,7,7,7,7,7,7}, // expected output: 1
        {1,2,3,4,5,6,7}, // expected output: 7
        {7,6,5,4,3,2,1}, // expected output: 1
    };
    for (auto& testCase : testCases)
    {
        int result = s.lengthOfLIS(testCase);
        cout << "Input: ";
        for (auto& num : testCase)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "Output: " << result << endl;
        cout << endl;
    }
}

int main()
{
    testLengthOfLIS();
    return 0;
}
