#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <istream>

using namespace std;

void pb_a()
{
	int n = 0, k = 0;
	cin >> n >> k;
	string str(n, 0);
	cin >> str;
	string mode = { 'y', 'k', 'a', 'w', 'i' };

}

//void pb_b()
//{
//	string str;
//	cin >> str;
//	for (char ch:str)
//	{
//		if (islower(ch))
//			printf("%c ", toupper(ch));
//		else
//			printf("%c ", tolower(ch));
//	}
//}


void pb_c()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		double total_weight = 0.0;
		double total_value = 0.0;
		//double things[n][2];
		double things[7][2];
		vector<int> hmap(n);
		double ans = 0;
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			double temp = 0.0;
			cin >> things[i][0] >> things[i][1];
			temp = things[i][1] / things[i][0];
			if (temp > ans)
			{
				ans = temp;
				pos = i;
			}
		}
		total_weight = things[pos][0];
		total_value = things[pos][1];
		hmap[pos]++;
		for (int j = 1; j < k; j++)
		{
			int p = 0;
			double temp = 0.0;
			for (int i = 0; i < n; i++)
			{
				if (!hmap[i])
				{
					if ((total_value + things[i][1]) / (total_weight + things[i][0]) > temp)
					{
						temp = (total_value + things[i][1]) / (total_weight + things[i][0]);
						p = i;
					}
				}
			}
			ans = temp;
			hmap[p]++;
		}
		printf("%.2lf\n", ans);
	}
}

void pb_e()
{
	vector<double> arr1(13);
	vector<double> arr2(13);
	vector<double> arr3(13);
	for (int i = 0; i < 12; i++)
	{
		double temp = 0.0;
		cin >> temp;
		arr1[i] = 1 - temp;
	}
	for (int i = 0; i < 12; i++)
	{
		double temp = 0.0;
		cin >> temp;
		arr2[i] = 1 - temp;
	}
	for (int i = 0; i < 12; i++)
	{
		double temp = 0.0;
		cin >> temp;
		arr3[i] = 1 - temp;
	}
	for (int i = 0; i < 13; i++)
	{
		printf("%.6lf\n", 1 - arr1[i] * arr2[i] * arr3[i]);
	}
}


//void pb_f()
//{
//	int n = 1000;
//	while (n--)
//	{
//		string str;
//		cin >> str;
//		int n = str.length();
//		int ans = 1;
//		if (!n)
//			break;
//		if (n == 1)
//		{
//			cout << ans;
//			continue;
//		}
//		if (n == 2)
//		{
//			cout << ans + (str[0] == str[2] ? 1 : 0);
//			continue;
//		}
//		for (int i = 1; i < n-1; i++)
//		{
//			int cnt = 1;
//			if (str[i + 1] == str[i - 1])
//			{
//				cnt += 2;
//				int l = i - 2, r = i + 2;
//				while (l >= 0 && r < n)
//				{
//					if (str[l] == str[r])
//						cnt += 2;
//					else
//						break;
//					l--;
//					r++;
//				}
//			}
//			else if (str[i] == str[i - 1])
//			{
//				cnt += 1;
//				int l = i - 2, r = i + 1;
//				while (l >= 0 && r < n)
//				{
//					if (str[l] == str[r])
//						cnt += 2;
//					else
//						break;
//					l--;
//					r++;
//				}
//			}
//			ans = max(ans, cnt);
//		}
//		cout << ans << endl;
//	}
//}
//
//void pb_h()
//{
//	int n = 0;
//	cin >> n;
//	char cake[n][n];
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> cake[i][j];
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int cnt = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (cake[i][j] == 'C')
//				cnt++;
//		}
//		if (cnt > 1)
//		{
//			int temp = 1;
//			while (cnt)
//			{
//				temp *= cnt;
//				cnt--;
//			}
//			ans += temp / 2;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int cnt = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (cake[j][i] == 'C')
//				cnt++;
//		}
//		if (cnt > 1)
//		{
//			int temp = 1;
//			while (cnt)
//			{
//				temp *= cnt;
//				cnt--;
//			}
//			ans += temp / 2;
//		}
//	}
//	cout << ans;
//}

//void pb_i()
//{
//	int n = 8;
//	char num = '\0';
//	int cnt = 0;;
//	while (n--)
//	{
//		cin >> num;
//		if (num - '0')
//			cnt++;
//	}
//	cout << cnt;
//}

void pb_j()
{
	int n = 0;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strs[i];
	}

}

int main()
{
	pb_c();
	return 0;
}