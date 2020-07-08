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
	ListNode* reverse(ListNode* p, ListNode* child)
	{
		if (child)
		{
			ListNode* grandson = child->next;
			child->next = p;
			return reverse(child, grandson);
		}
		else
			return p;
	}
	ListNode* reverseList(ListNode* head)
	{
		if (!head)
			return head;
		ListNode *child = head->next;
		head->next = NULL;
		return reverse(head, child);
	}
};