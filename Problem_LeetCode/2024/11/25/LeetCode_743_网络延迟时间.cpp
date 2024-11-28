#include <bits/stdc++.h>

using namespace std;

class Solution
{
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

    typedef unordered_map<int, int> umii;
    typedef unordered_map<ll, ll> uml;
    typedef unordered_map<char, int> umci;
    typedef unordered_map<char, ll> umcl;
    typedef unordered_map<string, int> umsi;
    typedef unordered_map<string, ll> umsl;

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vvi adj(n + 1);
        vvi cost(n + 1);
        for (auto t : times)
        {
            int u = t[0], v = t[1], w = t[2];
            adj[u].pb(v);
            cost[u].pb(w);
        }
        vi dis(n + 1, inf);
        dis[k] = 0;
        priority_queue<pii, vpii, greater<pii>> q;
        q.push({0, k});
        while (!q.empty())
        {
            auto [d, u] = q.top();
            q.pop();
            if (d > dis[d])
                continue;
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                int w = cost[u][i];
                if (dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = max(dis[i], ans);
        }
        if (ans == inf)
            ans = -1;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    cout << s.networkDelayTime(times, n, k) << "\n";
    return 0;
}