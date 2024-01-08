#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        // 初始化动态规划表，初始值为一个较大的数
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;

        // 动态规划计算
        for (int i = 1; i <= d; i++)
        {
            for (int j = i; j <= n; j++)
            {
                int maxDifficulty = 0;
                // 在当前第j个任务的位置，从第i-1个任务到第j-1个任务之间选择一个最大难度
                // 这样可以保证每天至少完成一个任务
                for (int k = j - 1; k >= i - 1; k--)
                {
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxDifficulty);
                }
            }
        }
        return dp[d][n] == 1e9 ? -1 : dp[d][n];
	}
};

void test()
{
    Solution s;
    vector<int> jobDifficulty1 = { 6, 5, 4, 3, 2, 1 };
    int d1 = 2;
    int result1 = s.minDifficulty(jobDifficulty1, d1);
    cout << "任务计划1的最小难度: " << result1 << endl;

    vector<int> jobDifficulty2 = { 9, 9, 9 };
    int d2 = 4;
    int result2 = s.minDifficulty(jobDifficulty2, d2);
    cout << "任务计划2的最小难度: " << result2 << endl;

    vector<int> jobDifficulty3 = { 1, 1, 1 };
    int d3 = 3;
    int result3 = s.minDifficulty(jobDifficulty3, d3);
    cout << "任务计划3的最小难度: " << result3 << endl;
}

int main() {
    test();
    return 0;
}

int main()
{
	test();
	return 0;
}