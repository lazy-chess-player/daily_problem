#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

constexpr int INF = 0x3f3f3f3f;

class Solution
{
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        arr1.push_back(INF);
        arr1.insert(arr1.begin(), -1);
        int n = arr1.size();
        int m = arr2.size();
        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr1[i - 1] < arr1[i])
                dp[i] = min(dp[i], dp[i - 1]);
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            for (int j = 1; j <= min(i - 1, k); ++j)
            {
                if (arr1[i - j - 1] < arr2[k - j])
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
            }
        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};
