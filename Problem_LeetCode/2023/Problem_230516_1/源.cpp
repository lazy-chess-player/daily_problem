#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        // ��ʼ����̬�滮����ʼֵΪһ���ϴ����
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;

        // ��̬�滮����
        for (int i = 1; i <= d; i++)
        {
            for (int j = i; j <= n; j++)
            {
                int maxDifficulty = 0;
                // �ڵ�ǰ��j�������λ�ã��ӵ�i-1�����񵽵�j-1������֮��ѡ��һ������Ѷ�
                // �������Ա�֤ÿ���������һ������
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
    cout << "����ƻ�1����С�Ѷ�: " << result1 << endl;

    vector<int> jobDifficulty2 = { 9, 9, 9 };
    int d2 = 4;
    int result2 = s.minDifficulty(jobDifficulty2, d2);
    cout << "����ƻ�2����С�Ѷ�: " << result2 << endl;

    vector<int> jobDifficulty3 = { 1, 1, 1 };
    int d3 = 3;
    int result3 = s.minDifficulty(jobDifficulty3, d3);
    cout << "����ƻ�3����С�Ѷ�: " << result3 << endl;
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