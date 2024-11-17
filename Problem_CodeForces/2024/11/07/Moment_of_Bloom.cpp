#include <bits/stdc++.h>

using namespace std;

#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
inline T read()
{
    T x = 0;
    int y = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * y;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/
void solve()
{
    const int N = 3e5 + 5;
    int n, m;
    cin >> n >> m;

    vvi adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vvi tree(n + 1);
    vb vis(n + 1);
    auto dfs = [&](auto &self, int u) -> void
    {
        vis[u] = 1;
        for (int v : adj[u])
        {
            if (vis[v])
                continue;
            tree[u].pb(v);
            tree[v].pb(u);
            self(self, v);
        }
    };

    dfs(dfs, 1);
    int q;
    cin >> q;
    vi a(q + 1), b(q + 1);
    vi f(n + 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i] >> b[i];
        f[a[i]] ^= 1;
        f[b[i]] ^= 1;
    }
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        cnt += f[i];
    }

    vi cur, ans;
    auto dfs2 = [&](auto self, int u, int fa, int aim)
    {
        cur.pb(u);
        if (u == aim)
        {
            ans = cur;
            return true;
        }
        for (int v : tree[u])
        {
            if (v == fa)
                continue;
            if (self(self, v, u, aim))
                return true;
        }
        cur.pop_back();
        return false;
    };
    if (cnt == 0)
    {
        YES;
        for (int i = 1; i <= q; i++)
        {
            cur.clear();
            dfs2(dfs2, a[i], 0, b[i]);
            cout << ans.size() << "\n";
            for (int x : ans)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        NO;
        cout << cnt / 2 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：