#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findMaxK(vector<int>& nums)
    {
        int ans = -1;
        unordered_set<int> mp(nums.begin(), nums.end());
        for (int num:nums)
        {
            if (mp.count(-num))
                ans = max(ans, num);
        }
        return ans;
    }
};