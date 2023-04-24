#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string lastSubstring(string s)
    {
        int i = 0, j = 1;
        int n = s.size();
        while (j < n)
        {
            int k = 0;
            while (j + k < n && s[i + k] == s[j + k])
            {
                k++;
            }
            if (j + k < n && s[i + k] < s[j + k])
            {
                int t = i;
                i = j;
                j = max(j + 1, t + k + 1);
            }
            else
                j = j + k + 1;
        }
        return s.substr(i, n - i);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lastSubstring(s) << endl;
    return 0;
}
