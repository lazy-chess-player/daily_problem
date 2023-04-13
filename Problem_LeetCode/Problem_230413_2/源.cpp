#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int n = numbers.size();
        int l = 0;
        int r = 1;
        while (r < n && numbers[l] + numbers[r] < target)
        {
            r++;
        }
        if (r == n)
            r--;
        while (l < r && numbers[l] + numbers[r] != target)
        {
            if (numbers[l] + numbers[r] > target)
            {
                r--;
            }
            if (numbers[l] + numbers[r] < target)
            {
                l++;
            }
        }
        return { l + 1,r + 1 };
    }
};

int main()
{
    Solution s;

    vector<int>test1 = { 5,25,75 };
    vector<int>ans1 = { 2,3 };
 
    vector<int>test2 = { 2,3,4,6};
    vector<int>ans2 = { 1,3 };

    vector<int>test3 = { -1,0 };
    vector<int>ans3 = { 1,2 };

    assert("Test1 Warning!" && ans1 == s.twoSum(test1, 100));
    assert("Test1 Warning!" && ans2 == s.twoSum(test2, 6));
    assert("Test1 Warning!" && ans3 == s.twoSum(test3,-1));

    cout << "All Past!" << endl;
    return 0;
}