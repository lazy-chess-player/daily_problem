#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int> d(n + 1);
        for (int i = 1; i < n; i++)
        {
            int mx = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--)
            {
                d[i] = max(d[i], d[j] + mx * (i - j));
                if (j > 0)
                    mx = max(mx, arr[j - 1]);
            }
        }
        return d[n];
    }
};

void test()
{
    Solution s;
    vector<int> arr{ 1,15,7,9,2,5,10 };
    if (s.maxSumAfterPartitioning(arr, 3) == 83)
        cout << "All Past" << endl;
    else
        cout << "Warning" << endl;
}

int main()
{
    test();
    return 0;
}