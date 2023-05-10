#include <unordered_set>

using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        unordered_set<int> seen;
        int x = 1 % k;
        while (x && !seen.count(x))
        {
            seen.insert(x);
            x = (x * 10 + 1) % k;
        }
        return x ? -1 : seen.size() + 1;
    }
};