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

namespace SegmentTree
{
    const int N = 1e6 + 5;
    ll a[N];
    // 线段树节点结构
    struct TreeNode
    {
        ll l, r, sum; // l: 区间左端点, r: 区间右端点, sum: 区间最大值
    } tree[N << 2];   // 线段树数组，大小为 4*N

    // 清空节点信息
    inline void clear(ll p)
    {
        tree[p].l = tree[p].r = tree[p].sum = 0; // 重置节点
    }

    // 递归清空节点
    inline void clean(ll p)
    {
        if (tree[p].l == tree[p].r)
        {             // 如果是叶子节点
            clear(p); // 清空该节点
            return;
        }
        clear(p);          // 清空当前节点
        clean(p << 1);     // 清空左子树
        clean(p << 1 | 1); // 清空右子树
    }

    // 更新父节点的值为子节点的最大值
    inline void pushup(ll p)
    {
        tree[p].sum = max(tree[p << 1].sum, tree[p << 1 | 1].sum); // 更新当前节点的最大值
    }

    // 建立线段树
    void build(ll p, ll l, ll r, ll a[])
    {
        tree[p].l = l;
        tree[p].r = r; // 设置节点的区间
        if (l == r)
        {                       // 如果是叶子节点
            tree[p].sum = a[l]; // 叶子节点值为数组对应值
            return;
        }
        ll mid = (l + r) >> 1;            // 计算中间点
        build(p << 1, l, mid, a);         // 构建左子树
        build(p << 1 | 1, mid + 1, r, a); // 构建右子树
        pushup(p);                        // 更新当前节点的值
    }

    // 查询区间 [l, r] 的最大值
    ll query(ll p, ll l, ll r)
    {
        if (l <= tree[p].l && tree[p].r <= r)
            return tree[p].sum;                // 如果当前节点的区间完全在查询范围内
        ll mid = (tree[p].l + tree[p].r) >> 1; // 计算中间点
        ll ans = -infll;                       // 初始化答案为负无穷
        if (l <= mid)
            ans = max(ans, query(p << 1, l, r)); // 查询左子树
        if (r > mid)
            ans = max(ans, query(p << 1 | 1, l, r)); // 查询右子树
        return ans;                                  // 返回最大值
    }
}

using SegmentTree::a;
using SegmentTree::build;
using SegmentTree::clean;
using SegmentTree::query;
using SegmentTree::tree;
void solve()
{

    int q, m;
    cin >> q >> m;
    vl ans(m + 1);
    ll sum = 0;
    while (q--)
    {
        int n;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        clean(1);
        build(1, 1, n, a);
        sum += max(0ll, tree[1].sum);

        for (int i = 1; i <= min(n + 2, m); i++)
        {
            ll cur = -infll;
            int l = i + n - m, r = i;
            if (l < 1)
            {
                cur = 0;
                l = 1;
            }
            if (r > n)
            {
                cur = 0;
                r = n;
            }
            cur = max(cur, query(1, l, r));
            ans[i] += cur - max(0ll, tree[1].sum);
        }

        for (int i = m; i >= max(m - n - 1, n + 3); i--)
        {
            ll cur = -infll;
            int l = i - m + n, r = i;
            if (l < 1)
            {
                cur = 0;
                l = 1;
            }
            if (r > n)
            {
                cur = 0;
                r = n;
            }
            cur = max(cur, query(1, l, r));
            ans[i] += cur - max(0ll, tree[1].sum);
        }
    }

    for (ll i = 1; i <= m; i++)
    {
        cout << sum + ans[i] << " \n"[i == m];
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