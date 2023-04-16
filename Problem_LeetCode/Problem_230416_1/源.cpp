#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        if (len == 0)
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        int arr[128] = { 0 };
        while (j < len)
        {
            if (!arr[s[j]])
            {
                arr[s[j]]++;
                j++;
                sum++;
            }
            else
            {
                while (arr[s[j]])
                {
                    arr[s[i]]--;
                    i++;
                    sum--;
                }
            }
            ans = sum > ans ? sum : ans;
        }
        return ans;
    }
};