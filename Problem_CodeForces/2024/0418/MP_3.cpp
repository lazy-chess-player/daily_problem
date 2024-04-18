#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int inf = 0x3f3f3f3f;

const int N = 4e5 + 100;

int a[N], b[N];

int main()
{
    //	freopen("input.txt","r",stdin);
    //	ios::sync_with_stdio(false);
    int n, I;
    scanf("%d%d", &n, &I);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    I = I * 8 / n;
    int k = I > 20 ? (1 << 20) : (1 << I);
    sort(a + 1, a + 1 + n);
    a[0] = -1; // 因为a[i]的取值范围会涉及到0，所以我们初始化一个一定与a[i]不相等的数
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            b[i] = b[i - 1];
        else
            b[i] = b[i - 1] + 1;
    }
    if (k >= b[n]) // 特判一下
        return 0 * printf("0");
    int ans;
    int l = 1, r = 1;
    int mmin = inf;
    while (r <= n) // 尺取
    {
        ans = b[r++] - b[l] + 1; // 先求出当前范围内有多少个不同的数
        if (ans > k)             // 如果这个值大于内存K的话，就让l逼近r
        {
            ans -= b[l++];
            while (ans > k) // 持续逼近
            {
                ans += b[l++]; // 注意要将之前的值加回来
                ans -= b[l];   // 然后再减去当前位置的值
            }
        }
        if (ans == k) // 如果满足条件，更新答案
            mmin = min(mmin, n - (r - l));
    }
    printf("%d\n", mmin);

    return 0;
}