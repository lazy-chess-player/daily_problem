#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int map[100000001] = { 0 };
int main()
{
    int n = 0;
    cin >> n;
    vector<int>a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        map[a[i]] = i;
    }

    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (map[a[i]] > i)
        {
            sum += (map[a[i]] - i);
        }
    }
    cout << sum << endl;
    return 0;
}