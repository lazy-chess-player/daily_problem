#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int unequalTriplets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && nums[j] == nums[i])
            {
                j++;
            }
            res += i * (j - i) * (n - j);
        }
        return res;
    }
};