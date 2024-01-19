class Solution
{
public:
    int minimumTime(vector<int> &nums1, vector<int> &nums2, int x) {
        int n = nums1.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](const int i, const int j) {return nums2[i] < nums2[j];});

        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) 
        {
            int a = nums1[ids[i]], b = nums2[ids[i]];
            for (int j = i + 1; j; j--) 
            {
                f[j] = max(f[j], f[j - 1] + a + b * j);
            }
        }

        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int t = 0; t <= n; t++) 
        {
            if (s1 + s2 * t - f[t] <= x)
                return t;
        }
        return -1;
    }
};