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
#include <array>
#include <tuple>

#define endl '\n'

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

#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffffLL

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

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;

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
typedef priority_queue<pll> pqpl;
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

vs mp;
vvi vis;
vector<vector<array<int, 4>>> ans, visd;
vector<tuple<int, int, int>> buf;

int n, m, q, tms, cnt;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int c0[] = {1, 0, 2, 3}; // -
const int c1[] = {0, 1, 3, 2}; // |
const int c2[] = {3, 2, 1, 0}; // /
const int c3[] = {2, 3, 0, 1}; // \'

int conv(int d, char c)
{
    switch (c)
    {
    case '-':
        return c0[d];
    case '|':
        return c1[d];
    case '/':
        return c2[d];
    case '\\':
        return c3[d];
    }
    return -1;
}
void dfs_line(int x, int y, int dir)
{
    buf.push_back({x, y, dir});
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    int nd = conv(dir, mp[x][y]);
    dfs_line(x + dx[nd], y + dy[nd], nd);
}
void f_line(int sx, int sy, int sd)
{
    buf.clear();
    dfs_line(sx, sy, sd);
    reverse(buf.begin(), buf.end());
    int res = 0;
    tms++;
    for (int i = 0; i < buf.size() - 1; i++)
    {
        auto [x, y, d] = buf[i];
        if (i)
        {
            int fl = 1;
            if (mp[x][y] == '-' && (d & 2) || mp[x][y] == '|' && !(d & 2))
                fl = 0;
            if (fl)
            {
                if (vis[x][y] != tms)
                    res += fl;
                vis[x][y] = tms;
            }
        }
        visd[x + dx[d ^ 1]][y + dy[d ^ 1]][d] = tms;
        ans[x + dx[d ^ 1]][y + dy[d ^ 1]][d] = res;
    }
}

void dfs_loop(int x, int y, int dir)
{
    visd[x][y][dir] = tms;
    x += dx[dir];
    y += dy[dir];
    int nd = conv(dir, mp[x][y]);
    if (nd != dir)
    {
        if (vis[x][y] != tms)
            cnt++;
        vis[x][y] = tms;
    }
    if (visd[x][y][nd] != tms)
        dfs_loop(x, y, nd);
}
void mk_loop(int x, int y, int dir)
{
    ans[x][y][dir] = cnt;
    visd[x][y][dir] = tms;
    x += dx[dir];
    y += dy[dir];
    int nd = conv(dir, mp[x][y]);
    if (visd[x][y][nd] != tms)
        mk_loop(x, y, nd);
}
void f_loop(int sx, int sy, int sd)
{
    cnt = 0;
    tms++;
    dfs_loop(sx, sy, sd);
    tms++;
    mk_loop(sx, sy, sd);
}

void solve()
{
    cin >> n >> m;
    mp.clear();
    mp.resize(n);
    for (auto &s : mp)
        cin >> s;
    ans.resize(n, vector<array<int, 4>>(m, {0, 0, 0, 0}));
    visd.resize(n, vector<array<int, 4>>(m, {0, 0, 0, 0}));
    vis.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        f_line(i, 0, 2);
        f_line(i, m - 1, 3);
    }
    for (int i = 0; i < m; i++)
    {
        f_line(0, i, 0);
        f_line(n - 1, i, 1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                if (visd[i][j][d] == 0)
                    f_loop(i, j, d);
            }
        }
    }
    cin >> q;
    int x, y, d;
    string opt;
    while (q--)
    {
        cin >> x >> y >> opt;
        x--, y--;
        if (opt == "below")
            d = 0;
        if (opt == "above")
            d = 1;
        if (opt == "right")
            d = 2;
        if (opt == "left")
            d = 3;
        cout << ans[x][y][d] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
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