#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        vector<int> ans = { 0 };
        for (auto& row : mat)
        {
            vector<int> temp;
            for (int x : ans)
            {
                for (int y : row)
                {
                    temp.push_back(x + y);
                }
            }
            sort(temp.begin(), temp.end());
            if (temp.size() > k)
                temp.resize(k);
            ans = move(temp);
        }
        return ans.back();
    }
};

void test()
{
    Solution s;
    vector<vector<int>> test1 = { {1,3,11 }, { 2,4,6 } };
    int k1 = 5;
    int ans1 = 7;
    if (s.kthSmallest(test1, k1) != ans1)
    {
        cout << "Test1 Warning!!!" << endl;
        return;
    }
    vector<vector<int>> test2 = { {1,3,11 }, { 2,4,6 } };
    int k2 = 9;
    int ans2 = 17;
    if (s.kthSmallest(test2, k2) != ans2)
    {
        cout << "Test2 Warning!!!" << endl;
        return;
    }
    vector<vector<int>> test3 = { {1,1,10 }, { 2,2,9 } };
    int k3 = 7;
    int ans3 = 12;
    if (s.kthSmallest(test3, k3) != ans3)
    {
        cout << "Test3 Warning!!!" << endl;
        return;
    }
    cout << "All Past!!!" << endl;
}

int main()
{
    test();
    return 0;
}