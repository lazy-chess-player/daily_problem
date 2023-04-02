#include <iostream>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int>& v)
    {
        int n = v.size();
        int memo[55][55];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i + 1 == j) return 0;
            int& res = memo[i][j];
            if (res != -1) return res;
            res = INT_MAX;
            for (int k = i + 1; k < j; ++k)
                res = min(res, dfs(i, k) + dfs(k, j) + v[i] * v[j] * v[k]);
            return res;
        };
        return dfs(0, n - 1);
    }
};

int main()
{
    Solution s;
    vector<int> values1{ 1,2,3 };
    vector<int> values2{ 3,7,4,5 };
    vector<int> values3{ 1,3,1,4,1,5 };
    cout << s.minScoreTriangulation(values1) << endl;
    cout << s.minScoreTriangulation(values2) << endl;
    cout << s.minScoreTriangulation(values3) << endl;
    return 0;
}