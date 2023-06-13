#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#define LEN (int)1e6+5
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<int> graph[LEN];
bool visited[LEN]{ false };
ll edges = 0, vertices = 0;

void dfs(int u)
{
	for (int v : graph[u])
	{
		edges++;
		if (visited[v])
			continue;
		vertices++;
		visited[v] = true;
		dfs(v);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	priority_queue<pll, vector<pll>, greater<>> groups;
	ll addEdge = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		edges = 0, vertices = 1;
		dfs(i);
		edges /= 2;
		addEdge += vertices * (vertices - 1) / 2 - edges;
		groups.push({ vertices,edges });
	}
	if (addEdge)
		cout << addEdge;
	else
	{
		pll m1 = groups.top();
		groups.pop();
		pll m2 = groups.top();
		ll all = m1.fi + m2.fi;
		cout << all * (all - 1) / 2 - (m1.se + m2.se);
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}