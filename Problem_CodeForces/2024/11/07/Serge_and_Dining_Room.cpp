#include <bits/stdc++.h>

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
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

#define RED cout << "\033[91m"     // 红色
#define GREEN cout << "\033[92m"   // 绿色
#define YELLOW cout << "\033[93m"  // 蓝色
#define BLUE cout << "\033[94m"    // 品红
#define MAGENTA cout << "\033[95m" // 青色
#define CYAN cout << "\033[96m"    // 青色
#define RESET cout << "\033[0m"    // 重置

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t i128;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<string, ll> psl;

typedef tuple<int, int, int> ti3;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ld, ld, ld> tld3;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 3e5 + 5;

// 懒标记线段树的标签结构
struct Tag
{
    ll add; // 用于区间加法操作
    Tag(ll v = 0) : add(v) {}
    // 应用标签的操作
    void apply(Tag t)
    {
        add += t.add; // 更新加法标签
    }
};

// 懒标记线段树的信息结构
struct Info
{
    ll mn; // 当前区间的最小值

    Info(ll v = inf) : mn(v) {}
    // 应用标签的操作
    void apply(Tag t)
    {
        mn += t.add; // 更新最小值
    }
};

// 信息结构的加法运算符重载
Info operator+(Info a, Info b)
{
    Info c;
    c.mn = std::min(a.mn, b.mn); // 更新最小值
    return c;
}

// 懒标记线段树模板类
template <class Info, class Tag>
struct LazySegmentTree
{
    const int n;            // 数组大小
    std::vector<Info> info; // 存储线段树节点的信息
    std::vector<Tag> tag;   // 存储懒标记

    // 构造函数，初始化线段树
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}

    // 使用初始值构造线段树
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size())
    {
        std::function<void(int, int, int)> build = [&](int p, int l, int r)
        {
            if (r - l == 1)
            {
                info[p] = init[l]; // 叶子节点直接赋值
                return;
            }
            int m = (l + r) / 2;    // 中间点
            build(2 * p, l, m);     // 构建左子树
            build(2 * p + 1, m, r); // 构建右子树
            pull(p);                // 更新父节点
        };
        build(1, 0, n);
    }

    // 更新父节点
    void pull(int p)
    {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // 应用标签到节点
    void apply(int p, const Tag &v)
    {
        info[p].apply(v); // 应用标签到信息
        tag[p].apply(v);  // 更新懒标记
    }

    // 推送懒标记到子节点
    void push(int p)
    {
        apply(2 * p, tag[p]);     // 推送到左子树
        apply(2 * p + 1, tag[p]); // 推送到右子树
        tag[p] = Tag();           // 清空当前节点的懒标记
    }

    // 区间应用标签
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v)
    {
        if (l >= y || r <= x)
        {
            return; // 范围不相交
        }
        if (l >= x && r <= y)
        {
            apply(p, v); // 当前区间完全包含在应用范围内
            return;
        }
        int m = (l + r) / 2;                  // 中间点
        push(p);                              // 推送懒标记
        rangeApply(2 * p, l, m, x, y, v);     // 递归到左子树
        rangeApply(2 * p + 1, m, r, x, y, v); // 递归到右子树
        pull(p);                              // 更新父节点
    }

    // 对外接口，区间应用标签
    void rangeApply(int l, int r, const Tag &v)
    {
        return rangeApply(1, 0, n, l, r, v);
    }

    int Query(int p, int l, int r)
    {
        push(p);
        if (info[p].mn > 0)
            return -1;
        if (r - l == 1)
            return l;
        int m = (l + r) / 2;
        if (info[2 * p + 1].mn < 0)
            return Query(2 * p + 1, m, r);
        else if (info[2 * p].mn < 0)
            return Query(2 * p, l, m);
        else
            return -1;
    }

    int Query()
    {
        return Query(1, 0, N);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Info> cnt(N, {0});
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]].mn--;
    }
    vi b(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        cnt[b[i]].mn++;
    }
    LazySegmentTree<Info, Tag> seg(cnt);
    int q;
    cin >> q;
    while (q--)
    {
        int op, p, x;
        cin >> op >> p >> x;
        if (op == 1)
        {
            if (x > a[p])
                seg.rangeApply(a[p] + 1, x + 1, Tag(-1));
            else
                seg.rangeApply(x + 1, a[p] + 1, Tag(1));
            a[p] = x;
        }
        else
        {
            if (x > b[p])
                seg.rangeApply(b[p] + 1, x + 1, Tag(1));
            else
                seg.rangeApply(x + 1, b[p] + 1, Tag(-1));
            b[p] = x;
        }
        cout << seg.Query() << "\n";
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