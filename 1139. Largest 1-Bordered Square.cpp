class Solution {
public:
    bool check_bound(vector<vector<int>>& grid, int l, int r, int t, int b) {
        for (int i = l; i <= r; ++i) {
            if (grid[t][i] != 1 || grid[b][i] != 1)
                return false;
        }
        for (int j = t; j <= b; ++j) {
            if (grid[j][l] != 1 || grid[j][r] != 1)
                return false;
        }
        return true;
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int res = 0;

        for (int l = 0; l < grid[0].size(); ++l)
            for (int r = grid[0].size() - 1; r >= 0; --r) {
                if (r < l) break;
                for (int t = 0; t < grid.size(); ++t)
                    for (int b = grid.size() - 1; b >= 0; --b) {
                        if (b < t) break;
                        if (r - l == b - t) {
                            if (check_bound(grid, l, r, t, b)) {
                                res = max(res, r - l + 1);        
                            }
                        }
                        
                    }
            }
        return res * res;
    }
};