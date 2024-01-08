#include <iostream>
#include <unordered_map>

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
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix = 0;
        unordered_map<int, ListNode*> seen;
        for (ListNode* node = dummy; node; node = node->next)
        {
            prefix += node->val;
            seen[prefix] = node;
        }
        prefix = 0;
        for (ListNode* node = dummy; node; node = node->next)
        {
            prefix += node->val;
            node->next = seen[prefix]->next;
        }
        return dummy->next;
    }
};

void printList(ListNode* head)
{
    ListNode* curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

void testSolution()
{
    // Ê¾Àý 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(-3);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(1);

    Solution solution1;
    cout << "Input: ";
    printList(head1);
    ListNode* result1 = solution1.removeZeroSumSublists(head1);
    cout << "Output: ";
    printList(result1);

    // Ê¾Àý 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(-3);
    head2->next->next->next->next = new ListNode(4);

    Solution solution2;
    cout << "Input: ";
    printList(head2);
    ListNode* result2 = solution2.removeZeroSumSublists(head2);
    cout << "Output: ";
    printList(result2);

    // Ê¾Àý 3
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(-3);
    head3->next->next->next->next = new ListNode(-2);

    Solution solution3;
    cout << "Input: ";
    printList(head3);
    ListNode* result3 = solution3.removeZeroSumSublists(head3);
    cout << "Output: ";
    printList(result3);
}

int main()
{
    testSolution();
    return 0;
}
