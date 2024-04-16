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

int mp[30][30];

void solve()
{
    memset(mp, 0x3f, sizeof mp);
    string s, t;
    cin >> s >> t;
    int m;
    cin >> m;
    while (m--)
    {
        char a, b;
        int w;
        cin >> a >> b >> w;
        a = a - 96;
        b = b - 96;
        mp[a][b] = min(w, mp[a][b]);
    }
    for (int i = 1; i <= 26; i++)
    {
        mp[i][i] = 0;
    }
    for (int k = 1; k <= 26; k++)
    {
        for (int i = 1; i <= 26; i++)
        {
            for (int j = 1; j <= 26; j++)
            {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    int sum = 0;
    if (s.size() != t.size())
    {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char a = s[i] - 96, b = t[i] - 96;
        int now = 1e9, id;
        for (int j = 1; j <= 26; j++)
        {
            now = min(now, mp[a][j] + mp[b][j]);
            if (now == mp[a][j] + mp[b][j])
                id = j;
        }
        if (now == 1e9)
        {
            cout << "-1\n";
            return;
        }
        sum += now;
        s[i] = id + 96;
    }
    cout << sum << '\n';
    cout << s << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}