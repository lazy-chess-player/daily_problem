#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 记录计算结果
unordered_map<long long, unordered_map<long long, long long>> dp;

// 递归函数，计算从(x, y)到(a, b)的最小伤害
long long dfs(long long x, long long y, long long a, long long b)
{
    // 如果已经到达目标位置，返回当前伤害
    if (x == a || y == b)
        return (a - x) * (ceil(b / (double)y) - 1);

    // 检查中dp数组是否存在计算结果
    if (dp[x].count(y) > 0)
        return dp[x][y];

    // 计算从(x, y)到(a, b)的最小伤害
    long long t = (a - x) * (ceil(b / (double)y) - 1);
    long long res = min(dfs(x, y + 1, a, b) + t, dfs(x + 1, y, a, b) + t);

    // 将计算结果存入数组
    dp[x][y] = res;

    return res;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    cout << dfs(0, 1, a, b) << endl;

    return 0;
}
