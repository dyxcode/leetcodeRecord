class Solution {
public:
    vector<int>::iterator pstart; // 用来计算相对位置
    int t;                        // 全局记录目标值
    int recursion(vector<int>::iterator pleft, vector<int>::iterator pright) {
        if (pleft + 1 == pright)
            return (*pleft == t ? pleft - pstart : -1);
        auto pmid = pright - (pright - pleft) / 2;
        // 将区间二分为[pleft, pmid), [pmid, pright)
        // 对依然旋转的数组递归调用划分，并在顺序数组中二分查找
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
