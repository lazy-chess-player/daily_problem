#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> nums(3);
        nums[0] = a;
        nums[1] = b;
        nums[2] = c;
        sort(nums.begin(), nums.end());

        vector<int> ans(2);
        if ((nums[1] - nums[0] == 2) || (nums[2] - nums[1] == 2))
            ans[0] = 1;
        else
            ans[0] = (nums[1] != nums[0] + 1) + (nums[1] != nums[2] - 1);
        ans[1] = nums[2] - nums[0] + 1 - 3;

        return ans;
    }
};