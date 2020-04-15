class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return ;
        for (auto i = nums.end() - 1; i != nums.begin(); --i) {
            if (*i > *(i - 1)) {
                auto p = upper_bound(nums.rbegin(), vector<int>::reverse_iterator(i), *(i - 1));
                swap(*p, *(i - 1));
                sort(i, nums.end());
                return ;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
