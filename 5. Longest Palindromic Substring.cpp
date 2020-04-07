class Solution {
public:
    string ans;
    char isPalStr[1000][1000]; //保存范围内的字符串是否是回文串，避免重复计算
    bool isPalindromicString(int begin, int end, const string& s) { //从中间开始判断，每判断一次就保存结果
        if (isPalStr[begin][end-1] !=0)
            return (isPalStr[begin][end-1]+1);//-1加1为假，1加1还为真
        int len = end - begin;
        int midFront, midBack;
        if (len % 2) {
            midFront = begin + len/2 - 1;
            midBack = begin + len/2 + 1;
        }
        else {
            midFront = begin + len/2 - 1;
            midBack = begin + len/2;
        }
        --end;
        while (begin <= midFront && end >= midBack) {
            if (s[midFront] != s[midBack]) {
                isPalStr[midFront][midBack] = -1;
                return false;
            }
            else
                isPalStr[midFront][midBack] = 1;
            midFront--;
            midBack++;
        }
        return true;
    }
    string longestPalindrome(string s) { //从大往小判断，符合条件直接返回
        memset(isPalStr, 0, sizeof(isPalStr));
        int maxSize = s.size();
        while (maxSize > 0) {
            int begin = 0;
            while (begin + maxSize <= s.size()) {
                if (isPalindromicString(begin, begin + maxSize, s)) {
                    ans.assign(s.begin()+begin, s.begin()+begin + maxSize);
                    return ans;
                }
                else
                    begin++;
            }
            maxSize--;
        }
        return "";
    }
};
