class Solution {
public:
    int splitArray(vector<int> &nums, int k) 
    {
        auto check = [&](int mx) -> bool 
        {
            int cnt = 1, s = 0;
            for (int x : nums) 
            {
                if (s + x <= mx) 
                    s += x;
                else 
                {
                    if (cnt++ == k) 
                        return false;
                    s = x;
                }
            }
            return true;
        };

        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = max(*ranges::max_element(nums) - 1, (right - 1) / k);
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};