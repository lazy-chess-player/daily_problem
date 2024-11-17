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

const int mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;

    vl l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }

    auto myFloor = [](int x, int y)
    {
        return x / y + (x % y != 0);
    };
    vl dp(m + 1), last(m + 1), sum(m + 1), pre(m + 1);

    for (int d = m; d >= 1; d--)
    {
        for (int j = 0; j <= m / d; j++)
        {
            dp[j] = 0;
            last[j] = 0;
            pre[j] = 0;
        }
        last[0] = pre[0] = 1;

        for (int j = 1; j <= m / d; j++)
        {
            pre[j] = (pre[j - 1] + last[j]) % mod;
        }

        for (int j = 1; j <= n; j++)
        {
            for (int L = m / d; L >= myFloor(l[j], d); L--)
            {
                if (L - r[j] / d > 0)
                {
                    dp[L] = (pre[L - myFloor(l[j], d)] - pre[L - r[j] / d - 1] + mod) % mod;
                }
                else
                {
                    dp[L] = pre[L - myFloor(l[j], d)];
                }
            }
            for (int j = 0; j <= m / d; j++)
            {
                last[j] = dp[j];
                dp[j] = 0;
            }

            pre[0] = last[0];
            for (int j = 1; j <= m / d; j++)
            {
                pre[j] = (pre[j - 1] + last[j]) % mod;
            }
        }

        for (int j = 0; j <= m / d; j++)
        {
            sum[d] = (sum[d] + last[j]) % mod;
        }

        for (int j = d + d; j <= m; j += d)
        {
            sum[d] = (sum[d] - sum[j] + mod) % mod;
        }
    }

    cout << sum[1] << endl;
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