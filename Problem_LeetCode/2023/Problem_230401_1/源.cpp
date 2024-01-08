#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<regex>

using namespace std;

class Solution
{
public:
    vector<string> country = { "", "+*-", "+**-", "+***-" };

    string maskPII(string s)
    {
        string res;
        int at = s.find("@");
        if (at != string::npos)
        {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s.substr(0, 1) + "*****" + s.substr(at - 1);
        }
        s = regex_replace(s, regex("[^0-9]"), "");
        return country[s.size() - 10] + "***-***-" + s.substr(s.size() - 4);
    }
};


void testMaskPII()
{
    Solution s;
    assert(s.maskPII("LeetCode@LeetCode.com") == "l*****e@leetcode.com");
    assert(s.maskPII("AB@qq.com") == "a*****b@qq.com");
    assert(s.maskPII("86-(10)12345678") == "+**-***-***-5678");
}

int main()
{
    testMaskPII();
    return 0;
}