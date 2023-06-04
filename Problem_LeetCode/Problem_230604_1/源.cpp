#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int distinctAverages(vector<int>& nums)
    {
        unordered_set<int> hmap;
        sort(nums.begin(), nums.end());
        int r = nums.size() - 1;
        int l = 0;
        while (l < r)
        {
            hmap.insert(nums[r--] + nums[l++]);
        }
        return hmap.size();
    }
};