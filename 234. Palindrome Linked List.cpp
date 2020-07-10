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
	bool isPalindrome(ListNode* head)
	{
		if (!head) return true;
		stack<ListNode*> stk;
		for (ListNode* cur = head; cur; cur = cur->next)
			stk.push(cur);
		ListNode* cur = head;
		while (stk.top() != cur && stk.top()->next != cur)
		{
			if (stk.top()->val != cur->val)
				return false;
			stk.pop();
			cur = cur->next;
		}
		return true;
	}
};