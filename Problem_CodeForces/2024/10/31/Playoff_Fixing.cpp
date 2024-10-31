#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

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
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

template <typename T>
void Debug(T x, int color = 1)
{
    switch (color)
    {
    case 1:
        RED;
        break;
    case 2:
        YELLOW;
        break;
    case 3:
        BLUE;
        break;
    case 4:
        MAGENTA;
        break;
    case 5:
        CYAN;
        break;
    default:
        break;
    }
    cout << x;
    RESET;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef pair<ll, int> pli;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pli> vpli;
typedef vector<pss> vpss;
typedef vector<ti3> vti3;
typedef vector<tl3> vtl3;
typedef vector<tld3> vtld3;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<ll, ll> mll;
typedef map<ll, bool> mlb;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<char, bool> mcb;
typedef map<string, int> msi;
typedef map<string, ll> msl;
typedef map<int, bool> mib;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 6e5 + 5;

const ll mod = 998244353;

ll fact[N], infact[N];

ll qmi(ll a, ll k, ll p = mod) // 快速幂模板
{
    ll res = 1;
    a %= p;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}

// 预处理阶乘的余数和阶乘逆元的余数
void getFact()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}

ll A(int a, int b)
{
    return (ll)fact[a] * infact[a - b] % mod;
}
ll C(int a, int b)
{
    if (a < b)
        return 0;
    return (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve()
{
    int k;
    cin >> k;
    int n = 1 << k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 1;
    auto calc = [&](int n) -> ll
    {
        if (n == 1)
            return 1;
        int num1 = n / 2;
        for (int i = 0; i < n; i++)
        {
            num1 -= (a[i] > n / 2);
        }
        int num2 = 0;
        for (int i = 0; i < n / 2; i++)
        {
            int p = 2 * i;
            int q = 2 * i + 1;
            if (a[p] != -1 && a[q] != -1)
            {
                if ((a[p] <= n / 2) == (a[q] <= n / 2))
                    return 0;
            }
            if (a[p] == -1 && a[q] == -1)
                num2++;
            if (a[p] != -1 && a[p] <= n / 2)
                a[i] = a[p];
            else if (a[q] != -1 && a[q] <= n / 2)
                a[i] = a[q];
            else
                a[i] = -1;
        }
        return qmi(2, num2) * A(num1, num1) % mod;
    };
    while (n)
    {
        ans = ans * calc(n) % mod;
        n >>= 1;
        if (ans == 0)
            break;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    // std::cin >> _;
    getFact();
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：