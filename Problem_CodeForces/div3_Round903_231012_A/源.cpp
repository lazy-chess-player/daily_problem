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

int n, m;

int findMinimumOperations(string x, string s) {
    int operations = 0;
    int xLength = x.length();
    int sLength = s.length();
    int comparePosition = 0;

    while (comparePosition < xLength) {
        int i = 0;
        int j = comparePosition;

        while (i < sLength && j < xLength) {
            if (s[i] == x[j]) {
                i++;
            }
            j++;
        }

        if (i == sLength) {
            // s is a substring of x
            return operations;
        }

        if (j >= xLength) {
            break;
        }

        comparePosition++;
        operations++;
    }

    return -1;
}

void solve()
{
	cin >> n >> m;
	string x, s;
    cin >> x >> s;
    int optionNum = 0;
    while (optionNum < 8)
    {
        if (x.length() >= s.length())
        {
            if (string::npos != x.find(s))
                break;
        }
        x += x;
        optionNum++;
    }
    if (optionNum == 8)
        optionNum = -1;
    cout << optionNum << endl;
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