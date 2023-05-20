#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	char** cake = (char**)malloc(n * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			scanf_s("%c",&cake[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (cake[i][j] = 'C')
				cnt++;
		}
		if (cnt > 1)
		{
			int temp = 1;
			while (cnt)
			{
				temp *= cnt;
				cnt--;
			}
			ans += cnt / 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (cake[j][i] = 'C')
				cnt++;
		}
		if (cnt > 1)
		{
			int temp = 1;
			while (cnt)
			{
				temp *= cnt;
				cnt--;
			}
			ans += cnt / 2;
		}
	}
	printf("%d", ans);
	return 0;
}