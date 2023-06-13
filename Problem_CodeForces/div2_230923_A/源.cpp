#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 105


void solve()
{
	int n; cin >> n;
	vector<int> s(n);
	vector<int> e(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> e[i];
	}
	int w = s[0];
	int maxNum = e[0];
	for (int i = 1; i < n; i++)
	{
		if (s[i] < w)
			e[i] = 0;
	}
	sort(e.begin(), e.end(), [](int a, int b) {return a > b; });
	if (e[0] > maxNum || e[1] == maxNum)
		cout << -1 << endl;
	else
		cout << w << endl;
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