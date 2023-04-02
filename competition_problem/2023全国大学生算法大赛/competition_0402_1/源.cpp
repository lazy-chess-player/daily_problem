#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int n=0;
int a[500001] = {0};
int sum = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int average = sum / 4;
    int tmp = 0;
    int s[4] = { 0 };
    int j = 0;
    int i = 0;
    while(i < n+1)
    {
        if (abs(tmp - average) <= abs(tmp + a[i] - average))
        {
            s[j++] = tmp;
            tmp = 0;
        }
        tmp += a[i];
        i++;
    }
    cout << max({ s[0], s[1], s[2], s[3] }) - min({ s[0], s[1], s[2], s[3] }) << endl;
    return 0;
}