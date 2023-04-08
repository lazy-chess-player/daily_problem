#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
    {
        unordered_map<string, int> sid;
        int m = req_skills.size();
        for (int i = 0; i < m; ++i)
            sid[req_skills[i]] = i;

        int n = people.size(), mask[n];
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < n; ++i)
        {
            for (auto& s : people[i])
            {
                mask[i] |= 1 << sid[s];
            }
        }

        int u = 1 << m;
        long long ids[u];
        memset(ids, 0, sizeof(ids));
        char f[u];
        memset(f, 0x7f, sizeof(f));
        f[0] = 0;
        for (int j = 0; j < u - 1; ++j)
        {
            if (f[j] < 0x7f)
            {
                for (int i = 0; i < n; ++i)
                {
                    if (f[j] + 1 < f[j | mask[i]])
                    {
                        f[j | mask[i]] = f[j] + 1;
                        ids[j | mask[i]] = ids[j] | (1LL << i);
                    }
                }
            }
        }
        auto res = ids[u - 1];

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if ((res >> i) & 1)
                ans.push_back(i);
        }
        return ans;
    }
};