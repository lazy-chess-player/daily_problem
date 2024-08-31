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

void solve()
{
    int n;
    ll ans = 0;
    cin >> n;

    // 定义用于存储输入数据的向量a，大小为n+2，其中a[0]和a[n+1]用于边界条件
    vector<int> a(n + 2, 0);

    // 定义用于存储计算结果的向量
    vector<int> minL(n + 1), minR(n + 1), maxL(n + 1), maxR(n + 1);

    // 定义用于模拟栈的向量
    vector<int> stk;

    // 读取输入数据
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 计算每个元素左侧最小值的下标
    stk.push_back(0); // 初始化栈，sta[0]表示边界条件
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[stk.back()])
        {
            // 如果当前元素大于栈顶元素，则直接将其下标入栈
            stk.push_back(i);
            minL[i] = i - 1; // 当前元素左侧最小值就是其左边的元素
        }
        else
        {
            // 否则，持续弹栈直到找到一个比当前元素小的元素
            while (!stk.empty() && a[i] < a[stk.back()])
            {
                stk.pop_back();
            }
            minL[i] = stk.back(); // 当前元素左侧最小值为栈顶元素
            stk.push_back(i);     // 将当前元素下标入栈
        }
    }

    // 计算每个元素右侧最小值的下标
    stk.clear();
    stk.push_back(n + 1); // 初始化栈，sta[0]表示边界条件
    for (int i = n; i >= 1; i--)
    {
        if (a[i] > a[stk.back()])
        {
            // 如果当前元素大于栈顶元素，则直接将其下标入栈
            stk.push_back(i);
            minR[i] = i + 1; // 当前元素右侧最小值就是其右边的元素
        }
        else
        {
            // 否则，持续弹栈直到找到一个比当前元素小的元素
            while (!stk.empty() && a[i] <= a[stk.back()])
            {
                stk.pop_back();
            }
            minR[i] = stk.back(); // 当前元素右侧最小值为栈顶元素
            stk.push_back(i);     // 将当前元素下标入栈
        }
    }

    // 设置边界条件
    a[0] = a[n + 1] = 0x7fffffff; // 设置a[0]和a[n+1]为极大值，方便处理边界情况
    stk.clear();
    stk.push_back(0); // 初始化栈，sta[0]表示边界条件

    // 计算每个元素左侧最大值的下标
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[stk.back()])
        {
            // 如果当前元素小于栈顶元素，则直接将其下标入栈
            stk.push_back(i);
            maxL[i] = i - 1; // 当前元素左侧最大值就是其左边的元素
        }
        else
        {
            // 否则，持续弹栈直到找到一个比当前元素大的元素
            while (!stk.empty() && a[i] > a[stk.back()])
            {
                stk.pop_back();
            }
            maxL[i] = stk.back(); // 当前元素左侧最大值为栈顶元素
            stk.push_back(i);     // 将当前元素下标入栈
        }
    }

    // 计算每个元素右侧最大值的下标
    stk.clear();
    stk.push_back(n + 1); // 初始化栈，sta[0]表示边界条件
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < a[stk.back()])
        {
            // 如果当前元素小于栈顶元素，则直接将其下标入栈
            stk.push_back(i);
            maxR[i] = i + 1; // 当前元素右侧最大值就是其右边的元素
        }
        else
        {
            // 否则，持续弹栈直到找到一个比当前元素大的元素
            while (!stk.empty() && a[i] >= a[stk.back()])
            {
                stk.pop_back();
            }
            maxR[i] = stk.back(); // 当前元素右侧最大值为栈顶元素
            stk.push_back(i);     // 将当前元素下标入栈
        }
    }

    // 计算最终的答案
    for (int i = 1; i <= n; i++)
    {
        ans += 1LL * a[i] * (1LL * (i - maxL[i]) * (maxR[i] - i) - 1LL * (i - minL[i]) * (minR[i] - i));
    }

    // 输出结果
    cout << ans;
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