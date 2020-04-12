/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> stk;
        ListNode* cur = head;
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->next;
        }
        while (n--)
            stk.pop();
        if (!stk.empty())
            stk.top()->next = stk.top()->next->next;
        else
            head = head->next;
        return head;
    }
};
