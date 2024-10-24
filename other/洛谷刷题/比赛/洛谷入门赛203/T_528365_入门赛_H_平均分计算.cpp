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

// 分数类
template <class T>
struct Frac
{
    T num; // 分子
    T den; // 分母

    // 构造函数，初始化分子和分母
    Frac(T num_, T den_) : num(num_), den(den_)
    {
        // 如果分母为负，调整分子和分母的符号
        if (den < 0)
        {
            den = -den;
            num = -num;
        }
    }

    // 默认构造函数，初始化为 0/1
    Frac() : Frac(0, 1) {}

    // 只传入分子，分母默认为 1
    Frac(T num_) : Frac(num_, 1) {}

    // 将分数转换为 double 类型
    explicit operator double() const
    {
        return 1. * num / den; // 注意使用浮点数运算
    }

    // 加法赋值
    Frac &operator+=(const Frac &rhs)
    {
        num = num * rhs.den + rhs.num * den; // 计算新分子
        den *= rhs.den;                      // 计算新分母
        return *this;                        // 返回当前对象
    }

    // 减法赋值
    Frac &operator-=(const Frac &rhs)
    {
        num = num * rhs.den - rhs.num * den; // 计算新分子
        den *= rhs.den;                      // 计算新分母
        return *this;                        // 返回当前对象
    }

    // 乘法赋值
    Frac &operator*=(const Frac &rhs)
    {
        num *= rhs.num; // 计算新分子
        den *= rhs.den; // 计算新分母
        return *this;   // 返回当前对象
    }

    // 除法赋值
    Frac &operator/=(const Frac &rhs)
    {
        num *= rhs.den; // 计算新分子
        den *= rhs.num; // 计算新分母
        if (den < 0)
        { // 如果分母为负，调整符号
            num = -num;
            den = -den;
        }
        return *this; // 返回当前对象
    }

    // 加法运算符
    friend Frac operator+(Frac lhs, const Frac &rhs)
    {
        return lhs += rhs; // 使用 += 实现
    }

    // 减法运算符
    friend Frac operator-(Frac lhs, const Frac &rhs)
    {
        return lhs -= rhs; // 使用 -= 实现
    }

    // 乘法运算符
    friend Frac operator*(Frac lhs, const Frac &rhs)
    {
        return lhs *= rhs; // 使用 *= 实现
    }

    // 除法运算符
    friend Frac operator/(Frac lhs, const Frac &rhs)
    {
        return lhs /= rhs; // 使用 /= 实现
    }

    // 一元负运算符
    friend Frac operator-(const Frac &a)
    {
        return Frac(-a.num, a.den); // 返回相反数
    }

    // 相等比较
    friend bool operator==(const Frac &lhs, const Frac &rhs)
    {
        return lhs.num * rhs.den == rhs.num * lhs.den; // 交叉相乘比较
    }

    // 不相等比较
    friend bool operator!=(const Frac &lhs, const Frac &rhs)
    {
        return !(lhs == rhs); // 使用 == 实现
    }

    // 小于比较
    friend bool operator<(const Frac &lhs, const Frac &rhs)
    {
        return lhs.num * rhs.den < rhs.num * lhs.den; // 交叉相乘比较
    }

    // 大于比较
    friend bool operator>(const Frac &lhs, const Frac &rhs)
    {
        return rhs < lhs; // 使用 < 实现
    }

    // 小于等于比较
    friend bool operator<=(const Frac &lhs, const Frac &rhs)
    {
        return !(rhs < lhs); // 使用 < 实现
    }

    // 大于等于比较
    friend bool operator>=(const Frac &lhs, const Frac &rhs)
    {
        return !(lhs < rhs); // 使用 < 实现
    }

    // 输出流重载
    friend ostream &operator<<(ostream &os, Frac x)
    {
        T g = __gcd(x.num, x.den); // 计算分子和分母的最大公约数
        if (x.den == g)
        {                           // 如果分母为最大公约数
            return os << x.num / g; // 只输出分子
        }
        else
        {
            ll t1 = x.num / g;
            ll t2 = x.den / g;
            return os << t1 / t2 << "+" << t1 % t2 << "/" << t2; // 输出简化后的分数
        }
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<vpll> p(n);
    vvl w(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        p[i].resize(m);
        w[i].resize(m);
        bool flag = false;
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j].sd;
        }
        sort(all(p[i]));
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j].ft;
        }
        sort(all(p[i]));
        for (int j = 0; j < m; j++)
        {
            cin >> w[i][j];
        }
    }
    int idx;
    cin >> idx;
    ll num = 0;
    ll den = 0;
    for (int i = 0; i < n; i++)
    {
        int m = p[i].size();
        bool flag = false;
        int pos = -1;
        for (int j = 0; j < m; j++)
        {
            if (p[i][j].sd == idx)
            {
                pos = j;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            int sc = p[i][pos].ft;
            int rank = 1;
            for (int j = 0; j < m; j++)
            {
                if (p[i][j].ft > sc)
                    rank++;
            }
            num += w[i][rank - 1];
            den++;
        }
    }
    cout << Frac<ll>(num, den) << endl;
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