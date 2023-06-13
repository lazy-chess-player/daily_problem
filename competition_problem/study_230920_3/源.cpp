#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define LEN (int)1e6+10

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<int> graph[LEN];
bool visited[LEN];

ll e = 0, d = 0;
void dfs(int u)
{
    for (int v : graph[u])
    {
        e++;
        if (visited[v]) continue;
        visited[v] = 1;
        d++;
        dfs(v);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    priority_queue<pll, vector<pll>, greater<>> p;
    ll ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (visited[i]) continue;
        visited[i] = 1;
        e = 0, d = 1;
        dfs(i); 
        e/=2;
        ll sum = d * (d - 1) / 2;
        ans += sum - e;
        p.push({ d, e});
    }
    if (!ans) 
    {
        pll p1 = p.top();
        p.pop();
        pll p2 = p.top();
        ll d = p1.first + p2.first;
        ll sum = d * (d - 1) / 2;
        ans = sum - (p1.second + p2.second);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}