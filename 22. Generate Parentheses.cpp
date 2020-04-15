class Solution {
public:
    vector<string> ret;
    string t;
    void dfs(unsigned k, unsigned p, unsigned q, unsigned n) {
        if (k == 2 * n - 1) {
            t.push_back(')');
            ret.push_back(t);
            t.pop_back();
            return ;
        }
        if (p > 0) {
            t.push_back('(');
            dfs(k+1, p-1, q, n);
            t.pop_back();
        }
        if (q > p) {
            t.push_back(')');
            dfs(k+1, p, q-1, n);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        t.push_back('(');
        dfs(1, n-1, n, n);

        return ret;
    }
};
