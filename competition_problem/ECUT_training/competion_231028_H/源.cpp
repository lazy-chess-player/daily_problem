#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>

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
	string a;
	cin >> a;
	string b = a;
	int n = a.length();
	sort(b.begin(), b.end());
	int start = -1, end = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			start = i;
			break;
		}
	}
	if (start == -1)
	{
		cout << a << endl;
		return;
	}
    string ans = a.substr(0, start);
    string c = b.substr(start);
	string d = a.substr(start);
	d.reserve();
	c.push_back('\0');
	int m = d.size();
	int maxLen = 0;
	char last = '\0';
	string temp;
	char t;
	for (int i = 0; i <m; i++)
	{
		int cnt = 0; 
		int j = 0;
		for (; j + i < m; j++)
		{
			if (d[j] == c[i])
				cnt++;
			else
			{
				t = c[j + 1];
				break;
			}
		}
		if (cnt > maxLen)
			temp = c.substr(j + 1);
		else if (cnt > maxLen && t < last)
		{
			temp = d.substr(i,j + 1);
			last = t;
		}
	}
	ans += temp;
	int p = temp.length();
	string q = a.substr(start + p);
	ans += q;
	cout << ans << endl;
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