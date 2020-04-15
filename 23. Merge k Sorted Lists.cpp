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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        multiset<int> ret;
        for (auto l : lists) {
            auto p = ret.begin();
            while (l != nullptr) {
                p = ret.insert(p, l->val);
                l = l->next;
            }
        }
        if (ret.empty())
            return nullptr;
        auto p = ret.begin();
        ListNode *start = new ListNode(*p);
        ListNode *end = start;
        for (++p; p != ret.end(); ++p) {
            end->next = new ListNode(*p);
            end = end->next;
        }
        return start;
    }
};
