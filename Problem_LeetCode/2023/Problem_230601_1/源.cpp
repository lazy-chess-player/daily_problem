#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int maximumTastiness(vector<int>& price, int k)
    {
        sort(price.begin(), price.end());

        auto f = [&](int d) -> int
        {
            int cnt = 1, pre = price[0];
            for (int p : price)
            {
                if (p >= pre + d)
                {
                    cnt++;
                    pre = p;
                }
            }
            return cnt;
        };
        int left = 0, right = (price.back() - price[0]) / (k - 1) + 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (f(mid) >= k ? left : right) = mid;
        }
        return left;
    }
};