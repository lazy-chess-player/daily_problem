#include<vector>
#include<iostream>

using namespace std;
//´«Í³¿ìÅÅ
class Solution
{
public:
    void quickSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return;
        bool sorted = true;
        for (int i = left; i < right; i++)
        {
            if (nums[i] > nums[i + 1])
                sorted = false;;
        }
        if (sorted)
            return;
        int poit1 = nums[left];
        int poit2 = nums[right];
        if (poit1 > poit2)
            swap(nums[left], nums[right]);
        int i = left + 1, j = left + 1, k = right - 1;
        while (j <= k)
        {
            if (nums[j] < poit1)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if (nums[j] >= poit1 && nums[j] <= poit2)
            {
                j++;
            }
            else
            {
                swap(nums[j], nums[k]);
                k--;
            }
        }
        if (i == j)
        {
            swap(nums[right], nums[j]);
            quickSort(nums, left, k);
            quickSort(nums, j + 1, right);
        }
        else
        {
            swap(nums[left], nums[i - 1]);
            swap(nums[right], nums[k + 1]);
            quickSort(nums, left, i - 2);
            quickSort(nums, i, k);
            quickSort(nums, j + 1, right);
        }
    }
    vector<int> sortArray(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
int main()
{
	Solution s;
    vector<int> nums = { 5,2,3,1 };
    vector<int> arr = s.sortArray(nums);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}