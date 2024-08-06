#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
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
#include <random>

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
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pii> vpll;
typedef vector<pss> vpss;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pii> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pii> pqpl;
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
inline void read(T &x)
{
    T f = 1;
    x = 0;
    char ch = getchar();
    while (0 == isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (0 != isdigit(ch))
        x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
inline void write(T x)
{
    if (x < 0)
    {
        x = ~(x - 1);
        putchar('-');
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

/*#####################################BEGIN#####################################*/

const int N = 2e5 + 5;
int n;

ll a[N];
ll b[N];

#define ls p * 2
#define rs p * 2 + 1
#define mid (l + r) >> 1

struct node
{
    int left, right;
    ll val;  // 区间和值
} st[4 * N]; // 一定要4*N

// 向上更新值
void pushup(int p)
{
    st[p].val = max(st[ls].val, st[rs].val);
}

// 构建线段树,p为当前节点编号,l,r为当前节点的区间范围
void build(int p, int l, int r)
{
    st[p].left = l;
    st[p].right = r;
    if (l == r)
    {
        st[p].val = b[l];
        return;
    }
    int m = mid;
    build(ls, l, m);
    build(rs, m + 1, r);
    pushup(p);
}

// p为当前节点编号,Left,Right为待查询区间边界
ll query(int p, int Left, int Right)
{
    int l = st[p].left;
    int r = st[p].right;
    if (r < Left || Right < l)
        return 0;
    if (Left <= l && r <= Right)
        return st[p].val;
    int m = mid;
    ll res = 0;
    if (Left <= m)
        res = max(res, query(ls, Left, Right));
    if (Right > m)
        res = max(res, query(rs, Left, Right));
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int m;
    cin >> m;
    int temp;
    mii sum;
    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        sum[temp]++;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < b[i])
            flag = true;
    }
    if (flag)
    {
        NO;
        return;
    }
    build(1, 1, n);
    mii mp;
    mii cnt;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == b[i])
            continue;
        if (!mp[b[i]])
            mp[b[i]] = i;
        else
        {
            int l = mp[b[i]];
            int x = query(1, l, i);
            if (x > b[i])
                cnt[b[i]]++;
            mp[b[i]] = i;
        }
    }
    for (auto v : mp)
    {
        if (v.sd)
            cnt[v.ft]++;
    }
    for (auto v : cnt)
    {
        if (sum[v.ft] < v.sd)
        {
            NO;
            return;
        }
    }
    YES;
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
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