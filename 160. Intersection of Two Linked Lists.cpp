/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		stack<ListNode*> a_stk, b_stk;
		ListNode* cur = headA;
		while (cur)
		{
			a_stk.push(cur);
			cur = cur->next;
		}
		cur = headB;
		while (cur)
		{
			b_stk.push(cur);
			cur = cur->next;
		}
		ListNode* ret = NULL;
		while (!a_stk.empty() && !b_stk.empty())
		{
			if (a_stk.top() == b_stk.top())
				ret = a_stk.top();
			a_stk.pop();
			b_stk.pop();
		}
		return ret;
	}
};