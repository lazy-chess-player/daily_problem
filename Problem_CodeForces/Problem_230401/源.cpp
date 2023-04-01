//±©¡¶À„∑®

#include <iostream>
#include<cmath>
using namespace std;

int main()
{

    int a, b, c;
    int ans_a, ans_b, ans_c;

	int t;
	cin >> t;
	while (t--)
	{
        cin >> a >> b >> c;
        int ans = 100000000;
        for (int i = 1; i < 10001; i++)
        {
            for (int j = 1; j * i < 20001; j++)
            {
                for (int k = 1; i * j * k < 20001; k++)
                {

                    int sum = abs(i - a);
                    sum += abs(i * j - b);
                    sum += abs(i * j * k - c);
                    if (ans > sum)
                    {
                        ans = sum;
                        ans_a = i;
                        ans_b = i * j;
                        ans_c = i * j * k;
                    }
                }
            }
        }

        cout << ans << endl;
        cout << ans_a << " " << ans_b << " " << ans_c << endl;
	}
}