#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string>& words)
    {
        unordered_map<string,int> strmap;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            strmap[words[i]]=i;
        }
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            string temp=words[j];
            reverse(temp.begin(), temp.end());
            if(strmap[temp]>j)
            {
                cnt++;
                strmap[temp]=-1;
            }
        }
        return cnt;
    }
};