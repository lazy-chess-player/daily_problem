#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        int len = words.size();
        int n = queries.size();
        vector<int> s(len + 1, 0);
        vector<int>ans(n);
        for (int i = 0; i < len; i++)
        {
            s[i + 1] = s[i] + (int)(vowels.count(words[i][0]) && vowels.count(words[i].back()));
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = s[queries[i][1] + 1] - s[queries[i][0]];
        }
        return ans;
    }
};

int main()
{
    vector<string> words ={ "aba", "bcb", "ece", "aa", "e" };
    vector<vector<int>> queries = { {0, 2}, {1, 4}, {1, 1} };
    Solution s;
    vector<int> result = s.vowelStrings(words, queries);
    cout << "²éÑ¯½á¹û£º";
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}