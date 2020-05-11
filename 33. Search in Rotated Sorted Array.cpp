class Solution {
public:
    vector<int>::iterator pstart; // �����������λ��
    int t;                        // ȫ�ּ�¼Ŀ��ֵ
    int recursion(vector<int>::iterator pleft, vector<int>::iterator pright) {
        if (pleft + 1 == pright)
            return (*pleft == t ? pleft - pstart : -1);
        auto pmid = pright - (pright - pleft) / 2;
        // ���������Ϊ[pleft, pmid), [pmid, pright)
        // ����Ȼ��ת������ݹ���û��֣�����˳�������ж��ֲ���
        if (*pleft > *(pmid - 1)) {
            auto p = lower_bound(pmid, pright, t);
            if (p != pright && *p == t)
                return p - pstart;
            return recursion(pleft, pmid);
        }
        else {
            auto p = lower_bound(pleft, pmid, t);
            if (p != pmid && *p == t)
                return p - pstart;
            return recursion(pmid, pright);
        }
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        pstart = nums.begin();
        t = target;
        return recursion(nums.begin(), nums.end());
    }
};
