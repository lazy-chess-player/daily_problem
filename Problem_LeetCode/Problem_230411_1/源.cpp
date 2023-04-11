#include<iostream>
#include<string>

using namespace std;

enum direction
{
    east, south, west, north
};

class Substance
{
public:
    direction d;
    int location[2];
    Substance()
    {
        d = north;
        location[0] = 0;
        location[1] = 0;
    }
};

enum commond
{
    G, L, R
};

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        Substance s1;
        int len = instructions.length();
        for (int i = 0; i < len; i++)
        {
            switch (instructions[i])
            {
            case 'G':
                if (s1.d % 2)
                    s1.location[1] += (s1.d - 2);
                else
                    s1.location[0] += (1 - s1.d);
                break;
            case 'L':
                s1.d = (direction)((s1.d + 1) % 4);
                break;
            case 'R':
                s1.d = (direction)((s1.d + 3) % 4);
                break;
            }
        }
        if ((s1.location[0] || s1.location[1]) && s1.d == 3)
            return false;
        return true;
    }
};

int main() {
    // 创建一个解决方案对象
    Solution s;
    // 定义三个测试用例
    string test1 = "RGL";
    string test2 = "GG";
    string test3 = "GLRLLGLL";
    // 调用函数并输出结果
    cout << "Input: " << test1 << endl;
    string ans1 = s.isRobotBounded(test1) ? "true" : "fasle";
    string ans2 = s.isRobotBounded(test2) ? "true" : "fasle";
    string ans3 = s.isRobotBounded(test3) ? "true" : "fasle";
    cout << "Output: " << ans1 << endl;
    cout << "Input: " << test2 << endl;
    cout << "Output: " << ans2 << endl;
    cout << "Input: " << test3 << endl;
    cout << "Output: " << ans3 << endl;
    return 0;
}