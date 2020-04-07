class Solution {
public:
    string ans;
    char isPalStr[1000][1000]; //���淶Χ�ڵ��ַ����Ƿ��ǻ��Ĵ��������ظ�����
    bool isPalindromicString(int begin, int end, const string& s) { //���м俪ʼ�жϣ�ÿ�ж�һ�ξͱ�����
        if (isPalStr[begin][end-1] !=0)
            return (isPalStr[begin][end-1]+1);//-1��1Ϊ�٣�1��1��Ϊ��
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
    string longestPalindrome(string s) { //�Ӵ���С�жϣ���������ֱ�ӷ���
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
