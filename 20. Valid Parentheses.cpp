class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        stack<char> stk;
        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else if (c == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                else
                    stk.pop();
            }
            else if (c == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                else
                    stk.pop();
            }
            else if (c == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                else
                    stk.pop();
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};
