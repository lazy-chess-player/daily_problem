#include <string>

using namespace std;

class Solution
{
public:
    int countTime(string time)
    {
        int hour = 1;
        if (time[0] == '?' && time[1] == '?')
            hour = 24;
        else if (time[0] == '?' && time[1] != '?')
            hour = 2 + (time[1] - '0' < 4 ? 1 : 0);
        else if (time[0] != '?' && time[1] == '?')
            hour = 10 - (time[0] - '0' < 2 ? 0 : 6);

        return hour * (time[3] == '?' ? 6 : 1) * (time[4] == '?' ? 10 : 1);
    }
};