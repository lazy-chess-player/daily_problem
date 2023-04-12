#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cstdlib>

using namespace std;

void DoubleAxisQsort(vector<int>& nums, int start, int end)
{
    if (start > end)
        return;
    if (nums[start] > nums[end])
        swap(nums[start], nums[end]);
    int temps = nums[start];
    int tempe = nums[end];
    int left = start;
    int right = end;
    int i = left + 1;
    while (i < right)
    {
        if (nums[i] < temps)
        {
            swap(nums[++left], nums[i++]);
        }
        else if (nums[i]<=tempe)
        {
            i++;
        }
        else
        {
            while (nums[right]>tempe)
            {
                if (right-- == i)
                    break;
            }
            if (i >= right)
                break;
            swap(nums[i], nums[right]);
        }
    }
    swap(nums[start], nums[left]);
    swap(nums[end], nums[right]);
    DoubleAxisQsort(nums, start, left - 1);
    DoubleAxisQsort(nums, left+1, right - 1);
    DoubleAxisQsort(nums, right + 1, end);
}

class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        if (!n)
            return nums;
        for (int i = 0; i < n; i++)
        {
            nums[i] *= nums[i];
        }
        DoubleAxisQsort(nums, 0, n - 1);
        return nums;
    }
};


int main()
{
    Solution s;

    vector<int> test1 = { -4,-1,0,3,10 };
    vector<int> ans1 = { 0,1,9,16,100 };

    assert("Test1 Warning!" && ans1 == s.sortedSquares(test1));

    vector<int> test2 = { -7,-3,2,3,11 };
    vector<int> ans2 = { 4,9,9,49,121 };

    assert("Test2 Warning!" && ans2 == s.sortedSquares(test2));

    std::cout << "All Past!" << endl;

    return 0;
}