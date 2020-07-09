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
	bool hasCycle(ListNode *head)
	{
		ListNode * slow, *fast;
		slow = fast = head;
		do
		{
			if (slow)
				slow = slow->next;
			else
				return false;

			if (fast && fast->next)
				fast = fast->next->next;
			else
				return false;
		} while (slow != fast);
		return true;
	}
};