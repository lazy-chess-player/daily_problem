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
//
//void solve()
//{
//	int n; cin >> n;
//	char temp;
//	int maxChar;
//	int len = n / 2;
//	int num;
//	int optNum = 0;
//	vector<vector<int>> div1(len, vector<int>(len));
//	vector<vector<int>> div2(len, vector<int>(len));
//	vector<vector<int>> div3(len, vector<int>(len));
//	vector<vector<int>> div4(len, vector<int>(len));
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> temp;
//			num = (int)(temp - 'a');
//			if (i < len && j < len)
//				div1[i][j] = num;
//			else if (i < len && j >= len)
//				div2[j - len][i] = num;
//			else if (i >= len && j < len)
//				div3[len - (i - len) - 1][j] = num;
//			else if (i >= len && j >= len)
//				div4[len - (j - len) - 1][len - (i - len) - 1] = num;
//		}
//	}
//
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len; j++)
//		{
//			maxChar = max(max(div1[i][j], div2[i][j]), max(div3[i][j], div4[i][j]));
//			optNum += 4 * maxChar - div1[i][j] - div2[i][j] - div3[i][j] - div4[i][j];
//		}
//	}
//	cout<<optNum<<endl;
//}

void solve()
{
	int n; cin >> n;
	vector<vi> matrix(n, vi(n));
	char temp;
	int num;
	int ans = 0;
	int maxChar;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			matrix[i][j] = (int)(temp - 'a') + 1;
		}
	}
	for (int start = 0, end = n - 1; start <= end; start++, end--)
	{
		for (int i = 0; start + i < end; i++)
		{
			maxChar = max(max(matrix[start][start + i], matrix[end - i][start]), max(matrix[end][end - i], matrix[start + i][end]));
			ans += 4 * maxChar - matrix[start][start + i] - matrix[end - i][start] - matrix[end][end - i] - matrix[start + i][end];
		}
	}
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