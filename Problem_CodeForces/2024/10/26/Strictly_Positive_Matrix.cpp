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
// 强连通分量类
struct SCC
{
    int n;                     // 图的节点数
    vector<vector<int>> adj;   // 邻接表表示的图
    vector<int> stk;           // 存储DFS路径的栈
    vector<int> dfn, low, bel; // dfn：节点的访问时间，low：节点的最小可达时间，bel：每个节点所属强连通分量的编号
    int cur, cnt;              // cur：当前时间戳，cnt：强连通分量的数量

    // 默认构造函数
    SCC() {}

    // 带参数的构造函数，初始化图的节点数
    SCC(int n)
    {
        init(n);
    }

    // 初始化函数
    void init(int n)
    {
        this->n = n;       // 设置节点数
        adj.assign(n, {}); // 初始化邻接表
        dfn.assign(n, -1); // 初始化访问时间为-1，表示未访问
        low.resize(n);     // 初始化low数组
        bel.assign(n, -1); // 初始化bel数组，表示每个节点的强连通分量编号
        stk.clear();       // 清空栈
        cur = cnt = 0;     // 当前时间戳和强连通分量计数器初始化为0
    }

    // 添加边的函数
    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // 在邻接表中添加边 u -> v
    }

    // 深度优先搜索函数
    void dfs(int x)
    {
        dfn[x] = low[x] = cur++; // 记录访问时间和low值
        stk.push_back(x);        // 将当前节点压入栈中

        // 遍历当前节点的所有邻接节点
        for (auto y : adj[x])
        {
            if (dfn[y] == -1)
            {                                 // 如果邻接节点y未被访问
                dfs(y);                       // 递归访问邻接节点y
                low[x] = min(low[x], low[y]); // 更新当前节点x的low值
            }
            else if (bel[y] == -1)
            {                                 // 如果邻接节点y已被访问，但不在当前强连通分量中
                low[x] = min(low[x], dfn[y]); // 更新low值
            }
        }

        // 如果当前节点x是一个强连通分量的根节点
        if (dfn[x] == low[x])
        {
            int y; // 用于存储从栈中弹出的节点
            do
            {
                y = stk.back(); // 获取栈顶元素
                bel[y] = cnt;   // 将该节点标记为当前强连通分量
                stk.pop_back(); // 从栈中弹出该节点
            } while (y != x); // 直到弹出当前节点x
            cnt++; // 增加强连通分量的计数
        }
    }

    // 主函数，执行SCC算法
    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {           // 如果节点i未被访问
                dfs(i); // 进行深度优先搜索
            }
        }
        return bel; // 返回每个节点的强连通分量编号
    }
};
void solve()
{
    int n;
    cin >> n;
    SCC scc(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (i == j)
                continue;
            if (x)
            {
                scc.addEdge(i, j);
            }
        }
    }
    scc.work();
    if (scc.cnt == 1)
        YES;
    else
        NO;
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