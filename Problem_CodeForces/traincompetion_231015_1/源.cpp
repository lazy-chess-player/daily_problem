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

const int N = 1e5 + 5;
//
//void solveA()
//{
//    int n;
//    cin >> n;
//    unordered_map<string, vs> killCount;
//    bool pentaKill = 0;
//    while (n--)
//    {
//        string a, b;
//        cin >> a >> b;
//        auto iter = find(killCount[a].begin(), killCount[a].end(), b);
//        if (iter != killCount[a].end())
//        {
//            killCount[a].erase(killCount[a].begin(), iter + 1);
//        }
//        killCount[a].push_back(b);
//        if (killCount[a].size() == 5)
//        {
//            pentaKill = true;
//            break;
//        }
//    }
//    if (pentaKill)
//    {
//        std::cout << "PENTA KILL!" << endl;
//    }
//    else
//        std::cout << "SAD:(" <<endl;
//}

//void solveI()
//{
//	string s;
//	cin >> s;
//	char a = *s.begin();
//	bool flag = false;
//	for (char c : s)
//	{
//		if (c != a)
//			flag = true;
//	}
//	if (flag)
//		cout << 0 << endl;
//	else
//		cout << s.size() - 1 << endl;
//}


int pos[40];
ll pow2[40];

void init()
{
	pow2[0] = 1;
	for (int i = 1; i <= 31; i++)
		pow2[i] = pow2[i - 1] * 2;
	return;
}

void solve()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 31; i > 0; i--)
	{
		pos[i] = 0;
	}
	for (int i = 31; i > 0; i--)
	{
		if (n >= pow2[i])
		{
			pos[i]++;
			n -= (pow2[i]);
			pos[1]++;
		}
	}
	if (n % 2)
		pos[1]++;
	cout<<"nunhehheh";
	for (int i = 31; i > 0; i--)
	{
		for (int j = 0; j < pos[i]; j++)
			cout<<'h';
		cout<<'a';
	}
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	cin >> t;
	init();
	while (t--)
	{
		solve();
	}
	return 0;
}
