#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        sort(words.begin(), words.end(), [](const auto& a, const auto& b) {return a.length() < b.length(); });
        int ans = 0;
        unordered_map<string, int> f;
        for (auto& s : words)
        {
            int res = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                auto it = f.find(s.substr(0, i) + s.substr(i + 1));
                if (it != f.end())
                    res = max(res, it->second);
            }
            ans = max(ans, f[s] = res + 1);
        }
        return ans;
    }
};

void test()
{
    Solution s;
    
    vector<string> test1{ "a","b","ba","bca","bda","bdca" };
    int ans1 = 4;

    if(ans1==s.longestStrChain(test1))
        cout<<"Test1 Past!"<<endl;

    vector<string> test2{ "xbc","pcxbcf","xb","cxbc","pcxbc" };
    int ans2 = 5;

    if(ans2==s.longestStrChain(test2))
        cout<<"Test2 Past!"<<endl;

    vector<string> test3{ "abcd","dbqca" };
    int ans3 = 1;

    if(ans3==s.longestStrChain(test3))
        cout<<"Test3 Past!"<<endl;
}

int main()
{
	test();
	return 0;
}