class Solution 
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points) 
    {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto &p1 : points) 
        {
            cnt.clear();
            for (auto &p2 : points) 
            {
                int d2 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                ans += cnt[d2]++ * 2;
            }
        }
        return ans;
    }
};