#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#define LEN (int)1e6+5

using namespace std;


int vertices[LEN]{ 0 };
bool visited[LEN]{ false };
int n, m, u, v;

void solve()
{
	cin >> n >> m;
	int vertices[10] = { 0 };
	for (int i = 0; i <m; i++)
	{
		cin >> u >> v;
		if (u > v)
			swap(u, v);
		if (vertices[u])
		{
			if (vertices[u] < v)
				continue;
			else if (vertices[u] > v)
				vertices[u] = v;
		}
		else
			vertices[u] = v;
	}
	priority_queue<int, vector<int>, greater<> > graphs;
	int addEdge = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;
		int cur = i;
		visited[cur] = true;
		int cnt = 1;
		while (vertices[cur])
		{
			cur = vertices[cur];
			visited[cur] = true;
			cnt++;
		}
		addEdge += (cnt * (cnt - 1)) / 2;
		graphs.push(cnt);
	}
	if (addEdge != m)
	{
		cout << addEdge - m << endl;
		return;
	}
	int min1 = graphs.top();
	graphs.pop();
	int min2 = graphs.top();
	graphs.pop();
	cout << ((min1 + min2) * (min1 + min2 - 1)) / 2 - (min1 * (min1 - 1)) / 2 - (min2 * (min2 - 1)) / 2 << endl;
	return;
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