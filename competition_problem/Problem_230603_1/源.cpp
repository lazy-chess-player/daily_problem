#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ��¼������
unordered_map<long long, unordered_map<long long, long long>> dp;

// �ݹ麯���������(x, y)��(a, b)����С�˺�
long long dfs(long long x, long long y, long long a, long long b)
{
    // ����Ѿ�����Ŀ��λ�ã����ص�ǰ�˺�
    if (x == a || y == b)
        return (a - x) * (ceil(b / (double)y) - 1);

    // �����dp�����Ƿ���ڼ�����
    if (dp[x].count(y) > 0)
        return dp[x][y];

    // �����(x, y)��(a, b)����С�˺�
    long long t = (a - x) * (ceil(b / (double)y) - 1);
    long long res = min(dfs(x, y + 1, a, b) + t, dfs(x + 1, y, a, b) + t);

    // ����������������
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
