#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int f(string s)
    {
        int cnt[26] = { 0 };
        for (char c : s)
        {
            cnt[c - 'a']++;
        }
        for (int x : cnt)
        {
            if (x)
                return x;
        }
        return 0;
    };
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        int n = words.size();
        vector<int>nums(n);
        for (int i = 0; i < n; i++)
        {
            nums[i] = f(words[i]);
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (auto& q : queries)
        {
            int x = f(q);
            ans.push_back(n - (upper_bound(nums.begin(), nums.end(), x) - nums.begin()));
        }
        return ans;
    }
};