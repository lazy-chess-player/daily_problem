#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

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

void solve()
{
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int minB = 1;
	for (int i = 0; i < n; i++)
	{
		if (minB == a[i])
			minB++;
		minB++;
	}
	cout << minB - 1 << endl;
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
