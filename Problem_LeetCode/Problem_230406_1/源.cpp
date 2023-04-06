#include <iostream>
#include <cassert>
using namespace std;

class Solution
{
public:
    string baseNeg2(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        string ans;
        while (n!=0)
        {
            if (n % -2 == 0)
                ans += "0";
            else
            {
                n -= 1; 
                ans += '1';
            }
            n /= -2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void Test()
{
    Solution s;
    assert("Test1 Warning!!!" && s.baseNeg2(2) == "110");
    assert("Test2 Warning!!!" && s.baseNeg2(3) == "111");
    assert("Test3 Warning!!!" && s.baseNeg2(4) == "100");
    cout << "All Past!" << endl;
}

int main()
{
    Test();
    return 0;
}