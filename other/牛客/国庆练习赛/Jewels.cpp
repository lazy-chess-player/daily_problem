#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <array>
#include <bitset>
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
#define reverse_all(x) reverse(all(x))
#define reverse1_all(x) reverse(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

// 红色
#define DEBUG1(x)                     \
    RED;                              \
    cout << #x << " : " << x << endl; \
    RESET;

// 绿色
#define DEBUG2(x)                     \
    GREEN;                            \
    cout << #x << " : " << x << endl; \
    RESET;

// 蓝色
#define DEBUG3(x)                     \
    BLUE;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 品红
#define DEBUG4(x)                     \
    MAGENTA;                          \
    cout << #x << " : " << x << endl; \
    RESET;

// 青色
#define DEBUG5(x)                     \
    CYAN;                             \
    cout << #x << " : " << x << endl; \
    RESET;

// 黄色
#define DEBUG6(x)                     \
    YELLOW;                           \
    cout << #x << " : " << x << endl; \
    RESET;

using namespace std;

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
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpll;
typedef priority_queue<psi> pqpsl;

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

void solve()
{
    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> jewels(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> get<0>(jewels[i]) >> get<1>(jewels[i]) >> get<2>(jewels[i]) >> get<3>(jewels[i]);
    }

    vector<vector<ll>> C(n, vector<ll>(n, 0));
    ll max_cost = 0;
    for (int i = 0; i < n; ++i)
    {
        int xi, yi, zi, vi;
        tie(xi, yi, zi, vi) = jewels[i];
        for (int t = 0; t < n; ++t)
        {
            ll distance_sq = (ll)xi * xi + (ll)yi * yi + (ll)(zi + t * vi) * (zi + t * vi);
            C[i][t] = distance_sq;
            if (distance_sq > max_cost)
            {
                max_cost = distance_sq;
            }
        }
    }

    vector<vector<ll>> cost(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cost[i][j] = max_cost - C[i - 1][j - 1];
        }
    }
    vector<ll> lx(n + 1, 0);
    vector<ll> ly(n + 1, 0);
    vector<ll> match_to(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        lx[i] = *max_element(cost[i].begin() + 1, cost[i].end());
    }

    for (int i = 1; i <= n; ++i)
    {
        vector<ll> slack(n + 1, infll);
        vector<ll> prev(n + 1, 0);
        vector<bool> S(n + 1, false);
        vector<bool> T_flag(n + 1, false);
        int j0 = 0;
        match_to[0] = i;

        int x = i;
        int y = 0;
        vector<ll> minv(n + 1, infll);
        vector<int> way(n + 1, 0);
        int marked_i = i;
        int marked_j = 0;
        int j1 = 0;
        vector<bool> used(n + 1, false);

        do
        {
            used[y] = true;
            x = match_to[y];
            ll delta = infll;
            int y1 = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (!used[j])
                {
                    ll cur = lx[x] + ly[j] - cost[x][j];
                    if (cur < minv[j])
                    {
                        minv[j] = cur;
                        way[j] = y;
                    }
                    if (minv[j] < delta)
                    {
                        delta = minv[j];
                        y1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j)
            {
                if (used[j])
                {
                    lx[match_to[j]] -= delta;
                    ly[j] += delta;
                }
                else
                {
                    minv[j] -= delta;
                }
            }
            y = y1;
        } while (match_to[y] != 0);

        do
        {
            int j1 = way[y];
            match_to[y] = match_to[j1];
            y = j1;
        } while (y != 0);
    }

    ll total_cost = 0;
    for (int j = 1; j <= n; ++j)
    {
        if (match_to[j] != 0)
        {
            int i = match_to[j] - 1;
            int t = j - 1;
            total_cost += C[i][t];
        }
    }

    cout << total_cost;
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