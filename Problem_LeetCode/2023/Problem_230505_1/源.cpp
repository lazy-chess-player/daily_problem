#include <iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int hardestWorker(int n, vector<vector<int>>& logs)
    {
        vector<int> workers(n);
        workers[logs[0][0]] = logs[0][1];
        for (int i = 1; i < logs.size(); i++)
        {
            workers[logs[i][0]] = max(workers[logs[i][0]], logs[i][1] - logs[i - 1][1]);
        }
        int ans = 0;
        int max_time = 0;
        for (int i = 0; i < n; i++)
        {
            if (workers[i] > max_time)
            {
                ans = i;
                max_time = workers[i];
            }
        }
        return ans;
    }
};