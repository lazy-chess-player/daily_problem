#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int left = -1;
        int right = nums.size() - 1;
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums.back())
                right = mid;
            else
                left = mid;
        }
        return nums[right];
    }
};