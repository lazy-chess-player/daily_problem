#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
    {
        int ans = 0,id = 0;
        int cnt = 0;
        int money = 0;
        int last = 0;
        int x = 0;
        int n = customers.size();
        for(int i=0;i<n;i++)
        {
            cnt += customers[i];
            if(cnt >= 4) 
            {
                cnt -= 4;
                money += boardingCost * 4;
            }
            else 
            {
                money += boardingCost * cnt;
                cnt = 0;
            }
            x ++;
            money -= runningCost;
            if(money > ans) 
            {
                ans = money;
                id = x;
            }
        }
        while(cnt) 
        {
            if(cnt >= 4) 
            {
                cnt -= 4;
                money += boardingCost * 4;
            }
            else 
            {
                money += boardingCost * cnt;
                cnt = 0;
            }
            money -= runningCost;
            x ++;
            if(money > ans) 
            {
                ans = money;
                id = x;
            }
        }
        if(ans > 0) 
            return id;
        else 
            return -1;
    }
};

int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x=0;
    int y=0;
    cin>>x>>y;
    Solution s;
    int ans=s.minOperationsMaxProfit(arr,x,y);
    cout<<ans<<endl;
    return 0;
}