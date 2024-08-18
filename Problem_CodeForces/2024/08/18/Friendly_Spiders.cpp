// LUOGU_RID: 99310031
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 600005;

vector<int> a[N];
vector<int> G[N];
int d[N], p[N];
bool vis[N], np[N];
int main()
{
    int n;
    scanf("%d", &n);
    const int wc = 3e5;
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        a[x].push_back(i);
    }
    for (int i = 2; i <= wc; i++)
    {
        if (np[i])
            continue;
        for (int j = i; j <= wc; j += i)
        {
            if (j > i)
                np[j] = 1;
            for (auto x : a[j])
            {
                G[x].push_back(wc + i);
                G[wc + i].push_back(x);
            }
        }
    }
    deque<int> q;
    int s, t;
    scanf("%d%d", &s, &t);
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    q.push_back(s);
    while (q.size())
    {
        int u = q.front();
        q.pop_front();
        if (vis[u])
            continue;
        for (auto v : G[u])
        {
            int w = v > wc;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                p[v] = u;
                if (w == 0)
                    q.push_front(v);
                else
                    q.push_back(v);
            }
        }
    }
    if (d[t] == INF)
        puts("-1");
    else
    {
        vector<int> ans;
        int x = t;
        while (x)
        {
            if (x <= wc)
                ans.push_back(x);
            x = p[x];
        }
        reverse(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (auto x : ans)
            printf("%d ", x);
        puts("");
    }
    return 0;
}
