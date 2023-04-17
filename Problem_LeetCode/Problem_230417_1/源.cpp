#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
public:
    int calculateDaysOfYear(string day, vector<int>& preSum)
    {
        int m = stoi(day.substr(0, 2));
        int d = stoi(day.substr(3));
        return preSum[m - 1] + d;
    }

    int countDaysTogether(string A_Arrive, string A_Leave, string B_Arrive, string B_Leave)
    {
        vector<int> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        vector<int> preSum(1, 0);
        for (auto& day : days) {
            preSum.emplace_back(preSum.back() + day);
        }
        int A_ArriveDay = calculateDaysOfYear(A_Arrive, preSum);
        int A_LeaveDay = calculateDaysOfYear(A_Leave, preSum);
        int B_ArriveDay = calculateDaysOfYear(B_Arrive, preSum);
        int B_LeaveDay = calculateDaysOfYear(B_Leave, preSum);
        return max(0, min(A_LeaveDay, B_LeaveDay) - max(A_ArriveDay, B_ArriveDay) + 1);
    }
};