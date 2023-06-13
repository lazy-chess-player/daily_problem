#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <string>

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

const int N = 1e5 + 5;

int i = 1;

void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll min_len = min(min(a, b), c);
	ll max_len = max(max(a, b), c);
	ll mid_len = a + b + c - min_len - max_len;
	
	bool flag = false;
	if (min_len == max_len)//²»ÇÐ
		flag = true;
	if (mid_len == min_len && max_len == 2 * min_len)//²»ÇÐ
		flag = true;
	if (mid_len == min_len && max_len == 2 * min_len)//ÇÐÒ»µ¶
		flag = true;
	if ((mid_len == max_len && max_len == 2 * min_len)|| (mid_len == min_len&& max_len == 3 * min_len))//ÇÐÁ½µ¶
		flag = true;
	if ((mid_len == min_len && max_len == 4 * min_len) || (mid_len == 2 * min_len && max_len == 3 * min_len))//ÇÐÈýµ¶
		flag = true;
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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