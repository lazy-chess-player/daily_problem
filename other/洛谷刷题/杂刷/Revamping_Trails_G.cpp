#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>

#define endl '\n'

#define ft first
#define sd second

#define yes cout << "Yes\n"
#define no cout << "No\n"

#define RED cout << "\033[91m"
#define GREEN cout << '\033[92m'
#define YELLOW cout << '\033[93m'
#define BLUE cout << '\033[94m'
#define MAGENTA cout << '\033[95m'
#define CYAN cout << '\033[96m'
#define RESET cout << "\033[0m"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<string, int> msi;
typedef map<string, ll> msl;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

// 2<=n<=10000,1<=m<=50000,0<=k<=10
const int N = 1e6 + 6;  // 节点个数
const int M = 1e7 + 10; // 边数

// 数组模拟实现链表，邻接表存储图
int idx, h[N], ne[M], e[M], w[M];

int src; // 起点
int des; // 终点

int dis[N]; // 存储src到每个点的距离
bool st[N]; // 存储每个点的最短距离是否已确定

int n, m, k; // 点数，边数，层数

// 建图
void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
// 堆优Dijkstra
void dijkstra()
{
    // 初始化距离数组dis，所有顶点距离均设为无穷大（此处用常数0x3f表示）
    memset(dis, 0x3f, sizeof dis);

    // 设定源点src的距离为0
    dis[src] = 0;

    // 使用小根堆存储顶点距离与顶点编号
    priority_queue<pii, vpii, greater<pii>> heap;

    // 将源点(src, 0)插入堆中
    heap.push({0, src});

    // 当堆非空时，进行循环操作
    while (heap.size())
    {
        // 弹出堆顶元素，即当前未处理且距离最小的顶点信息（distance, vertex）
        auto t = heap.top();
        heap.pop();

        // 获取顶点编号和距离
        int ver = t.second;
        int distance = t.first;

        // 若该顶点已访问则跳过本次循环
        if (st[ver])
            continue;

        // 标记当前顶点为已访问
        st[ver] = true;

        // 遍历顶点ver的所有邻接点
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            // 获取当前邻接点j的编号
            int j = e[i];

            // 检查经顶点ver到达邻接点j的路径是否更短，若是，则更新j点距离并将其加入堆中
            if (dis[j] > distance + w[i])
            {
                dis[j] = distance + w[i];
                heap.push({dis[j], j});
            }
        }
    }
}

// 定义解决问题的主函数solve()
void solve()
{
    // 初始化距离链表表头
    memset(h, -1, sizeof h);

    // n：节点数量
    // m：原图中的边数
    // k：复制节点组数
    // src：源节点编号
    // des：目标节点编号
    cin >> n >> m >> k;
    src = 1;
    des = n;

    // 循环处理m条原始边
    while (m--)
    {
        // 读入一条边的端点u、v和权重w
        int u, v, w;
        cin >> u >> v >> w;

        // 使用add函数向原图添加边(u, v)和边(v, u)，权重均为w
        add(u, v, w);
        add(v, u, w);

        // 对于每个复制节点组i（范围1到k），在对应位置添加如下四条边：
        //   (u + (i-1)*n, v + i*n) 和 (v + (i-1)*n, u + i*n)：权重为0
        //   (u + i*n, v + i*n) 和 (v + i*n, u + i*n)：权重为w
        for (int i = 1; i <= k; i++)
        {
            add(u + (i - 1) * n, v + i * n, 0);
            add(v + (i - 1) * n, u + i * n, 0);
            add(u + i * n, v + i * n, w);
            add(v + i * n, u + i * n, w);
        }
    }

    // 调用dijkstra函数计算所有节点的最短路径，并存储结果在dis数组中
    dijkstra();

    int ans = 0x3f3f3f3f;

    // 遍历所有复制节点组（包括原节点组，即i=0），找到从源节点到目标节点所在组内任意节点的最短距离，
    // 并将最小值更新至ans
    for (int i = 0; i <= k; i++)
    {
        ans = min(dis[des + i * n], ans);
    }

    // 输出最终答案（最短路径长度）
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

// https://www.luogu.com.cn/problem/P2939