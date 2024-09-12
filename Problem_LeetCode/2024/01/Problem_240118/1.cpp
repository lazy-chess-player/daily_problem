#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans)
    {
        long long n = beans.size();
        long long sum = 0;
        sort(beans.begin(),beans.end());
        for(int i=0;i<n;i++)
        {
            sum+=beans[i];
        }
        long long ans = INT64_MAX;
        for(long long i=0;i<n;i++)
        {
            ans=min(ans,sum-(n-i)*(long long)beans[i]);
        }
        return ans;
    }
};