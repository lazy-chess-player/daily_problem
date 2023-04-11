#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int>ans{ -1,-1 };
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (i < n && nums[i++] != target);
            if (nums[--i] != target)
                break;
            ans[0] = i;
            while (i < n && nums[i] == target)
            {
                i++;
            }
            ans[1] = i - 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int>test1_1 = { 5,7,7,8,8,10 };
    int test1_2 = 8;
    vector<int>ans1 = { 3,4 };

    vector<int>test2_1 = { 5,7,7,8,8,10 };
    int test2_2 = 6;
    vector<int>ans2 = { -1,-1 };

    vector<int>test3_1 = {};
    int test3_2 = 0;
    vector<int>ans3 = {-1,-1};

    assert("Test1 Warning!" && ans1 == s.searchRange(test1_1, test1_2));
    assert("Test2 Warning!" && ans2 == s.searchRange(test2_1, test2_2));
    assert("Test3 Warning!" && ans3 == s.searchRange(test3_1, test3_2));
    cout << "All Past!" << endl;

    return 0;
}