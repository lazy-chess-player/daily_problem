#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        stack<char> stk;
        for (int i = 0; i < n; i++)
        {
            if (!stk.size())
            {
                if (s[i] == 'a')
                    stk.push(s[i]);
                else
                    return false;
            }
            else
            {
                if (s[i] > stk.top() + 1)
                    return false;
                else
                {
                    if (s[i] == stk.top() + 1 && s[i] == 'c')
                    {
                        stk.pop();
                        stk.pop();
                    }
                    else
                        stk.push(s[i]);
                }
            }
        }
        if (stk.size())
            return false;
        else
            return true;
    }
};

void testIsValid() {
    Solution sol;
    string s1 = "aabcbc";
    cout << "s1 is valid: " << boolalpha << sol.isValid(s1) << endl;

    string s2 = "abcabcababcc";
    cout << "s2 is valid: " << boolalpha << sol.isValid(s2) << endl;

    string s3 = "abccba";
    cout << "s3 is valid: " << boolalpha << sol.isValid(s3) << endl;
}

int main()
{
    testIsValid();
    return 0;
}
