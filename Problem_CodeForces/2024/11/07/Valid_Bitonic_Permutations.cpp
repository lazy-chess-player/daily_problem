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

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const ll mod = 1e9 + 7;

ll qmi(ll x, ll k, ll p = mod)
{
    x %= p;
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}
void solve()
{
    ll n, i, j, x, y;
    cin >> n >> i >> j >> x >> y;
    vvl dp(n + 1, vl(n + 1));
    dp[0][n] = 1;
    for (int l = 0; l <= n; l++)
    {
        for (int r = n; r > l; r--)
        {
            int v = l + (n - r);
            if ((l + 1 != i || v == x - 1) && (l + 1 != j || v == y - 1))
                dp[l + 1][r] = (dp[l + 1][r] + dp[l][r]) % mod;
            if ((r != i || v == x - 1) && (r != j || v == y - 1))
                dp[l][r - 1] = (dp[l][r - 1] + dp[l][r]) % mod;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = (ans + dp[i][i]) % mod;
    }
    ans = (ans * qmi(2, mod - 2));
    ans = (ans - int(i == x && j == y) - int(i == n - x + 1 && j == n - y + 1) + mod) % mod;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：