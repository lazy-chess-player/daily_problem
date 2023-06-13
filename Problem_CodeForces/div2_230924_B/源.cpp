#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 3 * 1e5 + 5;


void solve()
{
	int n; cin >> n;/*
	vector<vector<ll>> board(N, vector<ll>(N));*/
	vector<ll>a(n);
	vector<ll>b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	ll minA = *min_element(a.begin(), a.end());
	ll minB = *min_element(b.begin(), b.end());
	ll sumCol = minA * n;
	ll sumRow = minB * n;
	for (auto x : b)
	{
		sumCol += x;
	}
	for (auto x : a)
	{
		sumRow += x;
	}
	ll ans = min(sumCol, sumRow);
	cout << ans << endl;
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