#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e3 + 5;
struct Edge
{
    int to, nxt, w;
} edge[N << 1];
int h[N], cnt = 1;
void add(int u, int v, int w)
{
    edge[cnt] = {v, h[u], w};
    h[u] = cnt++;
}

int n, m;
int a[N];
long long dis[N][N];
bool vis[N][N];
struct node
{
    long long dis;
    int u, speed;
    bool operator<(const node &b) const &
    {
        return dis > b.dis;
    }
};
void dijkstra()
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    priority_queue<node> q;
    dis[1][a[1]] = 0;
    q.push({0, 1, a[1]});

    while (q.size())
    {
        int t = q.top().u;
        int s = q.top().speed;
        q.pop();

        if (vis[t][s])
            continue;
        vis[t][s] = 1;

        for (int i = h[t]; i; i = edge[i].nxt)
        {
            int j = edge[i].to;
            int w = edge[i].w;
            long long sp = w * 1ll * s;
            if (dis[j][s] > dis[t][s] + sp) // 不换速度
            {
                dis[j][s] = dis[t][s] + sp;
                q.push({dis[j][s], j, s});
            }
            if (dis[j][a[j]] > dis[t][s] + sp)
            {
                dis[j][a[j]] = dis[t][s] + sp;
                q.push({dis[j][a[j]], j, a[j]});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(h, 0, sizeof h);
        cnt = 1;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
        }
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dijkstra();
        long long ans = 1e18;
        for (int i = 1; i <= n; i++)
            ans = min(ans, dis[n][a[i]]);
        cout << ans << endl;
    }
    return 0;
}