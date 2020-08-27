class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_val = nums.front();
        int upper_bound = -1;
        for (size_t i = 0u; i != nums.size(); ++i) {
            if (nums[i] < max_val)
                upper_bound = i;
            max_val = max(max_val, nums[i]);
        }
        if (upper_bound == -1)
            return 0;
        int min_val = nums.back();
        int lower_bound;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] > min_val)
                lower_bound = i;
            min_val = min(min_val, nums[i]);
        }
        return upper_bound - lower_bound + 1;
    }
};