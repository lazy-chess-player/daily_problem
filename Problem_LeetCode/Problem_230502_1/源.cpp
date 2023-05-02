#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        unordered_set<int> ans;
        int num1 = 1;
        for (int i = 0; i < 21; i++)
        {
            int num2 = 1;
            for (int j = 0; j < 21; j++)
            {
                if (num1 + num2 <= bound)
                    ans.emplace(num1 + num2);
                else
                    break;
                num2 *= y;
            }
            if (num1 > bound)
                break;
            num1 *= x;
        }
        return { ans.begin(),ans.end() };
    }
};