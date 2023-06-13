#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef priority_queue<int> pqi;

const int N = 1e5 + 5;

int n, k;

void solve()
{
	cin >> n >> k;
	vi heights(n);
	for (int i = 0; i <n; ++i)
	{
		cin >> heights[i];
	}
	vector<pqi> teams(k);
	vi diffs(k, 0);
	teams[0].push(heights[0]);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if(heights[i])
		}
	}
}


int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

int main()
{
}