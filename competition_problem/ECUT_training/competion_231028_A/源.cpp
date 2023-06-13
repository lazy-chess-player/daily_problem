#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>

#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define fi first
#define se second
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef vector<pss> vpss;
typedef queue <int> qi;
typedef queue <ll> ql;
typedef queue <pii> qpii;

const int N = 1e5 + 5;

void solve()
{
	int n; cin >> n;
	vs coupletsUp(n);
	vs coupletsDown(n);
	vi symbolUp(n);
	vi symbolDown(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coupletsUp[i];
		symbolUp[i] = *(coupletsUp[i].end() - 1) < '3' ? 1 : 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> coupletsDown[i];
		symbolDown[i] = *(coupletsDown[i].end() - 1) > '2' ? 1 : 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (symbolUp[i] != symbolDown[i])
		{
			cout << "NO\n";
			return;
		}
	}
	if (*(symbolUp.end() - 1) != 0)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}