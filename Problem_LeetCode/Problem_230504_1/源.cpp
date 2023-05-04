#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k)
    {
        int l = 0;
        int n = fruits.size();
        int cnt = 0;
        if (fruits[0][0] > startPos + k || fruits[n - 1][0] < startPos - k)
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (fruits[i][0] >= startPos - k)
            {
                l = i;
                break;
            }
        }
        int r = l;
        while(r < n && fruits[r][0] <= startPos)
        {
            cnt += fruits[r][1];
            r++;
        }
        int ans = cnt;
        while (r < n && fruits[r][0] <= startPos + k)
        {
            cnt += fruits[r][1];
            while (fruits[r][0] * 2 - fruits[l][0] - startPos > k && fruits[r][0] - fruits[l][0] * 2 + startPos > k)
            {
                cnt -= fruits[l][1];
                l++;
            }
            ans = max(cnt, ans);
            r++;
        }
        return ans;
    }
};


void test()
{
    Solution s;
    vector<vector<int>> fruits = { {0, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 1} };
    int startPos = 1;
    int k = 3;
    int res = s.maxTotalFruits(fruits, startPos, k);
    cout << res << endl;//10
}


int main()
{
    test();
    return 0;
}