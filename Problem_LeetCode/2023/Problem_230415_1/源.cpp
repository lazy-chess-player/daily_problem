#include<iostream>

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
    ListNode* middleNode(ListNode* head)
    {
        int i = 0;
        ListNode * h = head;
        ListNode* p = head->next;
        while (p)
        {
            p = p->next;
            i++;
        }
        i = (i + 1) / 2;
        while (i--)
        {
            h = h->next;
        }
        return h;
    }
};