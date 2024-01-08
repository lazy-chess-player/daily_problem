#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution
{
public:
    int mostFrequentEven(vector<int>& nums)
    {
        int hash_map[50001] = { 0 };
        bool isOdd = true;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (!(nums[i] % 2))
            {
                isOdd = false;
                hash_map[nums[i] / 2]++;
            }
        }
        if (isOdd)
        {
            return -1;
        }
        int mx = 0;
        int ans = 0;
        for (int i = 0; i < 50001; i++)
        {
            if (hash_map[i])
            {
                if (hash_map[i] > mx)
                {
                    mx = hash_map[i];
                    ans = i * 2;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    
    vector<int>test1 = { 0,1,2,2,4,4,1 };
    int ans1 = 2;

    vector<int>test2 = { 4,4,4,9,2,4 };
    int ans2 = 4;

    vector<int>test3 = { 29,47,21,41,13,37,25,7 };
    int ans3 = -1;

    assert("Test1 Warning!" && ans1 == s.mostFrequentEven(test1));
    assert("Test1 Warning!" && ans2 == s.mostFrequentEven(test2));
    assert("Test1 Warning!" && ans3 == s.mostFrequentEven(test3));

    cout << "All Past!" << endl;
    return 0;
}