#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Solution
{
public:
    bool checkDistances(string s, vector<int>& distance)
    {
        int cmap[26] = { 0 };
        int nmap[26] = { 0 };
        int n = s.length();
        for (int i = 0; i < n; i++)
        {

            if (cmap[s[i] - 'a'])
            {
                cmap[s[i] - 'a'] = i - cmap[s[i] - 'a'];
            }
            else
            {
                cmap[s[i] - 'a'] = i + 1;
                nmap[s[i] - 'a'] = distance[s[i]-'a'];
            }
        }
        if (memcmp(cmap, nmap, sizeof(int) * 26))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};