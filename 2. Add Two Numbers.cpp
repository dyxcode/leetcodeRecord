/*给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool cf = false;
        ListNode *l3 = new ListNode(0), *t = l3;
        while (l1 && l2) {
            t->next = new ListNode(l1->val + l2->val);
            if (cf) {
                ++t->next->val;
                cf = false;
            }
            if (t->next->val >= 10) {
                t->next->val -= 10;
                cf = true;
            }
            l1 = l1->next;
            l2 = l2->next;
            t = t->next;
        }
        while (l1) {
            t->next = new ListNode(l1->val);
            if (cf) {
                ++t->next->val;
                cf = false;
            }
            if (t->next->val >= 10) {
                t->next->val -= 10;
                cf = true;
            }
            l1 = l1->next;
            t = t->next;
        }
        while (l2) {
            t->next = new ListNode(l2->val);
            if (cf) {
                ++t->next->val;
                cf = false;
            }
            if (t->next->val >= 10) {
                t->next->val -= 10;
                cf = true;
            }
            l2 = l2->next;
            t = t->next;
        }
        if (cf) {
            t->next = new ListNode(1);
        }
        t = l3;
        l3 = l3->next;
        delete t;

        return l3;
    }
};
