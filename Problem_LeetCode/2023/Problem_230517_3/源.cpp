#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    int search(vector<int>& nums, int target)
    {
        int pos = findMin(nums);
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int realMid = (mid + pos) % nums.size();
            if (nums[realMid] == target)
                return realMid;
            else if (nums[realMid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};



void test()
{
}


int main()
{
    test();
    return 0;
}