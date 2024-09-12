#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int minLength(string s) 
    {
        vector<int> st;
        for (char& c : s) 
        {
            st.push_back(c);
            int n = st.size();
            if(n<2)
                continue;
            if (st[n - 2] == 'A' && st[n - 1] == 'B' ||st[n - 2] == 'C' && st[n - 1] == 'D')
            {
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};

int main()
{
    Solution sol;
    string s;
    cin>>s;
    int ans=sol.minLength(s);
    cout<<ans<<endl;
    return 0;
}