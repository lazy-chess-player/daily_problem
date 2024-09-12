#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    using ll = long long;
    using vi = vector<int>;
    using vvi = vector<vi>;
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        multiset<int> mn(nums.begin(), nums.begin() + n);
        multiset<int> mx(nums.begin() + n, nums.end());
        int ans = 0;
        while (!mn.empty() && !mx.empty())
        {
            auto it = mx.lower_bound(2 * (*mn.begin()));
            if (it == mx.end())
                break;
            ans++;
            mn.erase(mn.begin());
            mx.erase(it);
        }
        return ans * 2;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {42, 83, 48, 10, 24, 55, 9, 100, 10, 17, 17, 99, 51, 32, 16, 98, 99, 31, 28, 68, 71, 14, 64, 29, 15, 40};
    cout << s.maxNumOfMarkedIndices(nums);
}