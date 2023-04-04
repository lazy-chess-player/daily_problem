#include <iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int mergeStones(vector<int>& stones, int k)
    {
        if ((stones.size() - 1) % (k - 1))
        {
            return -1;
        }

        vector<int> dp(stones.size() - k + 1);
        int ans = 0;
        while (stones.size()>1)
        {
            for (int i = 0; i < stones.size() - k + 1; i++)
            {
                for (int j = i; j < i + k; j++)
                {
                    dp[i] += stones[j];
                }
            }

            int lc = 0;
            int mn = 1e9;
            for (int i = 0; i < dp.size(); i++)
            {
                if (dp[i] < mn)
                {
                    mn = dp[i];
                    lc = i;
                }
                dp[i] = 0;
            }

            ans += mn;

            stones[lc] = mn;
            for (int i = 1; i < k; i++)
            {
                if (stones.size() != k)
                    dp.pop_back();
                stones.erase(stones.begin() + lc + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> stones{ 6,4,4,6 };
    int K = 3;
    cout << s.mergeStones(stones, K) << endl;
    return 0;
}