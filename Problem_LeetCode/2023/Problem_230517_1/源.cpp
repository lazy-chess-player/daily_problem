#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lower_bound(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left<=right)
        {
            int mid = left + (right - left);
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] > target)
            return { -1,-1 };
        int end = lower_bound(nums, target + 1);
        return { start,end };
    }
};


void test()
{
    Solution solution;

    // ²âÊÔÓÃÀı1
    vector<int> nums1 = { 5, 7, 7, 8, 8, 10 };
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "Test Case 1: ";
    for (int num : result1)
        cout << num << " ";
    cout << endl;

    // ²âÊÔÓÃÀı2
    vector<int> nums2 = { 5, 7, 7, 8, 8, 10 };
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "Test Case 2: ";
    for (int num : result2)
        cout << num << " ";
    cout << endl;

}


int main()
{
	test();
	return 0;
}