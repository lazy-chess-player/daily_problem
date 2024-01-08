#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (!n)
            return -1;
        int l = 0;
        int r = n - 1;
        if (nums[l] == target)
            return l;
        if (nums[r] == target)
            return r;
        int mid = (l + r) / 2;
        while (n)
        {
            if (nums[mid] > target)
                r = mid;
            else if (nums[mid] < target)
                l = mid;
            else
                return mid;
            mid = (l + r) / 2;
            n /= 2;
        }
        return -1;
    }
};

int main()
{
    Solution s;

    vector<int>test1_1 = { -1,0,3,5,9,12 };
    int test1_2 = 9;
    int ans1 = 4;

    vector<int>test2_1 = { 5,7,7,8,8,10 };
    int test2_2 = 6;
    int ans2 = -1;

    vector<int>test3_1 = { 2,5 };
    int test3_2 = 5;
    int ans3 = 1;

    vector<int>test4_1 = { -1,0,5 };
    int test4_2 = -1;
    int ans4 = 0;

    assert("Test1 Warning!" && ans1 == s.search(test1_1, test1_2));
    assert("Test2 Warning!" && ans2 == s.search(test2_1, test2_2));
    assert("Test3 Warning!" && ans3 == s.search(test3_1, test3_2));
    assert("Test4 Warning!" && ans4 == s.search(test4_1, test4_2));
    std::cout << "All Past!" << endl;

    return 0;
}
