#include <bits/stdc++.h>

using namespace std;

class Solution
{
#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse1_all(x) reverse(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
    // typedef __int128_t i128;

    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<ld, ld> pdd;
    typedef pair<ll, int> pli;
    typedef pair<string, string> pss;
    typedef pair<string, int> psi;
    typedef pair<string, ll> psl;

    typedef tuple<int, int, int> ti3;
    typedef tuple<ll, ll, ll> tl3;
    typedef tuple<ld, ld, ld> tld3;

    typedef vector<bool> vb;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<string> vs;
    typedef vector<pii> vpii;
    typedef vector<pll> vpll;
    typedef vector<pli> vpli;
    typedef vector<pss> vpss;
    typedef vector<ti3> vti3;
    typedef vector<tl3> vtl3;
    typedef vector<tld3> vtld3;

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
    typedef priority_queue<pll> pqpll;
    typedef priority_queue<psi> pqpsl;

    typedef map<int, int> mii;
    typedef map<int, bool> mib;
    typedef map<ll, ll> mll;
    typedef map<ll, bool> mlb;
    typedef map<char, int> mci;
    typedef map<char, ll> mcl;
    typedef map<char, bool> mcb;
    typedef map<string, int> msi;
    typedef map<string, ll> msl;

    typedef unordered_map<int, int> umii;
    typedef unordered_map<ll, ll> uml;
    typedef unordered_map<char, int> umci;
    typedef unordered_map<char, ll> umcl;
    typedef unordered_map<string, int> umsi;
    typedef unordered_map<string, ll> umsl;

public:
    const ll mod = 1e9 + 7;
    int countWinningSequences(string s)
    {
        int n = s.length();
        auto turn = [&](char ch) -> int
        {
            if (ch == 'F')
                return 0;
            else if (ch == 'W')
                return 1;
            else
                return 2;
        };
        auto check = [&](int a, int b) -> int
        {
            if (b == 0 && a == 2)
                return 1;
            if (b == 1 && a == 0)
                return 1;
            if (b == 2 && a == 1)
                return 1;
            if (a == 0 && b == 2)
                return -1;
            if (a == 1 && b == 0)
                return -1;
            if (a == 2 && b == 1)
                return -1;
            return 0;
        };

        vvl f(4, vl(2 * n + 1, 0));
        f[3][n] = 1;
        for (int i = 0; i < n; ++i)
        {
            vvl g(4, vl(2 * n + 1, 0));

            for (int j = 0; j < 4; ++j)
            {
                for (int k = 0; k < 2 * n + 1; ++k)
                {
                    if (f[j][k] == 0)
                        continue;
                    for (int l = 0; l < 3; ++l)
                    {
                        if (j != 3 && l == j)
                            continue;
                        int d = k + check(turn(s[i]), l);
                        if (d < 0 || d > 2 * n)
                        {
                            continue;
                        }
                        g[l][d] = (g[l][d] + f[j][k]) % mod;
                    }
                }
            }
            f = g;
        }
        ll ans = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = n + 1; j <= 2 * n; ++j)
            {
                ans = (ans + f[i][j]) % mod;
            }
        }

        return (int)ans;
    }
};