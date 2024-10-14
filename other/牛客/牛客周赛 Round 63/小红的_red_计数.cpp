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

namespace SegTree
{
    const int N = 1e5 + 5;  // 定义常量N，表示数组的最大长度为100005。
#define ls rt << 1          // 定义宏ls，表示当前节点的左子节点编号。
#define rs rt << 1 | 1      // 定义宏rs，表示当前节点的右子节点编号。
#define lson ls, l, mid     // 定义宏lson，表示递归处理左子树的参数。
#define rson rs, mid + 1, r // 定义宏rson，表示递归处理右子树的参数。

    struct Info
    {
        ll r, e, d, re, ed, red, de, er, der;
        friend Info operator+(const Info a, const Info b)
        {
            Info c;
            c.r = a.r + b.r;
            c.e = a.e + b.e;
            c.d = a.d + b.d;
            c.re = a.re + b.re + a.r * b.e;
            c.ed = a.ed + b.ed + a.e * b.d;
            c.red = a.red + b.red + a.r * b.ed + a.re * b.d;
            c.de = a.de + b.de + a.d * b.e;
            c.er = a.er + b.er + a.e * b.r;
            c.der = a.der + b.der + a.de * b.r + a.d * b.er;
            return c;
        }
    } tr[N << 2]; // 线段树数组，大小为4倍的N，用于存储所有节点信息。

    Info a[N];
    // pushUp函数用于在递归构建或更新线段树时，向上更新当前节点的信息。
    void pushUp(int rt) { tr[rt] = tr[ls] + tr[rs]; }

    // build函数用于构建线段树。
    // 参数解释：
    // rt: 当前节点的编号。
    // l: 当前节点所表示区间的左端点。
    // r: 当前节点所表示区间的右端点。
    void build(int rt, int l, int r)
    {
        if (l == r) // 如果当前区间长度为1，即叶子节点。
        {
            tr[rt] = a[l];
            return;
        }
        int mid = l + r >> 1; // 计算当前区间的中点。
        build(lson);          // 递归构建左子树。
        build(rson);          // 递归构建右子树。
        pushUp(rt);           // 向上更新当前节点的信息。
    }

    // query函数用于查询线段树在[L, R]区间上的信息。
    // 参数解释：
    // rt: 当前节点的编号。
    // l: 当前节点所表示区间的左端点。
    // r: 当前节点所表示区间的右端点。
    // L: 查询区间的左端点。
    // R: 查询区间的右端点。
    Info query(int rt, int l, int r, int L, int R)
    {
        if (l >= L && r <= R) // 如果当前节点的区间完全被查询区间覆盖，直接返回当前节点信息。
            return tr[rt];
        Info temp;
        if (l >= R || r <= L) // 如果当前节点的区间与查询区间不相交，返回一个默认的信息。
            return temp;
        int mid = l + r >> 1; // 计算当前区间的中点。
        if (mid >= R)         // 如果查询区间完全位于左子树，递归查询左子树。
            return query(lson, L, R);
        if (mid < L) // 如果查询区间完全位于右子树，递归查询右子树。
            return query(rson, L, R);
        // 如果查询区间跨越左右子树，分别查询左右子树的信息并合并。
        return query(lson, L, R) + query(rson, L, R);
    }
}

// 引入SegTree命名空间中的build和query函数，方便直接调用。
using SegTree::build;
using SegTree::query;
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        SegTree::a[i].r = s[i - 1] == 'r';
        SegTree::a[i].e = s[i - 1] == 'e';
        SegTree::a[i].d = s[i - 1] == 'd';
    }
    build(1, 1, n);
    SegTree::Info t = query(1, 1, n, 1, n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        SegTree::Info t1 = query(1, 1, n, 1, l - 1);
        SegTree::Info t2 = query(1, 1, n, l, r);
        SegTree::Info t3 = query(1, 1, n, r + 1, n);
        ll ans = t.red - t2.re * t3.d - t1.r * t2.ed - t2.red + t2.der + t1.r * t2.de + t2.er * t3.d;

        cout << ans << '\n';
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