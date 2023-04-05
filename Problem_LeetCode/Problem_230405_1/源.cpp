#include<iostream>
#include<cassert>
#include<cmath>

using namespace std;

class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int cnt = 0;
        for (int i = 1; i <= min(a, b); i++)
        {
            cnt += ((a % i == 0 && b % i == 0) ? 1 : 0);
        }
        return cnt;
    }
};

void Test()
{
    Solution s;
    assert("Test1 Warning!!!" && 4 == s.commonFactors(12, 6));
    assert("Test2 Warning!!!" && 2 == s.commonFactors(25, 10));
    assert("Test3 Warning!!!" && 4 == s.commonFactors(32, 408));
    cout << "All Past!" << endl;
}

int main()
{
    Test();
    return 0;
}