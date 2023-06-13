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

vi nums(10);

int func(int x)
{
	for (int i = 0; i < 10; i++)
	{
		if (nums[i] == 0 || i == x)
			continue;
		nums[i]--;
		int index = 0, n = 0;
		for (int j = 0; j < 10; j++)
		{
			n += nums[j];
			if (nums[j] > nums[index])
				index = j;
		}
		n -= nums[index];
		if ((index == i && nums[index] >= n + 1) ||( index != i && nums[index] > n + 1))
			nums[i]++;
		else 
			return i;
	}
	return -1;
}
void solve()
{
	int maxNum = 0, n = 0, max_ele = -1;
	for (int i = 0; i < 10; i++)
	{
		cin >> nums[i];
		if (nums[i] > maxNum)
		{
			maxNum = nums[i];
			max_ele = i;
		}
		n += nums[i];
	}
	n -= maxNum;
	if (n == 0 && nums[0] == 1)
	{
		cout << 0 << endl;
		return;
	}
	if (max_ele == 0 && maxNum >= n + 1)
	{
		cout << -1 << endl;
		return;
	}
	else if (maxNum > n + 1)
	{
		cout << -1 << endl;
		return;
	}
	int digit = func(0);
	while (digit >= 0)
	{
		cout << digit;
		digit = func(digit);
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), std::cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}