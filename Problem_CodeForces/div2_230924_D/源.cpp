#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> prefix_xor(n);
    prefix_xor[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix_xor[i] = prefix_xor[i - 1] ^ a[i];
    }

    ll ans = 0;
    for (int l = 0; l < n; l++) 
    {
        for (int r = l; r < n; r++)
        {
            ll f = (l == 0) ? prefix_xor[r] : (prefix_xor[r] ^ prefix_xor[l - 1]);
            ans = (ans + f * (r - l + 1)) % MOD;
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}