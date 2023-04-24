#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); ++i)
        {
            people.push_back({ heights[i], names[i] });
        }
        sort(people.begin(), people.end());
        vector<string> res;
        for (int i = people.size() - 1; i > -1; i--)
        {
            res.push_back(people[i].second);
        }
        return res;
    }
};
int main()
{
    vector<string> names = { "Mary","John","Emma"};
    vector<int> heights = { 180, 165, 170 };
    Solution s;
    vector<string> res = s.sortPeople(names, heights);
    for (auto& e : res)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}