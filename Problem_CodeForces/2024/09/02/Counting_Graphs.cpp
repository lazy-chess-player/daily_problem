#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define sort1_all(x) sort(x.begin() + 1, x.end())

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

struct edge
{
    int u, v;
    ll w;
    edge(int _u = 0, int _v = 0, ll _w = 0) : u(_u), v(_v), w(_w) {};
    bool operator<(const edge &rhs) const
    {
        return w < rhs.w;
    }
    bool operator>(const edge &rhs) const
    {
        return w > rhs.w;
    }
};

const ll mod = 998244353;

ll qmi(ll x, ll k, ll p = mod)
{
    x %= p;
    // k %= p;
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res % p;
}
int n;

// const int N = 2e5 + 5;

// // p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量
// int p[N];
// ll sz[N];

// // 返回x的祖宗节点
// int find(int x)
// {
//     // 压缩路径，将路径上所有节点赋值为集合编号
//     if (p[x] != x)
//         p[x] = find(p[x]);
//     return p[x];
// }

// // 初始化，假定节点编号是1~n
// void init()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         p[i] = i;
//         sz[i] = 1;
//     }
// }

// // 合并a和b所在的两个集合：
// void merge(int a, int b)
// {
//     int pa = find(a), pb = find(b);
//     if (pa == pb)
//         return;
//     if (sz[pa] > sz[pb])
//         swap(pa, pb);
//     sz[pb] += sz[pa];
//     p[pa] = pb;
// }

void solve()
{
    ll S;
    cin >> n >> S;
    // init();
    vector<edge> e(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(all(e));
    vi p(n + 1);
    vl sz(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    auto find = [&](auto &self, int x) -> int
    {
        return p[x] == x ? x : p[x] = self(self, p[x]);
    };

    auto merge = [&](int a, int b) -> void
    {
        int pa = find(find, a), pb = find(find, b);
        if (pa != pb)
        {
            if (sz[pa] > sz[pb])
                swap(pa, pb);
            sz[pb] += sz[pa];
            p[pa] = pb;
        }
    };
    ll ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        int pu = find(find, u);
        int pv = find(find, v);
        ans = (ans * qmi(S - e[i].w + 1, sz[pu] * sz[pv] - 1)) % mod;
        merge(pu, pv);
    }
    cout << ans % mod << endl;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：