#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

class Solution 
{
public:
    vector<int> prevPermOpt1(vector<int>& arr)
    {
        int len = arr.size();
        for (int i = len - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                int j = len - 1; 
                for (; arr[j] >= arr[i] || arr[j] == arr[j - 1]; j--);
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};

void test_prevPermOpt1()
{
    Solution s;
    vector<int> t1{ 3, 2, 1 };
    vector<int> t2{ 1, 1, 5 };
    vector<int> t3{ 1, 9, 4, 6, 7 };
    vector<int> t4{ 3, 1, 1, 3 };
    bool if_AP = true;
    if (s.prevPermOpt1(t1) != vector<int>({ 3, 1, 2 }))
    {
        cout << "Test1 Wrong!" << endl;
        if_AP = false;
    }
    if (s.prevPermOpt1(t2) != vector<int>({ 1, 1, 5 }))
    {
        cout << "Test2 Wrong!" << endl;
        if_AP = false;
    }
    if(s.prevPermOpt1(t3) != vector<int>({1, 7, 4, 6, 9}))
    {
        cout << "Test3 Wrong!" << endl;
        if_AP = false;
    }
    if(s.prevPermOpt1(t4) != vector<int>({1, 3, 1, 3}))
    {
        cout << "Test4 Wrong!" << endl;
        if_AP = false;
    }
    if (if_AP)
    {
        cout << "All Pass!" << endl;
    }
}

int main()
{
    test_prevPermOpt1();
    return 0;
}