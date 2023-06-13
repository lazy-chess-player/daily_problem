#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <set>

#define max(a,b) (a)>(b)?(a):(b);
#define min(a,b) (a)<(b)?(a):(b);
#define endl '\n'
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 1e5 + 5;

int m, n;

struct VectorHash
{
	template <typename T>
	std::size_t operator () (const std::vector<T>& v) const 
	{
		std::size_t seed = v.size();
		for (const auto& elem : v) 
		{
			seed ^= std::hash<T>()(elem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		}
		return seed;
	}
};

int check(const vector<int>& ts)
{
	int cnt = 0;
	for (int i = 1; i < 51; i++)
	{
		if (ts[i] > 0)
			cnt++;
	}
	return cnt;
}

void solve()
{
	int n; cin >> n;
	vector<vector<int>> TS;
	vector<int> ts(51);
	unordered_map<vector<int>, int,VectorHash> Smap;
	int m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		vector<int> S(m);
		for (int j = 0; j < m; j++)
		{
			cin >> S[j];
		}
		if (Smap[S])
			continue;
		else
			Smap[S]++;
		TS.push_back(S);
	}
	n = TS.size();
	if (n <= 1)
	{
		cout << 0 << endl;
		return;
	}
	int maxElements = 0;
	int maxMask = (1 << n) - 1;

	vector<int> dp(1 << n, -1);
	dp[0] = 0;

	for (int mask = 1; mask <= maxMask; mask++) 
	{
		for (int i = 0; i < n; i++) 
		{
			if (!(mask & (1 << i))) 
			{
				int newMask = mask | (1 << i);
				int newSize = dp[mask] + TS[i].size();

				dp[newMask] = max(dp[newMask], newSize);
			}
		}
	}

	cout << dp[maxMask] << endl;
	//for (auto inter : TS)
	//{
	//	for (auto num : inter)
	//	{
	//		ts[num]++;
	//	}
	//}
	//int total = check(ts);
	//int maxNum = 0;
	//for (auto inter : TS)
	//{
	//	for (auto num : inter)
	//	{
	//		ts[num]--;
	//	}
	//	int counter = check(ts);
	//	if (counter < total)
	//		maxNum = max(maxNum, counter);
	//	for (auto num : inter)
	//	{
	//		ts[num]++;
	//	}
	//}
	//cout << maxNum << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

