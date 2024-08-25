#include <bits/stdc++.h>
using namespace std;
int n, cn[300900], cnt, m = 2750151, a[500900], f[3800900], q[3800900];
bool v[3800900], vv[500900];
vector<int> ss[3800900];
int main()
{
    v[0] = v[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        if (v[i] == 0)
            cn[++cnt] = i;
        for (int j = 1; j <= cnt && i * cn[j] <= m; j++)
        {
            v[i * cn[j]] = 1;
            if (q[i * cn[j]] == 0)
                q[i * cn[j]] = i;
            if (i % cn[j] == 0)
                break;
        }
    }
    scanf("%d", &n);
    n *= 2;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (v[a[i]] == 0)
        {
            if (a[i] <= 199999)
                f[cn[a[i]]] = a[i];
        }
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        ss[a[i]].push_back(i);
    for (int i = n; i > 0; i--)
        if (vv[i] == 0)
        {
            if (v[a[i]] == 1)
            {
                printf("%d ", a[i]);
                vv[i] = 1;
                ss[a[i]].pop_back();
                vv[ss[q[a[i]]].back()] = 1;
                ss[q[a[i]]].pop_back();
            }
            else
            {
                printf("%d ", f[a[i]]);
                vv[i] = 1;
                ss[a[i]].pop_back();
                vv[ss[f[a[i]]].back()] = 1;
                ss[f[a[i]]].pop_back();
            }
        }
    return 0;
}