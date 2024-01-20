#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) 
    {
        vector<string> ans;
        for(auto word:words)
        {
            int n=word.size();
            int i=0;
            while(i<n)
            {
                if(word[i]==separator)
                {
                    i++;
                    continue;
                }
                int start=i;
                i++;
                while (i<n&&word[i]!=separator)
                {
                    i++;
                }
                ans.push_back(word.substr(start,i-start));
            }   
            i++;
        }
        return ans;
    }
};