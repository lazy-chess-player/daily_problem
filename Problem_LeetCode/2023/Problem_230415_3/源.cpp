#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {
        vector<vector<int>> g(n); // ����һ����ά����g����СΪn�������洢ÿ����԰����Щ��԰����
        for (auto& e : paths)// ����paths�е�ÿ��Ԫ��e��e��һ��һά���飬��ʾһ��·��
        {
            int x = e[0] - 1, y = e[1] - 1; // ������������x��y���ֱ��ʾ·���������˵㣬��Ϊ��Ŀ�б���Ǵ�1��ʼ������Ҫ��ȥ1
            g[x].push_back(y); // ��y���뵽g[x]�У���ʾx��y����
            g[y].push_back(x); // ��x���뵽g[y]�У���ʾy��x����
        }
        vector<int> color(n); // ����һ��һά����color����СΪn�������洢ÿ����԰�Ļ�����ɫ
        for (int i = 0; i < n; ++i) // ����ÿ����԰i
        {
            bool used[5]{}; // ����һ��bool����used����СΪ5��������¼��Щ��ɫ�Ѿ���i�����ڻ�԰ʹ���ˣ�Ĭ��ֵΪfalse
            for (int j : g[i]) // ����i�����ڻ�԰j
            {
                used[color[j]] = true; // ��j����ɫ��Ӧ��used�����е�ֵ��Ϊtrue����ʾ������ɫ�Ѿ���ʹ����
            }
            while (used[++color[i]]); // ��1��ʼ����i����ɫ��ֱ���ҵ�һ��û�б�ʹ�ù�����ɫ
        }
        return color; // ����color������Ϊ��
    }
};
