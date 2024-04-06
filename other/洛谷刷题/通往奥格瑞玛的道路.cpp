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

const int N = 1e5 + 5;

const int M = 1e5 + 5;

int n, m, b, fee[N];

int h[N], e[M], ne[M], w[M];

int idx;

long dist[N];
bool vis[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dijkstra(int maxf)
{
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> heap;
    heap.push({0, 1});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int u = t.second;
        if (vis[u])
            continue;
        if (u == n)
            break;
        vis[u] = true;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];
            if (fee[v] > maxf)
                continue;
            if (dist[u] + w[i] < dist[v])
            {
                dist[v] = dist[u] + w[i];
                heap.push({dist[v], v});
            }
        }
    }

    return dist[n];
}

void init()
{
    memset(h, -1, sizeof h);
    idx = 0;
}

void solve()
{
    init();
    cin >> n >> m >> b;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> fee[i];
        r = max(r, fee[i]);
    }
    l = max(fee[1], fee[n]);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    while (l < r)
    {
        int mid = l + (r - l >> 1);
        if (dijkstra(mid) <= b)
            r = mid;
        else
            l = mid + 1;
    }

    if (dijkstra(l) > b)
        cout << "AFK";
    else
        cout << l << endl;
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

// https://www.luogu.com.cn/problem/P1462