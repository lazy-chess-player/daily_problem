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
    int cnt = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head)
            return NULL;
        head->next = removeNthFromEnd(head->next, n);
        cnt++;
        if (cnt == n)
            return head->next;
        return head;
    }
};