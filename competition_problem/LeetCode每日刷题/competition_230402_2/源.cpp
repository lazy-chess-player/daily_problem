#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool if_is(int m,int d,int y)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d < 32)
            return true;
    }
    else if (m == 2)
    {
        if (d < 30 && y % 4 == 0)
            return true;
        else if(d < 29 && y)
            return true;
    }
    else if(m<13)
    {
        if (d < 31)
            return true;
    }
    return false;
}

int main()
{
    char str[9] = { 0 };
    cin.getline(str, 9);
    int m = (str[0] - 48) * 10 + (str[1] - 48);
    int d = (str[3] - 48) * 10 + (str[4] - 48);
    int y = (str[6] - 48) * 10 + (str[7] - 48);

    bool mod1 = if_is(m, d, y);
    bool mod2 = if_is(d, m, y);

    if (mod1 && mod2)
    {
        cout << "BOTH" << endl;
        return 0;
    }
    else if(mod1)
    {
        cout << "MMDDYY" << endl;
    }
    else if(mod2)
    {
        cout << "DDMMYY" << endl;
    }
    else
    {
        cout << "NOTHING" << endl;
    }

    return 0;
}