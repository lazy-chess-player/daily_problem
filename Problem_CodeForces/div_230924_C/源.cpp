#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int N = 3 * 1e5 + 5;
const int MOD = 998244353;

ll factorial( int n) 
{
	if (n == 0 || n == 1)
		return 1;
	ll result = 1;
	for ( int i = 2; i <= n; ++i) 
	{
		result *= i;
		result %= MOD;
	}
	return result;
}

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	ll action = 0;
	ll ans = 1;
	vector<int> v;
	for (int i = 0; i < n;)
	{
		int j = i + 1;
		int cnt = 1;
		while(s[j] == s[i])
		{
			cnt++; 
			j++;
		}
		if (cnt > 1)
		{
			ans *= cnt;
			ans %= MOD;
			action += cnt - 1;
		}
		v.push_back(cnt);
		i = j;
	}
	for (int i = 2; i <= action; i++)
	{
		ans *= i;
		ans %= MOD;
	}
	cout << action << ' ' << ans << endl;
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
