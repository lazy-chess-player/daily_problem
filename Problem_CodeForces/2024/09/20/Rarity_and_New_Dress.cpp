#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2010;
int Q, n, m, a[N][N];
ll ans, f[N][N];
char ch;

int main()
{
    // 读取网格的行数和列数
    scanf("%d%d", &n, &m);

    // 读取网格，并将字符转换为数值（'a'->1, 'b'->2, ..., 'z'->26）
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            while (ch = getchar())
                if (ch >= 'a' && ch <= 'z')
                    break;
            a[i][j] = ch - 'a' + 1;
        }

    // 动态规划计算每个单元格的最大菱形高度
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                f[i][j] = 1LL; // 第一行的每个单元格只能形成高度为1的菱形
            }
            else if (a[i][j] != a[i - 1][j - 1] || a[i][j] != a[i - 1][j + 1] || a[i][j] != a[i - 2][j])
            {
                f[i][j] = 1LL; // 如果当前单元格颜色与左上、右上、上方单元格不同，最大高度为1
            }
            else
            {
                // 否则，可以基于上方、左上、右上单元格的DP值扩展
                f[i][j] = 1LL + min({f[i - 1][j - 1], f[i - 1][j + 1], f[i - 2][j]});
            }
        }

    // 累计所有菱形的数量
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == a[i - 1][j])
                ans += min(f[i][j], f[i - 1][j] + 1); // 判断是否可以基于上方单元格扩展
            else
                ans++; // 否则，当前单元格只能形成高度为1的菱形
        }

    // 输出结果
    cout << ans;
    return 0;
}
