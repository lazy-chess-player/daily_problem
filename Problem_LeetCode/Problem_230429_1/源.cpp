#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool equalFrequency(string word)
    {
        int Amap[26] = { 0 };
        for (char c : word)
        {
            Amap[c - 'a']++;
        }
        int mx = 0;
        int mn = 100;
        for (int i : Amap)
        {
            if (i)
            {
                mx = max(mx, i);
                mn = min(mn, i);
            }
        }
        int mxNum = 0;
        int mnNum = 0;
        int midNum = 0;
        for (int j : Amap)
        {
            if (j)
            {
                if (j == mx)
                    mxNum++;
                else if (j == mn)
                    mnNum++;
                else
                    midNum++;
            }
        }
        if (!midNum)
        {
            if (!mnNum)
            {
                if (mx == 1)
                    return true;
                else
                {
                    char ch = word[0];
                    for (char c : word)
                    {
                        if (ch == c)
                            ch = c;
                        else
                            return false;
                    }
                }
            }
            else
            {
                if (mn == 1 && mnNum == 1)
                    return true;
                if (abs(mx - mn) == 1 && mxNum == 1)
                    return true;
            }
        }
        return false;
    }
};

void test()
{
    Solution s;
    
    string test1{ "dd" };
    if (s.equalFrequency(test1))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main()
{
    test();
    return 0;
}