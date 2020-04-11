class Solution {
public:
    vector<vector<int>> ret;

    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; ++i)
            if (nums[i] + nums[i + 1] > 0)
                break;
            else if (i > 0 && nums[i] == nums[i - 1])
                continue;
            else {
                for (size_t j = i + 1; j < nums.size() - 1; ++j)
                    if (nums[i] + nums[j] > 0)
                        break;
                    else if (j > i + 1 && nums[j] == nums[j - 1])
                        continue;
                    else {
                        int sum = nums[i] + nums[j];
                        auto p = lower_bound(nums.begin() + j + 1, nums.end(), -sum);
                        if (p == nums.end() || *p != -sum)
                            continue;
                        else {
                            vector<int> t{nums[i], nums[j], *p};
                            ret.push_back(t);
                        }
                }
            }
        return ret;
    }
};
