#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] == 0;
                i++;
            }
        }
        int l = 0;
        while (l < n && nums[l] != 0)
        {
            l++;
        }
        if (l == n - 1)
            return nums;
        int r = l + 1;
        while (r < n)
        {
            if (nums[r])
            {
                swap(nums[l], nums[r]);
                l++;
            }
            r++;
        }
        return nums;
    }
};