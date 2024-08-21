#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <tuple>

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

#include <cstdio>

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

const int N = 2e5 + 5;

const int LGN = 21;

ll maxPre[N][LGN];
ll maxSuf[N][LGN];
int logn[N];
int n;

// 预处理log值，防止查询时影响速度
void getLog()
{
    logn[1] = 0, logn[2] = 1;
    for (int i = 3; i <= n; i++)
        logn[i] = logn[i / 2] + 1;
}

void buildPre()
{
    // 2的21次方满足两百万数据，若数据变大，这里上限也要变大
    for (int j = 1; j <= LGN; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            // 倍增的处理
            maxPre[i][j] = max(maxPre[i][j - 1], maxPre[i + (1 << (j - 1))][j - 1]);
        }
    }
}
void buildSuf()
{
    // 2的21次方满足两百万数据，若数据变大，这里上限也要变大
    for (int j = 1; j <= LGN; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            // 倍增的处理
            maxSuf[i][j] = max(maxSuf[i][j - 1], maxSuf[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll queryPre(int l, int r)
{
    int lg = logn[r - l + 1];
    ll res = max(maxPre[l][lg], maxPre[r - (1 << lg) + 1][lg]);
    return res;
}
ll querySuf(int l, int r)
{
    int lg = logn[r - l + 1];
    ll res = max(maxSuf[l][lg], maxSuf[r - (1 << lg) + 1][lg]);
    return res;
}

void init()
{
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j < LGN; j++)
        {
            maxPre[i][j] = 0;
            maxSuf[i][j] = 0;
        }
    }
}

void solve()
{
    cin >> n;
    vl a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxPre[i][0] = maxPre[i - 1][0] + a[i];
    }
    buildPre();
    for (int i = n; i >= 1; i--)
    {
        maxSuf[i][0] = maxSuf[i + 1][0] + a[i];
    }
    buildSuf();

    vi lc(n + 1, -1), rc(n + 1, -1);
    vi stk;
    for (int i = 1; i <= n; i++)
    {
        while (!stk.empty() && a[i] > a[stk.back()])
        {
            int x = stk.back();
            rc[x] = lc[i];
            lc[i] = x;
            stk.pop_back();
        }
        stk.pb(i);
    }
    while (stk.size() > 1)
    {
        int x = stk.back();
        stk.pop_back();
        rc[stk.back()] = x;
    }

    for (int i = 1; i <= n; i++)
    {
        int l = lc[i];
        int r = rc[i];
        ll left;
        ll right;
        if (r != -1)
            left = queryPre(i, r) - maxPre[i - 1][0];
        else
            left = a[i];
        if (l != -1)
            right = querySuf(l, i) - maxSuf[i + 1][0];
        else
            right = a[i];
        if (left + right > 2 * a[i])
        {
            NO;
            return;
        }
    }
    YES;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int _ = 1;
    std::cin >> _;
    getLog();
    while (_--)
    {
        solve();
    }
    return 0;
}

/*######################################END######################################*/
// 链接：