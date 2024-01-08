#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> getdiffs(string& str)
    {
        vector<int> diffs(str.length() - 1);
        for (int i = 1; i < str.length(); i++)
        {
            diffs[i - 1] = str[i] - str[i - 1];
        }
        return diffs;
    }
    string oddString(vector<string>& words)
    {
        int n = words[0].length();
        
        vector<int> diff0 = getdiffs(words[0]);
        vector<int> diff1 = getdiffs(words[1]);

        if (diff0 == diff1)
        {
            for (int i = 2; i < words.size(); i++)
            {
                vector<int> diffs = getdiffs(words[i]);
                if (diffs != diff0)
                    return words[i];
            }
        }
        else
        {
            vector<int> diff2 = getdiffs(words[2]);
            return diff2 == diff1 ? words[0] : words[1];
        } 
    }
};

void test()
{
    Solution s;
    vector<string> test1 ={"adc", "wzy", "abc"};
    string ans1 = "abc";
    if (s.oddString(test1) != ans1)
    {
        cout << "Test1 Warning!!!" << endl;
        return;
    }
    vector<string> test2 ={ "aaa","bob","ccc","ddd" };
    string ans2 = "bob";
    if (s.oddString(test2) != ans2)
    {
        cout << "Test2 Warning!!!" << endl;
        return;
    }
    cout << "All Past!!!" << endl;
}

int main()
{
    test();
    return 0;
}