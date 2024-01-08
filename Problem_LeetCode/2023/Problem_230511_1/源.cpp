#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Solution
{
public:
    bool queryString(string s, int n)
    {
        for (int i = n; i > 0; i--)
        {
            bitset<32> bit(i);
            string str1 = bit.to_string();
            string str2 = str1.substr(str1.find_first_not_of('0'));
            if (s.find(str2) == string::npos)
                return false;
        }
        return true;
    }
};