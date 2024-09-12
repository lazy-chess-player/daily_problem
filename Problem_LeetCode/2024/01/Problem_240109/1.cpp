#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) 
    {
        unordered_set<string> set(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) 
        {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j <= i; j++)
            {
                if (set.count(s.substr(j, i - j + 1))) 
                {
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> dictionary(n);
    for(int i=0;i<n;i++)
    {
        cin>>dictionary[i];
    }
    int ans=sol.minExtraChar(s,dictionary);
    cout<<ans<<endl;
    return 0;
}