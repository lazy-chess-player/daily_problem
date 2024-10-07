#include <bits/stdc++.h>
using namespace std;

// 定义常量最大节点数
const int MAXN = 3e5 + 5;

// 第二棵树的邻接表
vector<vector<int>> tree2(MAXN);
// 第一棵树的邻接表
vector<vector<int>> tree1(MAXN);

// in和out时间数组，用于第二棵树
int in2_time[MAXN];
int out2_time[MAXN];
int timer2;

// DFS函数，用于第二棵树，计算每个节点的入时间和出时间
void dfs2(int u, int parent)
{
    in2_time[u] = ++timer2;
    for (auto &v : tree2[u])
    {
        if (v != parent)
        {
            dfs2(v, u);
        }
    }
    out2_time[u] = timer2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // 清空第一棵树的邻接表
        for (int i = 1; i <= n; ++i)
        {
            tree1[i].clear();
        }
        // 读取第一棵树的边
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }

        // 清空第二棵树的邻接表
        for (int i = 1; i <= n; ++i)
        {
            tree2[i].clear();
        }
        // 读取第二棵树的边
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }

        // 重置计时器
        timer2 = 0;
        // 从根节点1开始对第二棵树进行DFS，计算in和out时间
        dfs2(1, -1);

        // 使用DFS遍历第一棵树，同时维护一个滑动窗口
        // 滑动窗口中维护当前路径上的节点，使得在第二棵树中这些节点互不祖孙
        // 使用有序集合按照第二棵树的in时间排序
        // 这样可以快速检查是否有节点的区间包含当前节点的区间
        // 从而维护S是第二棵树中的反链（antichain）

        // 定义最大集合大小
        int max_size = 0;
        // 定义滑动窗口的起始节点
        // 使用栈来模拟路径
        vector<int> path;
        // 定义有序集合，存储当前窗口中节点的in时间
        // 使用pair存储(in_time, out_time)
        set<pair<int, int>> window;

        // 使用DFS遍历第一棵树，同时维护滑动窗口
        // 定义一个辅助函数
        // 使用递归方式遍历第一棵树
        // 这里使用lambda表达式实现
        // 需要传递当前节点、父节点、当前窗口和路径等信息
        // 为了简化，使用全局变量或外部变量不太好
        // 因此改用显式的栈来模拟DFS

        // 使用显式栈进行DFS遍历
        // 栈中存储当前节点和它的父节点
        stack<pair<int, int>> stk;
        stk.emplace(1, -1);

        // 定义滑动窗口的左边界
        int left = 0;
        // 定义一个数组来存储路径上的节点
        vector<int> current_path;

        while (!stk.empty())
        {
            auto [u, parent] = stk.top();
            stk.pop();
            // 进入节点u
            current_path.push_back(u);
            // 插入u到窗口集合
            window.emplace(in2_time[u], out2_time[u]);

            // 检查是否有冲突
            // 在有序集合中查找u的in_time的位置
            auto it = window.find({in2_time[u], out2_time[u]});
            bool conflict = false;
            // 检查前一个节点是否包含u
            if (it != window.begin())
            {
                auto it_prev = prev(it);
                if (it_prev->second >= out2_time[u])
                {
                    conflict = true;
                }
            }
            // 检查后一个节点是否被u包含
            auto it_next = next(it);
            if (it_next != window.end())
            {
                if (it_next->first <= in2_time[u] && it_next->second >= out2_time[u])
                {
                    conflict = true;
                }
            }
            // 如果有冲突，需要移动左边界
            while (conflict)
            {
                // 移除路径中最左边的节点
                int remove_node = current_path[left];
                window.erase({in2_time[remove_node], out2_time[remove_node]});
                left++;
                // 重新检查冲突
                conflict = false;
                if (!window.empty())
                {
                    it = window.find({in2_time[u], out2_time[u]});
                    if (it != window.begin())
                    {
                        auto it_prev = prev(it);
                        if (it_prev->second >= out2_time[u])
                        {
                            conflict = true;
                            continue;
                        }
                    }
                    it_next = next(it);
                    if (it_next != window.end())
                    {
                        if (it_next->first <= in2_time[u] && it_next->second >= out2_time[u])
                        {
                            conflict = true;
                            continue;
                        }
                    }
                }
            }

            // 更新最大集合大小
            max_size = max(max_size, (int)(window.size()));

            // 将子节点加入栈中，逆序遍历以保证DFS顺序
            for (auto it = tree1[u].rbegin(); it != tree1[u].rend(); ++it)
            {
                int v = *it;
                if (v != parent)
                {
                    stk.emplace(v, u);
                }
            }

            // 离开节点u时，按照后序处理，会在下一次循环中处理
            // 这里不需要显式处理离开节点，因为我们是维护一个全局窗口
            // 具体的窗口调整是在有冲突时进行的
        }

        // 输出最大集合大小
        cout << max_size << "\n";
    }
}
