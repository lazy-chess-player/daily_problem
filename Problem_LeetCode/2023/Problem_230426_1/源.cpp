#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
    {
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++)
        {
            s[i + 1] += (s[i] + nums[i]);
        }
        int sum = 0, maxA = 0, maxB = 0;
        for (int i = firstLen+secondLen; i <= n; i++)
        {
            maxA = max(maxA, s[i - secondLen] - s[i - secondLen - firstLen]);
            maxB = max(maxB, s[i - firstLen] - s[i - firstLen - secondLen]);
            sum = max(sum,max(maxA + s[i] - s[i - secondLen],maxB + s[i] - s[i - firstLen]));
        }
        return sum;
    }
};

void test()
{
    Solution s;
    vector<int> test1{ 0,6,5,2,2,5,1,9,4 };
    int ans1 = 20;
    if (ans1 == s.maxSumTwoNoOverlap(test1, 1, 2))
        cout << "test1 Past" << endl;
}

int main()
{
    test();
    return 0;
}
