class Solution {
public:
    int longestValidParentheses(string s) {
        // �����±�iΪ��β�������У����Ч�����Ӵ��ĳ���
        vector<int> dp(s.size());
        int ret = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else if (s[i - 1] == '(') {
                if (i == 1)
                    dp[i] = 2;
                else
                    dp[i] = dp[i - 2] + 2;
            } else { // case : (s[i - 1] == ')')
                if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(')
                    if (i - dp[i-1] - 2 < 0)
                        dp[i] = dp[i-1] + 2;
                    else
                        dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2];
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
