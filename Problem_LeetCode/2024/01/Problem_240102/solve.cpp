#include<vector>
#include<iostream>
#include<map>

using namespace std;

class Solution 
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int len1 = s1.size(), len2 = s2.size();
        vector<int> cnt;
        map<int, int> indexmap;
        int k = 0;
        for(int i = 0; i < n1; i++) 
        {
            for(int j = 0; j < len1; j++) 
            {
                if(s1[j] == s2[k % len2]) k++;
            }
            cnt.push_back(k);
            if(indexmap.count(k % len2)) 
            {
                int a = i - indexmap[k % len2], b = k - cnt[indexmap[k % len2]];
                int res = (n1 - i - 1) / a * b;
                for(int u = 0; u < (n1 - i - 1) % a; u++) 
                {
                    for(int j = 0; j < len1; j++) 
                    {
                        if(s1[j] == s2[k % len2])
                            k++;
                    }
                }
                res += k;
                return res / len2 / n2;
            }
            indexmap[k % len2] = i;
        }
        return k / len2 / n2;
    }
};


int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    int x=0;
    int y=0;
    cin>>x>>y;
    Solution s;
    int ans=s.getMaxRepetitions(s1,x,s2,y);
    cout<<ans<<endl;
    return 0;
}