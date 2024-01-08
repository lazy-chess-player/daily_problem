#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<cstdlib>
#include<string>

using namespace std;

class Solution {
public:
    int longestDecomposition(string text)
    {
        int n = text.length();
        int ans = 0;
        while (n > 0)
        {
            int l = 1;
            int r = n - 1;
            while (l <= r && (text.substr(0,l) != text.substr(r,n)))
            {
                l++;
                r--;
            }
            if (l > r)
            {
                ans++;
                break;
            }
            ans += 2;
            text = text.substr(l, r - l);
            n -= l * 2;
        }
        return ans;
    }
};

int main()
{
    Solution s;


    string test1 = "ghiabcdefhelloadamhelloabcdefghi";
    int ans1 = 7;

    string test2 = "elvtoelvto";
    int ans2 = 2;

    string test3 = "antaprezatepzapreanta";
    int ans3 = 11;

    assert("Test2 Warning!!!" && ans2 == s.longestDecomposition(test2));
    assert("Test3 Warning!!!" && ans3 == s.longestDecomposition(test3));
    assert("Test1 Warning!!!" && ans1 == s.longestDecomposition(test1));



    std::cout << "All Past!" << endl;

    return 0;
}