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

namespace O1Trie
{
    const int N = 1e6 + 5;          // 最大节点数
    int tr[N << 5][2], cnt[N << 5]; // tr 是 Trie 树，cnt 记录每个节点经过的次数
    int tot;                        // 节点总数，记录当前 Trie 树已使用的节点数
    void init()
    {
        memset(tr, 0, sizeof(tr));   // 清空 Trie 树
        memset(cnt, 0, sizeof(cnt)); // 清空计数数组
        tot = 0;                     // 重置节点总数
    }
    // 插入一个数到 Trie 树中
    void insert(int x)
    {
        int pos = 0; // 从根节点开始
        for (int i = 30; i >= 0; i--)
        {                           // 遍历整数的二进制位，从高位到低位
            int c = (x >> i) & 1;   // 提取第 i 位的值（0 或 1）
            if (!tr[pos][c])        // 如果当前位对应的子节点不存在，创建新节点
                tr[pos][c] = ++tot; // 新增一个节点
            pos = tr[pos][c];       // 移动到下一个节点
            cnt[pos]++;             // 当前节点被经过，计数加一
        }
    }

    // 查询满足条件的数对
    ll query(int x, int k)
    {
        ll res = 0;  // 结果变量
        int pos = 0; // 从根节点开始
        for (int i = 30; i >= 0; i--)
        {                          // 同样遍历整数的每一位，从高位到低位
            int c = (x >> i) & 1;  // 提取 x 的第 i 位
            int ck = (k >> i) & 1; // 提取 k 的第 i 位
            if (ck)                // 如果 k 的第 i 位为 1，意味着我们可以从不相同的分支中选择
                pos = tr[pos][!c]; // 选择与 x 的当前位相反的分支
            else
            {                            // 如果 k 的第 i 位为 0，则只能选择与 x 当前位相同的分支
                res += cnt[tr[pos][!c]]; // 统计符合条件的数目
                pos = tr[pos][c];        // 选择相同分支
            }
            if (!pos) // 如果 Trie 树中没有对应的节点，则提前终止
                break;
        }
        return res + cnt[pos]; // 返回结果，加上当前路径上剩余的有效节点计数
    }
}
using O1Trie::init;
using O1Trie::insert;
using O1Trie::query;
void solve()
{
    int n, k;
    cin >> n >> k;
    insert(0);
    ll ans = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        sum ^= x;
        ans += query(sum, k);
        insert(sum);
    }
    cout << ans << endl;
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