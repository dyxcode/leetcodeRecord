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
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *slow, *fast;
		slow = fast = head;
		do
		{
			if (fast && fast->next)
				fast = fast->next->next;
			else
				return NULL;
			slow = slow->next;
		} while (slow != fast);

		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};