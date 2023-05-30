#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int mctFromLeafValues(vector<int>& arr)
    {
        int ans = 0;
        int pos = 0;
        while (arr.size() > 1)
        {
            int mn = INT_MAX;
            for (int i = 0; i < arr.size() - 1; i++)
            {
                if (mn > arr[i] * arr[i + 1])
                {
                    mn = arr[i] * arr[i + 1];
                    pos = arr[i] < arr[i + 1] ? i : i + 1;
                }
            }
            ans += mn;
            arr.erase(arr.begin() + pos);
        }
        return ans;
    }
};

void testMCTFromLeafValues()
{
    vector<vector<int>> testCases =
    {
        {6, 2, 4},      // 示例 1
        {4, 11},        // 示例 2
        {5, 1, 7, 3, 9}, // 自定义测试用例 1
        {3, 4, 2, 1},    // 自定义测试用例 2
        {10, 8, 6, 4, 2} // 自定义测试用例 3
    };

    Solution s;
    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "测试用例 " << i + 1 << ":" << endl;
        vector<int> arr = testCases[i];
        int result = s.mctFromLeafValues(arr);
        cout << "数组：";
        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "最小可能总和：" << result << endl;
        cout << endl;
    }
}

int main()
{
    testMCTFromLeafValues();
    return 0;
}
