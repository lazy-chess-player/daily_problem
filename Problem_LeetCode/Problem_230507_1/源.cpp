#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        vector<int> dp(60);
        int ans = 0;
        for (int t : time)
        {
            ans += dp[(60 - t % 60) % 60];
            ++dp[t % 60];
        }
        return ans;
    }
};

void test()
{
    Solution s;
    vector<int> time1 = { 30,20,150,100,40 };
    vector<int> time2 = { 269,230,318,468,171,158,350,60,287,27,11,384,332,267,412,478,280,303,242,378,129,131,164,467,345,146,264,332,276,479,284,433,117,197,430,203,100,280,145,287,91,157,5,475,288,146,370,199,81,428,278,2,400,23,470,242,411,470,330,144,189,204,62,318,475,24,457,83,204,322,250,478,186,467,350,171,119,245,399,112,252,201,324,317,293,44,295,14,379,382,137,280,265,78,38,323,347,499,238,110,18,224,473,289,198,106,256,279,275,349,210,498,201,175,472,461,116,144,9,221,473 };

    cout << s.numPairsDivisibleBy60(time1) << endl; // Êä³ö 3
    cout << s.numPairsDivisibleBy60(time2) << endl; // Êä³ö 105
}

int main()
{
    test();
    return 0;
}