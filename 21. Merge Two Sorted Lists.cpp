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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        if (l2->val < l1->val)
            swap(l1, l2);
        ListNode *p = l1, *q = l2;
        ListNode *t;
        while (p->next) {
            while (q != NULL && q->val < p->next->val) {
                t = q;
                q = q->next;
                t->next = p->next;
                p->next = t;
                p = p->next;
            }
            if (q == NULL)
                return l1;
            p = p->next;
        }
        p->next = q;
        return l1;
    }
};
