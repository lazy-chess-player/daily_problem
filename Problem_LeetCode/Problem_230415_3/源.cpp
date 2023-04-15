#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {
        vector<vector<int>> g(n); // 定义一个二维数组g，大小为n，用来存储每个花园与哪些花园相连
        for (auto& e : paths)// 遍历paths中的每个元素e，e是一个一维数组，表示一条路径
        {
            int x = e[0] - 1, y = e[1] - 1; // 定义两个整数x和y，分别表示路径的两个端点，因为题目中编号是从1开始，所以要减去1
            g[x].push_back(y); // 把y加入到g[x]中，表示x和y相连
            g[y].push_back(x); // 把x加入到g[y]中，表示y和x相连
        }
        vector<int> color(n); // 定义一个一维数组color，大小为n，用来存储每个花园的花的颜色
        for (int i = 0; i < n; ++i) // 遍历每个花园i
        {
            bool used[5]{}; // 定义一个bool数组used，大小为5，用来记录哪些颜色已经被i的相邻花园使用了，默认值为false
            for (int j : g[i]) // 遍历i的相邻花园j
            {
                used[color[j]] = true; // 把j的颜色对应的used数组中的值设为true，表示这种颜色已经被使用了
            }
            while (used[++color[i]]); // 从1开始递增i的颜色，直到找到一个没有被使用过的颜色
        }
        return color; // 返回color数组作为答案
    }
};
