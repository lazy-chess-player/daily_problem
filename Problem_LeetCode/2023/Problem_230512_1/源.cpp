#include <vector>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums)
    {
        int base = 0, d = 0, mx = 0, mn = 0x3f3f3f3f, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int a = nums[i - 1], b = nums[i];
            base += abs(a - b);
            mx = max(mx, min(a, b));
            mn = min(mn, max(a, b));
            d = max(d, max(abs(nums[0] - b) - abs(a - b),abs(nums[n - 1] - a) - abs(a - b)));
        }
        return base + max(d, 2 * (mx - mn));
    }
};