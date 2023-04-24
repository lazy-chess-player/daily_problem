#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

long long fun(long long num,int len)
{
    long long n = num / pow(10, len-1);

    long long sum = 0;

    while (len--&&len!=1)
    {
        sum += pow(4, len);
    }
    if (n > 8)
        return 4 * sum;
    if (n > 7)
        return 3 * sum;
    if (n > 5)
        return 2 * sum;
    return sum;
}

int main()
{
    long long num=0;
    cin >> num;
    long long tmp = num;
    long long ans = 0;
    int len = 0;
    while (tmp)
    {
        tmp /= 10;
        len++;
    }

    while (num)
    {
        ans += fun(num, len);
        num /= 10;
        len--;
    }
    ans /= 15;
    cout << ans << endl;
    return 0;
}