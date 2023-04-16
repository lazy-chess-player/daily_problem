#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1_map[27] = { 0 };
        int s2_map[27] = { 0 };
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2)
            return false;
        for (int i = 0; i < n1; i++)
        {
            s1_map[s1[i] - 'a']++;
            s2_map[s2[i] - 'a']++;
        }
        int l = 0, r = n1 - 1;
        while (r < n2)
        {
            if (memcmp(s1_map, s2_map, sizeof(s1_map)) == 0)
                return true;
            s2_map[s2[l] - 'a']--;
            l++;
            r++;
            if (r == n2)
                break;
            s2_map[s2[r] - 'a']++;
        }
        return false;
    }
};

void test()
{
    Solution s;

    string s1 = "ab";
    string s2 = "eidbaooo";

    if (s.checkInclusion(s1, s2))
        cout << "Test1 Past!" << endl;

}

int main()
{
    test();
    return 0;
}