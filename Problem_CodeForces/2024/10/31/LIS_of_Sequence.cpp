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

const int N = 1e5 + 5;
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct Fenwick
{
    int n;       // 数组大小
    vector<T> a; // 存储树状数组的数组

    // 构造函数，初始化树状数组
    Fenwick(int n_ = 0)
    {
        init(n_);
    }

    // 初始化树状数组
    void init(int n_)
    {
        n = n_;               // 设置大小
        a.assign(n + 1, T{}); // 初始化数组，所有元素为0
    }
    T calc(const T &a, const T &b)
    {
        return max(a, b);
    }

    // 在索引 x 上添加值 v
    void add(int x, const T &v)
    {
        for (int i = x; i <= n; i += i & -i)
        {                         // 从 x 开始更新
            a[i] = calc(a[i], v); // 更新当前节点
        }
    }

    T query(int x)
    {
        T ans{}; // 初始化结果为 0
        for (int i = x; i > 0; i -= i & -i)
        {                          // 从 x 向上遍历
            ans = calc(ans, a[i]); // 累加当前节点的值
        }
        return ans; // 返回前缀和
    }
};

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi f(n);
    Fenwick<int> tr(N);
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = tr.query(a[i] - 1) + 1;
        tr.add(a[i], f[i]);
        mx = max(mx, f[i]);
    }
    vi g(n);
    tr.init(N);
    for (int i = n - 1; i >= 0; i--)
    {
        g[i] = tr.query(N - a[i] - 1) + 1;
        tr.add(N - a[i], g[i]);
    }
    string ans(n, '#');
    map<pii, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (f[i] + g[i] - 1 < mx)
            ans[i] = '1';
        else
            mp[pii(f[i], g[i])]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (f[i] + g[i] - 1 < mx)
            continue;
        else if (mp[pii(f[i], g[i])] > 1)
            ans[i] = '2';
        else
            ans[i] = '3';
    }
    cout << ans << "\n";
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