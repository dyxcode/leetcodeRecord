class Solution {
public:
    int computeHeight(vector<int>& vec, int i, int j) {
        return (vec[i] > vec[j] ? vec[j] : vec[i]);
    }
    int computeWeight(vector<int>& vec, int i, int j) {
        if ((vec.size() - i - 1) * vec[i] == (vec.size() - j - 1) * vec[j]) {
            return j;
        }
        else {
            if ((vec.size() - i - 1) * vec[i] > (vec.size() - j - 1) * vec[j])
                return i;
            else
                return j;
        }
    }
    int maxArea(vector<int>& height) {
        int maxCap = computeHeight(height, 0, 1);
        if (height.size() == 2)
            return maxCap;
        int valpos = computeWeight(height, 0, 1);

        for (int i = 2; i < height.size(); ++i) {
            int curCap;
            if (height[valpos] <= height[i]) {
                curCap = computeHeight(height, valpos, i) * (i - valpos);
                if (curCap > maxCap)
                    maxCap = curCap;
            }
            else {
                for (int j = 0; j < i; ++j) {
                    curCap = computeHeight(height, j, i) * (i - j);
                    if (curCap > maxCap) {
                        maxCap = curCap;
                    }
                    if (height[j] >= height[i])
                        break;
                }
            }
            valpos = computeWeight(height, valpos, i);
        }
        return maxCap;
    }
};
