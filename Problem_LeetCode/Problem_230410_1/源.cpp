#include<iostream>
#include<vector>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int>ans, stk;
        int i = 0;
        while (head != nullptr)
        {
            ans.push_back(head->val);
            while (!stk.empty() && ans[stk.back()] < ans[i])
            {
                ans[stk.back()] = ans[i];
                stk.pop_back();
            }
            stk.push_back(i++);
            head = head->next;
        }
        for (int& j : stk)
        {
            ans[j] = 0;
        }
        return ans;
    }
};

int main()
{
    // ��������
    ListNode* head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(5);

    // ���ú���
    Solution s;
    vector<int> result = s.nextLargerNodes(head);

    // ��ӡ���
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}