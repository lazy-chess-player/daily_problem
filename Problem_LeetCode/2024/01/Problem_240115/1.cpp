#include<iostream>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNodenext) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            int val = cur->next->val;
            if (cur->next->next->val == val)
            {
                while (cur->next && cur->next->val == val)
                {
                    cur->next = cur->next->next;
                }
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};