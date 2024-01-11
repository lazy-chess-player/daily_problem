#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <map>


using namespace std;

class Solution {
public:
    int addMinimum(string word) 
    {
        int n=word.length();
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(word[i]<=word[i-1])
                cnt++;
        }
        return cnt*3-n;
    }
};

int main()
{
    Solution sol;
    string s;
    cin>>s;
    int ans=sol.addMinimum(s);
    cout<<ans<<endl;
    return 0;
}