#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int bad_version = 4;

bool isBadVersion(int version)
{
    if (version >= bad_version)
        return true;
    return false;
};



class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 1;
        int r = n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    Solution s;

    int test1 = 5;
    bad_version = 4;

    assert("Test1 Warning!" && bad_version == s.firstBadVersion(test1));

    int test2 = 1;
    bad_version = 1;

    assert("Test2 Warning!" && bad_version == s.firstBadVersion(test2));

    std::cout << "All Past!" << endl;

    return 0;
}