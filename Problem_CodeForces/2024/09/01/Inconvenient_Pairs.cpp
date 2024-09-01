#include <bits/stdc++.h>

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
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define sort_all(x) sort(all(x))
#define reverse_all(x) reverse(all(x))
#define sort1_all(x) sort(x.begin() + 1, x.end())
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL
#define RED cout << "\033[91m"
#define GREEN cout << "\033[92m"
#define YELLOW cout << "\033[93m"
#define BLUE cout << "\033[94m"
#define MAGENTA cout << "\033[95m"
#define CYAN cout << "\033[96m"
#define RESET cout << "\033[0m"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pli> vpli;

typedef map<int, int> mii;

const int N = 1e6 + 10;
int n, m, k, heng[N], shu[N], vish[N], viss[N], b1[N], b2[N];
struct dian
{
    int x, y;
} a[N];
map<int, int> mp;

inline int read()
{
    int x = 0, ff = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            ff = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * ff;
}

inline bool cmp1(int x, int y) { return a[x].x < a[y].x; }
inline bool cmp2(int x, int y) { return a[x].y < a[y].y; }

int main()
{
    int T = read();
    while (T--)
    {
        n = read();
        m = read();
        k = read();
        memset(vish, 0, sizeof(vish));
        memset(viss, 0, sizeof(viss));
        for (int i = 1; i <= n; ++i)
        {
            shu[i] = read();
            viss[shu[i]] = 1;
        }
        for (int i = 1; i <= m; ++i)
        {
            heng[i] = read();
            vish[heng[i]] = 1;
        }
        for (int i = 1; i <= k; ++i)
        {
            a[i].x = read();
            a[i].y = read();
        }
        int n1 = 0, n2 = 0;
        for (int i = 1; i <= k; ++i)
        {
            if (vish[a[i].y] && viss[a[i].x])
                continue;
            if (vish[a[i].y])
                b1[++n1] = i;
            else
                b2[++n2] = i;
        }
        sort(b1 + 1, b1 + n1 + 1, cmp1);
        sort(b2 + 1, b2 + n2 + 1, cmp2);
        ll ans = 0;
        int j = 1;
        for (int i = 1; i < n; ++i)
        {
            int sm = 0;
            while (j <= n1 && a[b1[j]].x > shu[i] && a[b1[j]].x < shu[i + 1])
            {
                mp[a[b1[j]].y]++;
                sm++;
                ++j;
            }
            for (auto x : mp)
            {
                sm -= x.second;
                ans += (ll)x.second * sm;
            }
            mp.clear();
        }
        j = 1;
        for (int i = 1; i < m; ++i)
        {
            int sm = 0;
            while (j <= n2 && a[b2[j]].y > heng[i] && a[b2[j]].y < heng[i + 1])
            {
                mp[a[b2[j]].x]++;
                sm++;
                ++j;
            }
            for (auto x : mp)
            {
                sm -= x.second;
                ans += (ll)x.second * sm;
            }
            mp.clear();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
