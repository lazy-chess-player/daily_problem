#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit)
    {
        int n = values.size();
        vector<pair<int, int>> object;
        for (int i = 0; i < n; i++)
        {
            object.push_back({ values[i],labels[i] });
        }
        sort(object.begin(), object.end(),greater<pair<int,int>>());
        unordered_map<int, int> hmap;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n && cnt < numWanted; i++)
        {
            if (hmap[object[i].second] < useLimit)
            {
                ans += object[i].first;
                hmap[object[i].second]++;
                cnt++;
            }
        }
        return ans;
    }
};

void test_largestValsFromLabels()
{
    vector<int> values = { 5,4,3,2,1 };
    vector<int> labels = { 1,1,2,2,3 };
    int num_wanted = 3;
    int use_limit = 1;
    int expected_output = 9;
    Solution s;
    assert("Test1 Warning!!!" && s.largestValsFromLabels(values, labels, num_wanted, use_limit) == expected_output);

    values = { 5,4,3,2,1 };
    labels = { 1,3,3,3,2 };
    num_wanted = 3;
    use_limit = 2;
    expected_output = 12;
    assert("Test2 Warning!!!" && s.largestValsFromLabels(values, labels, num_wanted, use_limit) == expected_output);

    values = { 9,8,8,7,6 };
    labels = { 0,0,0,1,1 };
    num_wanted = 3;
    use_limit = 1;
    expected_output = 16;
    assert("Test3 Warning!!!" && s.largestValsFromLabels(values, labels, num_wanted, use_limit) == expected_output);

    cout << "ALL PAST!!!" << endl;
}

int main()
{
    test_largestValsFromLabels();
    return 0;
}