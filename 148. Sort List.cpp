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
	int genLength(ListNode* p)
	{
		int len = 0;
		while (p)
		{
			len++;
			p = p->next;
		}
		return len;
	}

	ListNode* mergeList(ListNode* pre_first, ListNode* f, ListNode* pre_second, ListNode* s, int size)
	{
		int num_f = 0, num_s = 0;
		while (1)
		{
			if (f->val <= s->val)
			{
				pre_first = f;
				f = f->next;
				num_f++;
				if (num_f == size)
					break;
			}
			else
			{
				ListNode* temp = s->next;
				pre_second->next = temp;
				pre_first->next = s;
				s->next = f;
				s = temp;
				pre_first = pre_first->next;
				num_s++;
				if (num_s == size || !s)
					break;
			}
		}
		while (num_s != size && s)
		{
			s = s->next;
			num_s++;
		}
		while (f->next != s)
			f = f->next;
		return f;
	}
	ListNode* sortList(ListNode* head)
	{
		if (!head) return head;
		ListNode * pre = new ListNode(0);
		pre->next = head;

		int len = genLength(head);
		int size = 1;
		ListNode* pre_first = pre;
		while (size < len)
		{
			bool is_end = false;
			ListNode* first = pre_first->next;
			ListNode* second = first;
			ListNode* pre_second;
			for (int i = 0; i < size; ++i)
				if (second && second->next)
				{
					pre_second = second;
					second = second->next;
				}
				else
				{
					is_end = true;
					break;
				}
			if (is_end)
			{
				size *= 2;
				pre_first = pre;
				continue;
			}
			pre_first = mergeList(pre_first, first, pre_second, second, size);
		}
		return pre->next;
	}
};