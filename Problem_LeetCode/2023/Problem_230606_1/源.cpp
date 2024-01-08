#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int n = grid[0].size();
        map<vector<int>, int> hmap;
        for (auto row : grid)
        {
            hmap[row]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> col;
            for (int j = 0; j < n; j++)
            {
                col.push_back(grid[j][i]);
            }
            if (hmap.find(col) != hmap.end())
            {
                ans += hmap[col];
            }
        }
        return ans;
    }
};