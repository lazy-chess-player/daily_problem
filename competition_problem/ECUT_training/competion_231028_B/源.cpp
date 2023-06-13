#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<cstring>
#define inf 0x3f3f3f3f
#define pb push_back
#define lowbit(x) x&-x 
using namespace std;
typedef long long ll;

typedef pair<int, int> PII;
typedef vector<int> vi;
typedef vector<vi> vii;
const int N = 1e6 + 10, K = 131;
unsigned long long pre[N], ne[N], st[N];
vii mp;
char str[N];


bool choose(int r1, int l, int r2, int len)
{
    int ll = 0, lr = r1 - l;
    //  cout<<r1 <<" "<< r2 <<endl;
    if (ne[l] - ne[r1 + 1] * st[r1 - l + 1] != ne[r2 - r1 + l] - ne[r2 + 1] * st[r1 - l + 1]) {
        ll = 0, lr = r1 - l;
        while (ll < lr) {
            int mid = ll + lr >> 1;
            //  cout<<mid<<" "<<ne[r1 - mid] - ne[r1 + 1] * st[mid + 1] <<" Sss "<< ne[r2 - mid] - ne[r2 + 1] * st[mid + 1]<<endl;
            if (ne[r1 - mid] - ne[r1 + 1] * st[mid + 1] != ne[r2 - mid] - ne[r2 + 1] * st[mid + 1]) lr = mid;
            else ll = mid + 1;
        }
        //  cout<<1<<" "<<r1-ll<<" "<<str[r1 - ll] << " "<< r2 - ll <<" "<< str[r2 - ll]<<endl;
        return str[r1 - ll] < str[r2 - ll];
    }
    else {
        ll = 0, lr = r2 - r1 - 1;
        // cout<<"sssssssssss"<<endl;
        while (ll < lr) {
            int mid = ll + lr >> 1;
            if (pre[r1 + 1 + mid] - pre[r1] * st[mid + 1] != ne[r2 - (r1 - l + 1) - mid] - ne[r2 - (r1 - l + 1) + 1] * st[mid + 1]) lr = mid;
            else ll = mid + 1;
        }
        return str[r1 + 1 + ll] < str[r2 - (r1 - l + 1) - ll];
    }
    return true;
}

void solve()
{
    memset(str, 0, sizeof(str));
    memset(pre, 0, sizeof(pre));
    memset(ne, 0, sizeof(ne));
    cin >> str + 1;
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++) 
    {
        pre[i] = pre[i - 1] * K + (str[i] - 'a');
    }
    for (int i = len; i >= 1; i--)
    {
        ne[i] = ne[i + 1] * K + (str[i] - 'a');
    }
    vector<int> q(30);
    for (int i = 1; i <= len; i++)
    {
        q[str[i] - 'a']++;
    }
    int l = -1, r = -1, cn = -1;
    bool flag = true;
    for (int i = 1; i <= len; i++)
    {
        int t = str[i] - 'a';
        q[t]--;
        for (int j = 0; j < t; j++)
        {

            if (q[j]) 
            {
                l = i;
                cn = j;
                flag = false;
                break;
            }
        }
        if (!flag) 
            break;
    }


    if (l == -1)
    {
        printf("%s\n", str + 1);
        return;
    }
    for (int i = len; i >= l; i--) if (str[i] - 'a' == cn) 
    {
        r = i; 
        break; 
    }
    int ansr = -1;
    for (int i = r; i > l; i--) 
    {
        if (str[i] - 'a' == cn) 
        {
            if (ansr == -1 || choose(i, l, ansr, len))
                ansr = i;
        }
    }
    int t = ansr;
    for (int i = 1; i < l; i++) 
        std::cout << str[i];
    for (int i = t; i >= l; i--) 
        std::cout << str[i];
    for (int i = t + 1; i <= len; i++) 
        std::cout << str[i];
    std::cout << '\n';
}


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
