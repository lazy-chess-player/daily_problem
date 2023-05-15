#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        int ans = 0;
        int n = matrix[0].size();
        unordered_map<string, int> cnt;
        for (auto row : matrix)
        {
            string str(n, 0);
            for (int i = 0; i < n; i++)
            {
                str[i] = row[i] ^ row[0];
            }
            ans = max(ans, ++cnt[str]);
        }
        return ans;
    }
};