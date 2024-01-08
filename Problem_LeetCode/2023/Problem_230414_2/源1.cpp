#include<iostream>
#include<string>

using namespace std;

class Solution
{
public:
    void reverseString(string& s, int l, int r)
    {
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
    string reverseWords(string s)
    {
        int n = s.length();
        for (int i = 0; i < n;)
        {
            int l = i;
            while (i < n && s[i] != ' ')
            {
                i++;
            }
            int r = i - 1;
            reverseString(s, l, r);
            while (i < n && s[i] == ' ')
            {
                i++;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;

    string test1 = "Let's take LeetCode contest";

    cout<<s.reverseWords(test1) << endl;

    return 0;
}