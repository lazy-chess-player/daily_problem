#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <numeric>

#define endl '\n'

#define ft first
#define sd second

#define yes cout << "Yes\n"
#define no cout << "No\n"

#define RED cout << "\033[91m"
#define GREEN cout << '\033[92m'
#define YELLOW cout << '\033[93m'
#define BLUE cout << '\033[94m'
#define MAGENTA cout << '\033[95m'
#define CYAN cout << '\033[96m'
#define RESET cout << "\033[0m"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<string, ll> psl;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pss> vpss;

typedef vector<vi> vvi;
typedef vector<vl> vvl;

typedef queue<int> qi;
typedef queue<ll> ql;
typedef queue<pii> qpii;
typedef queue<pll> qpll;
typedef queue<psi> qpsi;
typedef queue<psl> qpsl;

typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<string> pqs;
typedef priority_queue<pii> pqpii;
typedef priority_queue<psi> pqpsi;
typedef priority_queue<pll> pqpl;
typedef priority_queue<psi> pqpsl;

typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<char, ll> mcl;
typedef map<string, int> msi;
typedef map<string, ll> msl;

typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_map<char, int> umci;
typedef unordered_map<char, ll> umcl;
typedef unordered_map<string, int> umsi;
typedef unordered_map<string, ll> umsl;

const int N = 1.5e3;

ll g[N][N];
ll ans[int(5e6 + 5)];
ll idx = 1;
void init()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i, k = 1; j > 0; j--, k++)
        {
            g[j][k] = g[j - 1][k] + g[j][k - 1] - g[j - 1][k - 1] + idx * idx;
            ans[idx++] = g[j][k];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    init();
    while (_--)
    {
        solve();
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1829/G