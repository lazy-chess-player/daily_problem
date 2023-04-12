#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cstdlib>

using namespace std;

class Solution {
public:
    void overturn(vector<int>& nums, int left, int right)
    {
        while (left<right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (k > n)
            k %= n;
        overturn(nums, 0, n - 1);
        overturn(nums, 0, k - 1);
        overturn(nums, k, n - 1);
    }
};


int main()
{
    Solution s;

    vector<int> test1 = { 1,2,3,4,5,6,7 };
    vector<int> ans1 = { 5,6,7,1,2,3,4 };

    s.rotate(test1, 3);
    assert("Test1 Warning!" && ans1 == test1);

    vector<int> test2 = { -1,-100,3,99 };
    vector<int> ans2 = { 3,99,-1,-100 };

    s.rotate(test2,2);
    assert("Test2 Warning!" && ans2 == test2);

    vector<int> test3 = { -1};
    vector<int> ans3 = {-1};

    s.rotate(test3,3);
    assert("Test2 Warning!" && ans3 == test3);

    std::cout << "All Past!" << endl;

    return 0;
}