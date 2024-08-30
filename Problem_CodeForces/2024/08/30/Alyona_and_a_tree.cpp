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
const int N = 2e5 + 5;

struct Que
{
    ll d1;
    int d2, id;
    Que(ll d1 = 0, int d2 = 0, int id = 0) : d1(d1), d2(d2), id(id) {}

} Q[N * 3], tmp[N * 3];

int head[N], to[N << 1], nex[N << 1], idx;
int n, m, dfn[N], siz[N], cnt, DFN;
ll dep[N], Ans[N], a[N], val[N << 1];
void dfs(int x, int f)
{
    siz[x] = 1;
    dfn[x] = ++DFN;
    for (int i = head[x]; i; i = nex[i])
    {
        int y = to[i];
        if (y == f)
            continue;
        dep[y] = dep[x] + val[i];
        dfs(y, x);
        siz[x] += siz[y];
    }
    Q[++cnt] = Que(dep[x] - a[x], dfn[x], 0);
    Q[++cnt] = Que(dep[x], dfn[x], -x);
    Q[++cnt] = Que(dep[x], dfn[x] + siz[x] - 1, x);
    return;
}

void add(int u, int v, ll w)
{
    nex[++idx] = head[u];
    to[idx] = v;
    head[u] = idx;
    val[idx] = w;
}
bool cmp1(const Que &x, const Que &y)
{
    if (x.d1 ^ y.d1)
        return x.d1 < y.d1;
    if (x.d2 ^ y.d2)
        return x.d2 < y.d2;
    return x.id < y.id;
}
void CDQ_Divide(int l, int r)
{
    if (l == r)
        return;
    int mid = l + r >> 1, posl = l, posr = mid + 1, pos = l, tot = 0;
    CDQ_Divide(l, mid), CDQ_Divide(mid + 1, r);
    while (posl <= mid && posr <= r)
    {
        if (Q[posl].d2 <= Q[posr].d2)
        {
            if (Q[posl].id == 0)
                tot++;
            tmp[pos++] = Q[posl++];
        }
        else
        {
            if (Q[posr].id < 0)
                Ans[-Q[posr].id] -= tot;
            else if (Q[posr].id > 0)
                Ans[Q[posr].id] += tot;
            tmp[pos++] = Q[posr++];
        }
    }
    while (posl <= mid)
        tmp[pos++] = Q[posl++];
    while (posr <= r)
    {
        if (Q[posr].id < 0)
            Ans[-Q[posr].id] -= tot;
        else if (Q[posr].id > 0)
            Ans[Q[posr].id] += tot;
        tmp[pos++] = Q[posr++];
    }
    for (int i = l; i <= r; i++)
        Q[i] = tmp[i];
    return;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int x, v;
        cin >> x >> v;
        add(i, x, v);
        add(x, i, v);
    }
    dfs(1, 0);
    sort(Q + 1, Q + cnt + 1, cmp1);
    CDQ_Divide(1, cnt);
    for (int i = 1; i <= n; i++)
    {
        cout << Ans[i] << " \n"[i == n];
    };
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