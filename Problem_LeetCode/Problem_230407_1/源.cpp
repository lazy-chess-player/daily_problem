#include <iostream>
#include <vector>
#include<cassert>
#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<int> numMovesStonesII(vector<int>& stones)
    {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int mx = stones[n - 1] - stones[0] + 1 - n - min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);
        int mn = n;
        for (int l = 0,r = 0; l < n && r + 1 < n; ++l)
        {
            while (r + 1 < n && stones[r + 1] - stones[l] + 1 <= n)
            {
                ++r;
            }
            if ( r - l + 1 == n - 1 && stones[r] - stones[l] + 1 == n - 1)
            {
                mn = min(mn, 2);
            }
            else
            {
             mn = min(mn, n - (r - l + 1));
            }

        }
        return vector<int>{mn, mx};
    }
};


void Test()
{
    Solution s;
    vector<int>test1{ 7,4,9 };
    vector<int>ans1{ 1,2 };
    vector<int>test2{ 6,5,4,3,10 };
    vector<int>ans2{ 2,3 };
    vector<int>test3{ 100,101,104,102,103 };
    vector<int>ans3{ 0,0 };
    assert("Test1 Warning!!!" && s.numMovesStonesII(test1) == ans1);
    assert("Test2 Warning!!!" && s.numMovesStonesII(test2) == ans2);
    assert("Test3 Warning!!!" && s.numMovesStonesII(test3) == ans3);
    cout << "All Past!" << endl;
}

int main()
{
    Test();
    return 0;
}