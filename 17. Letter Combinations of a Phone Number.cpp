class Solution {
public:
    vector<string> num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ret;
    string temp;
    void dfs(const string& s, size_t t) {
        int n = s[t] - '0';
        if (t == (s.size() - 1)) {
            for (auto i : num[n]) {
                temp.push_back(i);
                ret.push_back(temp);
                temp.pop_back();
            }
            return ;
        }
        for (auto i : num[n]) {
            temp.push_back(i);
            dfs(s, t + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.empty())
            dfs(digits, 0);
        return ret;
    }
};
