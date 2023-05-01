#include <iostream>
#include <vector>
#include<functional>

using namespace std;

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> dp(n);
        for (int i =0;i<n;i++)
        {
            if (manager[i] >= 0)
                dp[manager[i]].push_back(i);
        }
        function<int(int)> dfs = [&](int i) -> int
        {
            int ans = 0;
            for (int j : dp[i])
            {
                ans = max(ans, dfs(j) + informTime[i]);
            }
            return ans;
        };
        return dfs(headID);
    }
};

void test()
{
    Solution s;
    vector<int> manager = { -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19 };
    vector<int> informTime = { 0, 4, 4, 0, 0, 4, 5, 6, 7, 0, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int n = manager.size();
    int headID = 4;
    int ans = s.numOfMinutes(n, headID, manager, informTime);
    cout << "Answer: " << ans << endl;  // 7
}

int main()
{
    test();
    return 0;
}
