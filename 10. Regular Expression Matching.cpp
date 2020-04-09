class Solution {
public:
    bool starMatch(const string& s, const string& p, int star) { //有'*'的匹配
        string chs;
        for (size_t i = 0; i < star; ++i) {
            if (p[i*2] == '.') //里面有'.'直接返回true
                return true;
            chs.push_back(p[i*2]);
        }
        size_t i = 0, j = 0;
        while (i < s.size()) {
            if (s[i] != chs[j]) {
                ++j;
                if (j == chs.size())
                    return false;
            }
            else ++i;
        }
        return true;
    }

    bool isAllStar(const string& p) {
        if (p.empty())
            return true;
        for (size_t i = 1; i < p.size(); i += 2)
            if (p[i] != '*')
                return false;
        return p.back() == '*';
    }

    bool isMatch(string s, string p) {
        if (s.empty())
            return isAllStar(p);
        size_t co = p.find_first_of('*'); //查找第一个出现'*'的位置
        if (co == string::npos) {
            if (s.size() != p.size()) //长度不等返回假
                return false;
            for (size_t pos = 0; pos < s.size(); ++pos)
                if (s[pos] != p[pos] && p[pos] != '.') //有字符不同返回假
                    return false;
            return true;  //没问题返回真
        }
        else {
            if (s.size() < co - 1) //s不够
                return false;
            for (size_t pos = 0; pos < co - 1; ++pos)
                if (s[pos] != p[pos] && p[pos] != '.')
                    return false;
            string tail_s(s, co - 1); //co-1前面的都匹配了, 检查后面的
            if (tail_s.empty()) //判空
                return isAllStar(p.substr(co - 1));

            int numStar = 1;
            while (1) { //如果'*'连续出现
                if (co == p.size() - 1) { //'*'后面没有字符了
                    string st(p, co - (2*numStar - 1), 2*numStar);
                    return starMatch(tail_s, st, numStar);
                }
                size_t next_co = p.find_first_of('*', co + 1); //寻找第下一个'*'
                if (next_co == string::npos) { //没有'*'，则现在这个'*'后面必须和s的尾部匹配
                    int i = tail_s.size()-1;
                    for (size_t j = p.size()-1; j > co; --i, --j)
                        if (i < 0 || (tail_s[i] != p[j] && p[j] != '.'))
                            return false;
                    //尾部匹配
                    string sub_s(tail_s.begin(), tail_s.begin() + i + 1);
                    string st(p, co - (2*numStar - 1), 2*numStar);
                    if (starMatch(sub_s, st, numStar))
                        return true;
                    else return false;
                }
                else { //有第二个'*', 坐标为next_co
                    string sub_p(p, co + 1, next_co - co - 2); //两个星号中间
                    if (sub_p.empty()) { //如果子串为空
                        co = next_co;
                        ++numStar;
                        continue;
                    }
                    else if (sub_p.size() > tail_s.size())
                        return false;
                    size_t point_pos = sub_p.find('.'); //找到特殊符号之前的子串
                    string str;                 //找到必须匹配的部分子串，再校验其余部分
                    unsigned int pointNum = 0;
                    if (point_pos == 0) { //第一个是'.'
                        ++pointNum;
                        while (++point_pos < sub_p.size() && sub_p[point_pos] == '.')
                            pointNum++;

                        if (point_pos == sub_p.size()) { //全部都是'.'
                            string st(p, co - (2*numStar - 1), 2*numStar);
                            for (size_t i = 0; i <= tail_s.size()-pointNum; ++i) {
                                string sub_s(tail_s.begin(), tail_s.begin() + i);
                                string new_s(tail_s, i + pointNum);
                                string new_p(p, next_co - 1);
                                if (starMatch(sub_s, st, numStar) && isMatch(new_s, new_p))
                                    return true;
                            }
                            return false;
                        }
                        else {
                            size_t next_point = sub_p.find_first_of('.', pointNum);
                            if (next_point == string::npos)
                                str = sub_p.substr(pointNum);
                            else
                                str.assign(sub_p, pointNum, next_point - pointNum);
                        }
                    }
                    else if (point_pos == string::npos)
                        str = sub_p;
                    else
                        str.assign(sub_p, 0, point_pos);

                    size_t pos = 0;
                    if (!str.empty())
                        pos = tail_s.find(str);  //该子串必须在tail_s中存在匹配
                    while (pos != string::npos) {
                        bool flag = false;
                        if (point_pos != string::npos) { //如果有点则必须检验全部子串
                            if (pos >= pointNum) {
                                size_t j;
                                if (pointNum == 0) //第一个不是点
                                    j = point_pos;
                                else j = pointNum + str.size();
                                for (size_t i = pos + str.size(); j < sub_p.size(); ++i, ++j)
                                    if (i >= tail_s.size())
                                        return false;
                                    else if (tail_s[i] != sub_p[j] && sub_p[j] != '.') {
                                        flag = true;
                                        break;
                                    }
                            }
                            else flag = true;
                        }
                        if (flag == false) {
                            string new_p(p, next_co - 1);
                            string new_s(tail_s, pos + sub_p.size() - pointNum);
                            if (isMatch(new_s, new_p)) {    //子串后面可以匹配
                                string sub_s(tail_s.begin(), tail_s.begin() + pos);
                                string st(p, co - (2*numStar - 1), 2*numStar);
                                if (starMatch(sub_s, st, numStar))  //子串前面也可以匹配，返回真
                                    return true;
                            }
                        }

                        pos = tail_s.find(str, pos + str.size()); //寻找s中下一个匹配的子串
                    }
                    return false;
                }
            }
        }
    }
};
