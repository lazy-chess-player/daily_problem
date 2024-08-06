#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <string>
#include <cmath>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <math.h>
#include <functional>

#define ull unsigned long long
#define ll long long
#define pii pair<ll, ll>
#define ft first
#define sd second
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define forn(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define forne(i, n) for (ll(i) = 1; (i) <= (n); (i)++)
#define rforn(i, n) for (ll(i) = (n - 1); i >= 0; i--)
#define rforne(i, n) for (ll(i) = n; i >= 1; i--)
#define vv vector
#define inf 0x4f4f4f4f
const int N = 4e5 + 100;
ll t;

void solve()
{

    int n;
    cin >> n;
    int m;
    cin >> m;
    vv<int> a(n);
    forn(i, m)
            cin >>
        a[i];
    vv<int> k(n);
    forn(i, m)
            cin >>
        k[i];
    vv<int> pos(n + 1, 1e16);
    forn(i, m)
        pos[--a[i]] = k[i];
    int mn = n;
    forn(j, n)
    {
        if (pos[mn] + abs(mn - 0) >= pos[j] + abs(j - 0))
            mn = j;
    }
    forn(i, n)
    {
        if (i <= mn)
        {
            pos[i] = pos[mn] + abs(mn - i);
        }
        else
        {
            mn = n;
            for (int j = i; j < n; j++)
            {
                if (pos[mn] + abs(mn - i) >= pos[j] + abs(j - i))
                    mn = j;
            }
            pos[i] = pos[mn] + abs(mn - i);
        }
    }
    mn = n;
    rforn(j, n)
    {
        if (pos[mn] + abs(mn - n + 1) >= pos[j] + abs(j - n + 1))
            mn = j;
    }
    rforn(i, n)
    {
        if (i >= mn)
        {
            pos[i] = pos[mn] + abs(mn - i);
        }
        else
        {
            mn = n;
            for (int j = i; j >= 0; j--)
            {
                if (pos[mn] + abs(mn - i) >= pos[j] + abs(j - i))
                    mn = j;
            }
            pos[i] = pos[mn] + abs(mn - i);
        }
    }

    forn(i, n)
            cout
        << pos[i] << " ";
    cout << endl;
}
void main()
{
    t = 1;
    cin >> t;
    while (t--)
        solve();
}