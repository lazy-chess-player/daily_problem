
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        int ans = 0;                     // 记录特殊整数的数量
        int len = to_string(n).length(); // 获取n的位数

        // 计算位数少于len的特殊整数
        for (int i = 1; i < len; i++)
        {
            int cnt = 9; // 第一位可以是1-9中的任意数字
            int can = 9; // 剩余可用的数字是0-9中去掉第一位后的数字

            for (int j = 1; j < i; j++)
            {
                cnt *= can; // 当前位可以选择的数字
                can--;      // 减少可用数字
            }
            ans += cnt; // 累加特殊整数的数量
        }

        // 处理位数等于len的特殊整数
        map<int, int> used; // 用于记录已经使用的数字
        for (int i = 0; i < len; i++)
        {
            int cur = (n / (int)pow(10, len - 1 - i)) % 10; // 获取当前位数字

            // 处理当前位之前的数字
            for (int j = (i == 0 ? 1 : 0); j < cur; j++)
            {
                if (used.count(j) == 0)
                {                    // 如果这个数字没有被使用
                    int cnt = 1;     // 当前位置的选择
                    int can = 9 - i; // 剩余可用数字

                    for (int k = len - i - 1; k > 0; k--)
                    {
                        cnt *= can; // 计算后续位的选择
                        can--;      // 减少可用数字
                    }
                    ans += cnt; // 累加特殊整数的数量
                }
            }

            // 如果当前位数字已经被使用，结束循环
            if (used.count(cur))
                break;
            used[cur]; // 插入当前位数字

            // 如果当前位是0，后面的数字无法继续构造特殊整数
            if (i == 0 && cur == 0)
                break;
        }

        // 处理n本身是否为特殊整数
        if (used.size() == len)
            ans++; // 如果n是特殊的，计入

        return ans;
    }
};