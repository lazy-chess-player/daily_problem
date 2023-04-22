#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int>& a)
    {
        const int n = a.size();
        int ans = 0, f[n][1001];
        memset(f, 0, sizeof(f));
        for (int i = 1; i < n; ++i)
            for (int j = i - 1; j >= 0; --j)
            {
                int d = a[i] - a[j] + 500;
                if (f[i][d] == 0)
                {
                    f[i][d] = f[j][d] + 1;
                    ans = max(ans, f[i][d]);
                }
            }
        return ans + 1;
    }
};


int main()
{
    vector<int> nums1 = { 3, 6, 9, 12 };
    vector<int> nums2 = { 9, 4, 7, 2, 10 };
    vector<int> nums3 = { 20, 1, 15, 3, 10, 5, 8 };
    Solution s;
    cout << s.longestArithSeqLength(nums2) << endl; // expected output: 3
    cout << s.longestArithSeqLength(nums1) << endl; // expected output: 4
    cout << s.longestArithSeqLength(nums3) << endl; // expected output: 4
    return 0;
}