#define _Lstring_ADD_SIZE_ 16
#define _LONG_OF_TO_Lstring_TEMP_CHAR_ 100
//need template swap
//need istream, ostream
class Lstring {
private:
    char* _data;
    unsigned long long _size;
    unsigned long long _allsize;

public:

    static const unsigned long long npos = -1;

    Lstring();
    Lstring(const char*);
    Lstring(const char*, unsigned long long n);
    Lstring(const char*, unsigned long long begin, unsigned long long n);
    Lstring(unsigned long long, char);
    Lstring(const Lstring&);
    ~Lstring();

    Lstring& assign(const char*);
    Lstring& assign(const char*, unsigned long long n);
    Lstring& assign(const char*, unsigned long long begin, unsigned long long n);
    Lstring& assign(const Lstring&);
    Lstring& assign(unsigned long long, char);
    Lstring& operator=(const Lstring&);
    Lstring& operator=(const char*);

    char& at(unsigned long long);
    char& operator[](unsigned long long);
    char& front();
    char& back();
    char* data();

    char at(unsigned long long)const;
    char operator[](unsigned long long)const;
    char front()const;
    char back()const;
    const char* data()const;
    const char* c_str()const;
    Lstring substr(unsigned long long begin = 0, unsigned long long n = -1)const;

    bool empty()const;
    unsigned long long size()const;
    unsigned long long length()const;
    unsigned long long max_size()const;
    bool reserve(unsigned long long);
    unsigned long long capacity()const;
    void shrink_to_fit();

    Lstring& clear();
    Lstring& insert(unsigned long long index, const Lstring&);
    Lstring& insert(unsigned long long index, const Lstring&, unsigned long long begin, unsigned long long n);
    Lstring& insert(unsigned long long index, const char*, unsigned long long n = -1);
    Lstring& insert(unsigned long long index, unsigned long long n, char);
    Lstring& erase(unsigned long long index, unsigned long long n);
    Lstring& push_back(char);
    Lstring& pop_back();
    Lstring& append(const Lstring& str);
    Lstring& append(const Lstring& str, unsigned long long begin, unsigned long long n);
    Lstring& append(const char* s);
    Lstring& append(const char* s, unsigned long long n);
    Lstring& append(unsigned long long n, char A);
    Lstring& operator+=(const Lstring& str);
    Lstring& operator+=(const char* s);
    Lstring& operator+=(char A);
    unsigned long long copy(char* s, unsigned long long n, unsigned long long begin = 0) const;
    void resize(unsigned long long n);
    void resize(unsigned long long n, char A);
    void swap(Lstring&);
    Lstring& replace(unsigned long long index, unsigned long long n, const Lstring& s);
    Lstring& replace(unsigned long long index, unsigned long long n, const Lstring& s, unsigned long long begin, unsigned long long sn);
    Lstring& replace(unsigned long long index, unsigned long long n, const char* s);
    Lstring& replace(unsigned long long index, unsigned long long n, const char* s, unsigned long long sn);
    Lstring& replace(unsigned long long index, unsigned long long n, unsigned long long cn, char A);
    unsigned long long find(const Lstring& str, unsigned long long index = 0)const;
    unsigned long long find(const char* s, unsigned long long index = 0)const;
    unsigned long long find(const char* s, unsigned long long index, unsigned long long n)const;
    unsigned long long find(char A, unsigned long long index = 0)const;
    unsigned long long rfind(const Lstring& str, unsigned long long index = -1)const;
    unsigned long long rfind(const char* s, unsigned long long index = -1)const;
    unsigned long long rfind(const char* s, unsigned long long index, unsigned long long n)const;
    unsigned long long rfind(char A, unsigned long long index = -1)const;
    unsigned long long find_first_of(const Lstring& str, unsigned long long index = 0)const;
    unsigned long long find_first_of(const char* s, unsigned long long index = 0)const;
    unsigned long long find_first_of(const char* s, unsigned long long index, unsigned long long n)const;
    unsigned long long find_first_of(char A, unsigned long long index = 0)const;
    unsigned long long find_last_of(const Lstring& str, unsigned long long index = -1)const;
    unsigned long long find_last_of(const char* s, unsigned long long index = -1)const;
    unsigned long long find_last_of(const char* s, unsigned long long index, unsigned long long n)const;
    unsigned long long find_last_of(char A, unsigned long long index = -1)const;
    unsigned long long find_first_not_of(const Lstring& str, unsigned long long index = 0)const;
    unsigned long long find_first_not_of(const char* s, unsigned long long index = 0)const;
    unsigned long long find_first_not_of(const char* s, unsigned long long index, unsigned long long n)const;
    unsigned long long find_first_not_of(char A, unsigned long long index = 0)const;
    unsigned long long find_last_not_of(const Lstring& str, unsigned long long index = -1)const;
    unsigned long long find_last_not_of(const char* s, unsigned long long index = -1)const;
    unsigned long long find_last_not_of(const char* s, unsigned long long index, unsigned long long n)const;
    unsigned long long find_last_not_of(char A, unsigned long long index = -1)const;
    int compare(const Lstring& str)const;
    int compare(unsigned long long begin, unsigned long long n, const Lstring& str)const;
    int compare(unsigned long long begin, unsigned long long n, const Lstring& str, unsigned long long subBegin, unsigned long long subN)const;
    int compare(const char* s)const;
    int compare(unsigned long long begin, unsigned long long n, const char* s)const;
    int compare(unsigned long long begin, unsigned long long n, const char* s, unsigned long long sn)const;

};
Lstring operator+(const Lstring& lhs, const Lstring& rhs);
Lstring operator+(const Lstring& lhs, const char* rhs);
Lstring operator+(const char* lhs, const Lstring& rhs);
Lstring operator+(const Lstring& lhs, char rhs);
Lstring operator+(char lhs, const Lstring& rhs);
bool operator!=(const Lstring& lhs, const Lstring& rhs);
bool operator!=(const Lstring& lhs, const char* rhs);
bool operator!=(const char* lhs, const Lstring& rhs);
bool operator!=(const Lstring& lhs, char rhs);
bool operator!=(char lhs, const Lstring& rhs);
bool operator==(const Lstring& lhs, const Lstring& rhs);
bool operator==(const Lstring& lhs, const char* rhs);
bool operator==(const char* lhs, const Lstring& rhs);
bool operator==(const Lstring& lhs, char rhs);
bool operator==(char lhs, const Lstring& rhs);
bool operator<(const Lstring& lhs, const Lstring& rhs);
bool operator<(const Lstring& lhs, const char* rhs);
bool operator<(const char* lhs, const Lstring& rhs);
bool operator<(const Lstring& lhs, char rhs);
bool operator<(char lhs, const Lstring& rhs);
bool operator<=(const Lstring& lhs, const Lstring& rhs);
bool operator<=(const Lstring& lhs, const char* rhs);
bool operator<=(const char* lhs, const Lstring& rhs);
bool operator<=(const Lstring& lhs, char rhs);
bool operator<=(char lhs, const Lstring& rhs);
bool operator>(const Lstring& lhs, const Lstring& rhs);
bool operator>(const Lstring& lhs, const char* rhs);
bool operator>(const char* lhs, const Lstring& rhs);
bool operator>(const Lstring& lhs, char rhs);
bool operator>(char lhs, const Lstring& rhs);
bool operator>=(const Lstring& lhs, const Lstring& rhs);
bool operator>=(const Lstring& lhs, const char* rhs);
bool operator>=(const char* lhs, const Lstring& rhs);
bool operator>=(const Lstring& lhs, char rhs);
bool operator>=(char lhs, const Lstring& rhs);
istream& operator>>(istream& is, Lstring& s);
ostream& operator<<(ostream& os, const Lstring& s);
istream& getline(istream& is, Lstring& s);
istream& getline(istream& is, Lstring& s, char delim);
void swap(Lstring& s1, Lstring& s2);
int stoi(const Lstring& str, unsigned long long* index = nullptr, int base = 10);//进制转换我不想复刻了，啊啊啊啊啊去世了
long stol(const Lstring& str, unsigned long long* index = nullptr, int base = 10);
long long stoll(const Lstring& str, unsigned long long* index = nullptr, int base = 10);
unsigned long stoul(const Lstring& str, unsigned long long* index = nullptr, int base = 10);
unsigned long long stoull(const Lstring& str, unsigned long long* index = nullptr, int base = 10);
float stof(const Lstring& str, unsigned long long* index = nullptr);
double stod(const Lstring& str, unsigned long long* index = nullptr);
long double stold(const Lstring& str, unsigned long long* index = nullptr);
Lstring to_Lstring(int val);
Lstring to_Lstring(long val);
Lstring to_Lstring(long long val);
Lstring to_Lstring(unsigned val);
Lstring to_Lstring(unsigned long val);
Lstring to_Lstring(unsigned long long val);
Lstring to_Lstring(float val);
Lstring to_Lstring(double val);
Lstring to_Lstring(long double val);

const Lstring ___Lstring_EOF__ = "___Lstring_EOF__";

/************************************************************************************
 * 程序：Lstring字符串类源文件
 * 语言：C++
 * 编程人：呆呆兽（计科**班2021********）
 * 指导老师：钟凡
 * 创建时间：2022/5/16
 * 修改时间：2022/5/23
 *
 * 程序描述：可恶啊，为什么之前不知道有sprintf()啊！
 *
 ************************************************************************************/

#include <cstring>
#include <ctype.h>
#include <cmath>
Lstring to_Lstring(long double val) {
    int sgd = val < 0 ? -1 : 1;
    int ans1 = val * sgd;
    long double ans2 = val * sgd - ans1;
    int N = log10(ans1) + 1;
    int len = (sgd == -1) + N + 1 + 6;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    (sgd == -1) ? s[0] = '-' : 0;
    for (int i = N + (sgd == -1) - 1; i >= (sgd == -1); --i) {
        s[i] = ans1 % 10 + '0';
        ans1 /= 10;
    }
    s[(sgd == -1) + N] = '.';
    for (int i = (sgd == -1) + N + 1; i < len; ++i) {
        s[i] = (ans2 *= 10) + '0';
        ans2 -= int(ans2);
    }
    s[len] = 0;
    return Lstring(s);
}
Lstring to_Lstring(double val) {
    int sgd = val < 0 ? -1 : 1;
    int ans1 = val * sgd;
    double ans2 = val * sgd - ans1;
    int N = log10(ans1) + 1;
    int len = (sgd == -1) + N + 1 + 6;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    (sgd == -1) ? s[0] = '-' : 0;
    for (int i = N + (sgd == -1) - 1; i >= (sgd == -1); --i) {
        s[i] = ans1 % 10 + '0';
        ans1 /= 10;
    }
    s[(sgd == -1) + N] = '.';
    for (int i = (sgd == -1) + N + 1; i < len; ++i) {
        s[i] = (ans2 *= 10) + '0';
        ans2 -= int(ans2);
    }
    s[len] = 0;
    return Lstring(s);
}
Lstring to_Lstring(float val) {
    int sgd = val < 0 ? -1 : 1;
    int ans1 = val * sgd;
    float ans2 = val * sgd - ans1;
    int N = log10(ans1) + 1;
    int len = (sgd == -1) + N + 1 + 6;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    (sgd == -1) ? s[0] = '-' : 0;
    for (int i = N + (sgd == -1) - 1; i >= (sgd == -1); --i) {
        s[i] = ans1 % 10 + '0';
        ans1 /= 10;
    }
    s[(sgd == -1) + N] = '.';
    for (int i = (sgd == -1) + N + 1; i < len; ++i) {
        s[i] = (ans2 *= 10) + '0';
        ans2 -= int(ans2);
    }
    s[len] = 0;
    return Lstring(s);
}
Lstring to_Lstring(unsigned long long val) {
    unsigned long long ans = val;
    int N = log10(ans) + 1;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    for (int i = N - 1; i >= 0; --i) {
        s[i] = ans % 10 + '0';
        ans /= 10;
    }
    s[N] = 0;
    return Lstring(s);
}
Lstring to_Lstring(unsigned long val) {
    unsigned long ans = val;
    int N = log10(ans) + 1;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    for (int i = N - 1; i >= 0; --i) {
        s[i] = ans % 10 + '0';
        ans /= 10;
    }
    s[N] = 0;
    return Lstring(s);
}
Lstring to_Lstring(unsigned val) {
    unsigned ans = val;
    int N = log10(ans) + 1;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    for (int i = N - 1; i >= 0; --i) {
        s[i] = ans % 10 + '0';
        ans /= 10;
    }
    s[N] = 0;
    return Lstring(s);
}
Lstring to_Lstring(long long val) {
    int sgd = val < 0 ? -1 : 1;
    long long ans = val * sgd;
    int N = log10(ans) + 1;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    for (int i = N + (sgd == -1) - 1; i >= (sgd == -1); --i) {
        s[i] = ans % 10 + '0';
        ans /= 10;
    }
    s[N + (sgd == -1)] = 0;
    (sgd == -1) ? s[0] = '-' : 0;
    return Lstring(s);
}
Lstring to_Lstring(long val) {
    int sgd = val < 0 ? -1 : 1;
    long ans = val * sgd;
    int N = log10(ans) + 1;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    for (int i = N + (sgd == -1) - 1; i >= (sgd == -1); --i) {
        s[i] = ans % 10 + '0';
        ans /= 10;
    }
    s[N + (sgd == -1)] = 0;
    (sgd == -1) ? s[0] = '-' : 0;
    return Lstring(s);
}
Lstring to_Lstring(int val) {
    int sgd = val < 0 ? -1 : 1;
    int ans = val * sgd;
    int N = log10(ans) + 1;
    char s[_LONG_OF_TO_Lstring_TEMP_CHAR_];
    for (int i = N + (sgd == -1) - 1; i >= (sgd == -1); --i) {
        s[i] = ans % 10 + '0';
        ans /= 10;
    }
    s[N + (sgd == -1)] = 0;
    (sgd == -1) ? s[0] = '-' : 0;
    return Lstring(s);
}
long double stold(const Lstring& s, unsigned long long* index) {
    long double ans = 0; int sgd = 1;
    const Lstring cmp = "0123456789";

    unsigned long long begin = s.find_first_of(cmp + "-+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '-') {
        sgd = -1;
        begin++;
    }
    else if (s[begin] == '+') {
        begin++;
    }
    if (begin > end || begin == end && s[begin] != '.') {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        box = s[i] - '0';
        ans += box * pow(10, end - 1 - i);
    }
    index ? *index = end : 0;

    if (end >= s.size()) {//防短路，不和下面放在一起
        return ans * sgd;
    }
    if (s[end] == '.') {
        begin = end + 1;
        if (begin >= s.size()) {
            return ans * sgd;
        }
        end = s.find_first_not_of(cmp, begin);//begin开始不加一
        end == Lstring::npos ? end = s.size() : 0;
        if (begin >= end) {
            return ans * sgd;
        }
        else {
            for (unsigned long long i = begin; i < end; ++i) {
                int box;
                box = s[i] - '0';
                ans += box / pow(10, (i - begin + 1));
            }
        }
    }
    index ? *index = end : 0;
    return ans * sgd;
}
double stod(const Lstring& s, unsigned long long* index) {
    double ans = 0; int sgd = 1;
    const Lstring cmp = "0123456789";

    unsigned long long begin = s.find_first_of(cmp + "-+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '-') {
        sgd = -1;
        begin++;
    }
    else if (s[begin] == '+') {
        begin++;
    }
    if (begin > end || begin == end && s[begin] != '.') {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        box = s[i] - '0';
        ans += box * pow(10, end - 1 - i);
    }
    index ? *index = end : 0;

    if (end >= s.size()) {//防短路，不和下面放在一起
        return ans * sgd;
    }
    if (s[end] == '.') {
        begin = end + 1;
        if (begin >= s.size()) {
            return ans * sgd;
        }
        end = s.find_first_not_of(cmp, begin);//begin开始不加一
        end == Lstring::npos ? end = s.size() : 0;
        if (begin >= end) {
            return ans * sgd;
        }
        else {
            for (unsigned long long i = begin; i < end; ++i) {
                int box;
                box = s[i] - '0';
                ans += box / pow(10, (i - begin + 1));
            }
        }
    }
    index ? *index = end : 0;
    return ans * sgd;
}
float stof(const Lstring& s, unsigned long long* index) {
    float ans = 0; int sgd = 1;
    const Lstring cmp = "0123456789";

    unsigned long long begin = s.find_first_of(cmp + "-+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '-') {
        sgd = -1;
        begin++;
    }
    else if (s[begin] == '+') {
        begin++;
    }
    if (begin > end || begin == end && s[begin] != '.') {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        box = s[i] - '0';
        ans += box * pow(10, end - 1 - i);
    }
    index ? *index = end : 0;

    if (end >= s.size()) {//防短路，不和下面放在一起
        return ans * sgd;
    }
    if (s[end] == '.') {
        begin = end + 1;
        if (begin >= s.size()) {
            return ans * sgd;
        }
        end = s.find_first_not_of(cmp, begin);//begin开始不加一
        end == Lstring::npos ? end = s.size() : 0;
        if (begin >= end) {
            return ans * sgd;
        }
        else {
            for (unsigned long long i = begin; i < end; ++i) {
                int box;
                box = s[i] - '0';
                ans += box / pow(10, (i - begin + 1));
            }
        }
    }
    index ? *index = end : 0;
    return ans * sgd;
}
unsigned long long stoull(const Lstring& s, unsigned long long* index, int base) {
    unsigned long long ans = 0;
    Lstring cmp;
    for (char i = 0; i < base; ++i) {//生成对应基数字符集
        i < 10 ? cmp.push_back('0' + i) : (cmp.push_back('A' + i - 10), cmp.push_back('a' + i - 10));
    }
    unsigned long long begin = s.find_first_of(cmp + "+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '+') {
        begin++;
    }
    if (begin >= end) {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        if ('0' <= s[i] && s[i] <= '9') {
            box = s[i] - '0';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            box = s[i] - 'A' + 10;
        }
        else {
            box = s[i] - 'a' + 10;
        }
        ans += box * pow(base, end - 1 - i);
    }

    index ? *index = end : 0;
    return ans;
}
unsigned long stoul(const Lstring& s, unsigned long long* index, int base) {
    unsigned long ans = 0;
    Lstring cmp;
    for (char i = 0; i < base; ++i) {//生成对应基数字符集
        i < 10 ? cmp.push_back('0' + i) : (cmp.push_back('A' + i - 10), cmp.push_back('a' + i - 10));
    }
    unsigned long long begin = s.find_first_of(cmp + "+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '+') {
        begin++;
    }
    if (begin >= end) {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        if ('0' <= s[i] && s[i] <= '9') {
            box = s[i] - '0';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            box = s[i] - 'A' + 10;
        }
        else {
            box = s[i] - 'a' + 10;
        }
        ans += box * pow(base, end - 1 - i);
    }

    index ? *index = end : 0;
    return ans;
}
long long stoll(const Lstring& s, unsigned long long* index, int base) {
    long long ans = 0; int sgd = 1;
    Lstring cmp;
    for (char i = 0; i < base; ++i) {//生成对应基数字符集
        i < 10 ? cmp.push_back('0' + i) : (cmp.push_back('A' + i - 10), cmp.push_back('a' + i - 10));
    }
    unsigned long long begin = s.find_first_of(cmp + "-+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '-') {
        sgd = -1;
        begin++;
    }
    else if (s[begin] == '+') {
        begin++;
    }
    if (begin >= end) {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        if ('0' <= s[i] && s[i] <= '9') {
            box = s[i] - '0';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            box = s[i] - 'A' + 10;
        }
        else {
            box = s[i] - 'a' + 10;
        }
        ans += box * pow(base, end - 1 - i);
    }

    index ? *index = end : 0;
    return ans * sgd;
}
long stol(const Lstring& s, unsigned long long* index, int base) {
    long ans = 0; int sgd = 1;
    Lstring cmp;
    for (char i = 0; i < base; ++i) {//生成对应基数字符集
        i < 10 ? cmp.push_back('0' + i) : (cmp.push_back('A' + i - 10), cmp.push_back('a' + i - 10));
    }
    unsigned long long begin = s.find_first_of(cmp + "-+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '-') {
        sgd = -1;
        begin++;
    }
    else if (s[begin] == '+') {
        begin++;
    }
    if (begin >= end) {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        if ('0' <= s[i] && s[i] <= '9') {
            box = s[i] - '0';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            box = s[i] - 'A' + 10;
        }
        else {
            box = s[i] - 'a' + 10;
        }
        ans += box * pow(base, end - 1 - i);
    }

    index ? *index = end : 0;
    return ans * sgd;
}
int stoi(const Lstring& s, unsigned long long* index, int base) {
    int ans = 0; int sgd = 1;
    Lstring cmp;
    for (char i = 0; i < base; ++i) {//生成对应基数字符集
        i < 10 ? cmp.push_back('0' + i) : (cmp.push_back('A' + i - 10), cmp.push_back('a' + i - 10));
    }
    unsigned long long begin = s.find_first_of(cmp + "-+");//转换区间
    if (begin == Lstring::npos) {
        return 0;
    }
    unsigned long long end = s.find_first_not_of(cmp, begin + 1);
    end == Lstring::npos ? end = s.size() : 0;
    if (s[begin] == '-') {
        sgd = -1;
        begin++;
    }
    else if (s[begin] == '+') {
        begin++;
    }
    if (begin >= end) {
        return 0;
    }
    for (unsigned long long i = end - 1; i >= begin; --i) {
        int box;
        if ('0' <= s[i] && s[i] <= '9') {
            box = s[i] - '0';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            box = s[i] - 'A' + 10;
        }
        else {
            box = s[i] - 'a' + 10;
        }
        ans += box * pow(base, end - 1 - i);
    }

    index ? *index = end : 0;
    return ans * sgd;
}
void swap(Lstring& s1, Lstring& s2) {
    s1.swap(s2);
}
istream& getline(istream& is, Lstring& s, char delim) {
    s.clear();
    for (char box; is >> box;) {
        if (box == delim) {
            break;
        }
        s.push_back(box);
    }
    return is;
}
istream& getline(istream& is, Lstring& s) {
    s.clear();
    for (char box; is >> box;) {
        if (box == '\n') {
            break;
        }
        s.push_back(box);
    }
    return is;
}
ostream& operator<<(ostream& os, const Lstring& s) {
    for (unsigned long long i = 0; i < s.size(); ++i) {
        os << s[i];
    }
    return os;
}
istream& operator>>(istream& in, Lstring& s) {
    s.clear();
    char box = 0;
    while (in >> box) {//scanf("%c",&box)!=EOF
        if (box > ' ' && box <= '~') break;
    }
    if (box) {
        s.push_back(box);
        for (;in >> box;) {
            if (box <= ' ' || box > '~') {
                break;
            }
            s.push_back(box);
        }
    }
    return in;
}
bool operator>=(char lhs, const Lstring& rhs) {
    return 0 >= rhs.compare(Lstring(1, lhs));
}
bool operator>=(const Lstring& lhs, char rhs) {
    return lhs.compare(Lstring(1, rhs)) >= 0;
}
bool operator>=(const char* lhs, const Lstring& rhs) {
    return 0 >= rhs.compare(lhs);
}
bool operator>=(const Lstring& lhs, const char* rhs) {
    return lhs.compare(rhs) >= 0;
}
bool operator>=(const Lstring& lhs, const Lstring& rhs) {
    return lhs.compare(rhs) >= 0;
}
bool operator>(char lhs, const Lstring& rhs) {
    return 0 > rhs.compare(Lstring(1, lhs));
}
bool operator>(const Lstring& lhs, char rhs) {
    return lhs.compare(Lstring(1, rhs)) > 0;
}
bool operator>(const char* lhs, const Lstring& rhs) {
    return 0 > rhs.compare(lhs);
}
bool operator>(const Lstring& lhs, const char* rhs) {
    return lhs.compare(rhs) > 0;
}
bool operator>(const Lstring& lhs, const Lstring& rhs) {
    return lhs.compare(rhs) > 0;
}
bool operator<=(char lhs, const Lstring& rhs) {
    return 0 <= rhs.compare(Lstring(1, lhs));
}
bool operator<=(const Lstring& lhs, char rhs) {
    return lhs.compare(Lstring(1, rhs)) <= 0;
}
bool operator<=(const char* lhs, const Lstring& rhs) {
    return 0 <= rhs.compare(lhs);
}
bool operator<=(const Lstring& lhs, const char* rhs) {
    return lhs.compare(rhs) <= 0;
}
bool operator<=(const Lstring& lhs, const Lstring& rhs) {
    return lhs.compare(rhs) <= 0;
}
bool operator<(char lhs, const Lstring& rhs) {
    return 0 < rhs.compare(Lstring(1, lhs));
}
bool operator<(const Lstring& lhs, char rhs) {
    return lhs.compare(Lstring(1, rhs)) < 0;
}
bool operator<(const char* lhs, const Lstring& rhs) {
    return 0 < rhs.compare(lhs);
}
bool operator<(const Lstring& lhs, const char* rhs) {
    return lhs.compare(rhs) < 0;
}
bool operator<(const Lstring& lhs, const Lstring& rhs) {
    return lhs.compare(rhs) < 0;
}
bool operator==(char lhs, const Lstring& rhs) {
    return !rhs.compare(Lstring(1, lhs));
}
bool operator==(const Lstring& lhs, char rhs) {
    return !lhs.compare(Lstring(1, rhs));
}
bool operator==(const char* lhs, const Lstring& rhs) {
    return !rhs.compare(lhs);
}
bool operator==(const Lstring& lhs, const char* rhs) {
    return !lhs.compare(rhs);
}
bool operator==(const Lstring& lhs, const Lstring& rhs) {
    return !lhs.compare(rhs);
}
bool operator!=(char lhs, const Lstring& rhs) {
    return !!rhs.compare(Lstring(1, lhs));
}
bool operator!=(const Lstring& lhs, char rhs) {
    return !!lhs.compare(Lstring(1, rhs));
}
bool operator!=(const char* lhs, const Lstring& rhs) {
    return !!rhs.compare(lhs);
}
bool operator!=(const Lstring& lhs, const char* rhs) {
    return !!lhs.compare(rhs);
}
bool operator!=(const Lstring& lhs, const Lstring& rhs) {
    return !!lhs.compare(rhs);
}
Lstring operator+(char lhs, const Lstring& rhs) {
    return Lstring(1, lhs) + rhs;
}
Lstring operator+(const Lstring& lhs, char rhs) {
    return lhs + Lstring(1, rhs);
}
Lstring operator+(const char* lhs, const Lstring& rhs) {
    return Lstring(lhs) + rhs;
}
Lstring operator+(const Lstring& lhs, const char* rhs) {
    return lhs + Lstring(rhs);
}
Lstring operator+(const Lstring& lhs, const Lstring& rhs) {
    Lstring temp(lhs.size() + rhs.size(), 'A');
    for (unsigned long long i = 0; i != lhs.size(); ++i) {
        temp[i] = lhs[i];
    }
    for (unsigned long long i = 0; i != rhs.size(); ++i) {
        temp[i + rhs.size()] = rhs[i];
    }
    return temp;
}
int Lstring::compare(unsigned long long begin, unsigned long long n, const char* s, unsigned long long sn)const {
    return substr(begin, n).compare(Lstring(s, sn));
}
int Lstring::compare(unsigned long long begin, unsigned long long n, const char* s)const {
    return substr(begin, n).compare(Lstring(s));
}
int Lstring::compare(const char* s)const {
    return compare(Lstring(s));
}
int Lstring::compare(unsigned long long begin, unsigned long long n, const Lstring& s, unsigned long long sbgin, unsigned long long sn)const {
    return substr(begin, n).compare(s.substr(sbgin, sn));
}
int Lstring::compare(unsigned long long begin, unsigned long long n, const Lstring& s)const {
    return substr(begin, n).compare(s);
}
int Lstring::compare(const Lstring& str)const {
    for (unsigned long long i = 0; 1; ++i) {
        if (i == _size && i == str._size) {
            return 0;
        }
        else if (i == _size) {
            return -1;
        }
        else if (i == str._size) {
            return 1;
        }
        else {//不到尾
            if (_data[i] != str._data[i]) {
                return _data[i] - str._data[i];
            }
        }
    }
}
unsigned long long Lstring::find_last_not_of(char A, unsigned long long index)const {
    for (unsigned long long i = (index < _size - 1 ? index : _size - 1); i >= 0; --i) {
        if (_data[i] != A) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::find_last_not_of(const char* s, unsigned long long index, unsigned long long n)const {
    return find_last_not_of(Lstring(s, n), index);
}
unsigned long long Lstring::find_last_not_of(const char* s, unsigned long long index)const {
    return find_last_not_of(Lstring(s), index);
}
unsigned long long Lstring::find_last_not_of(const Lstring& s, unsigned long long index)const {
    for (unsigned long long i = (index < _size - 1 ? index : _size - 1); i >= 0; --i) {
        bool find = true;
        for (unsigned long long j = 0; j < s._size; ++j) {
            if (_data[i] == s._data[j]) {
                find = false;
            }
        }
        if (find) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::find_first_not_of(char A, unsigned long long index)const {
    for (unsigned long long i = index; i < _size; ++i) {
        if (_data[i] != A) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::find_first_not_of(const char* s, unsigned long long index, unsigned long long n)const {
    return find_first_not_of(Lstring(s, n), index);
}
unsigned long long Lstring::find_first_not_of(const char* s, unsigned long long index)const {
    return find_first_not_of(Lstring(s), index);
}
unsigned long long Lstring::find_first_not_of(const Lstring& s, unsigned long long index)const {
    for (unsigned long long i = index; i < _size; ++i) {
        bool find = true;
        for (unsigned long long j = 0; j < s._size; ++j) {
            if (_data[i] == s._data[j]) {
                find = false;
            }
        }
        if (find) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::find_last_of(char A, unsigned long long index)const {
    for (unsigned long long i = (index < _size - 1 ? index : _size - 1); i >= 0; --i) {
        if (_data[i] == A) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::find_last_of(const char* s, unsigned long long index, unsigned long long n)const {
    unsigned long long N = n < strlen(s) ? n : strlen(s);
    for (unsigned long long i = (index < _size - 1 ? index : _size - 1); i >= 0; --i) {
        for (unsigned long long j = 0; j < N; j++) {
            if (_data[i] == s[j]) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find_last_of(const char* s, unsigned long long index)const {
    unsigned long long N = strlen(s);
    for (unsigned long long i = (index < _size - 1 ? index : _size - 1); i >= 0; --i) {
        for (unsigned long long j = 0; j < N; j++) {
            if (_data[i] == s[j]) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find_last_of(const Lstring& s, unsigned long long index)const {
    for (unsigned long long i = (index < _size - 1 ? index : _size - 1); i >= 0; --i) {
        for (unsigned long long j = 0; j < s._size; j++) {
            if (_data[i] == s._data[j]) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find_first_of(const Lstring& s, unsigned long long index)const {
    for (unsigned long long i = index; i < _size; ++i) {
        for (unsigned long long j = 0; j < s._size; j++) {
            if (_data[i] == s._data[j]) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find_first_of(const char* s, unsigned long long index, unsigned long long n)const {
    unsigned long long N = strlen(s) < n ? strlen(s) : n;
    for (unsigned long long i = index; i < _size; ++i) {
        for (unsigned long long j = 0; j < N; j++) {
            if (_data[i] == s[j]) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find_first_of(const char* s, unsigned long long index)const {
    unsigned long long N = strlen(s);
    for (unsigned long long i = index; i < _size; ++i) {
        for (unsigned long long j = 0; j < N; j++) {
            if (_data[i] == s[j]) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find_first_of(char A, unsigned long long index)const {
    for (unsigned long long i = index; i < _size; ++i) {
        if (_data[i] == A) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::rfind(char A, unsigned long long index)const {
    return rfind(Lstring(1, A), index);
}
unsigned long long Lstring::rfind(const char* s, unsigned long long index, unsigned long long n)const {
    return rfind(Lstring(s, n), index);
}
unsigned long long Lstring::rfind(const char* s, unsigned long long index)const {
    return rfind(Lstring(s), index);
}
unsigned long long Lstring::rfind(const Lstring& s, unsigned long long index)const {
    unsigned long long N = _size - 1 < index ? _size - 1 : index;
    for (unsigned long long i = N; i >= 0; i--) {
        if (s[i] == _data[i]) {
            bool find = true;
            for (unsigned long long j = i; j - i < s._size && j < _size; j++) {
                if (s[j] != _data[j]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                return i;
            }
        }
    }
    return npos;
}
unsigned long long Lstring::find(char A, unsigned long long index)const {
    for (unsigned long long i = index; i < _size; ++i) {
        if (_data[i] == A) {
            return i;
        }
    }
    return npos;
}
unsigned long long Lstring::find(const char* s, unsigned long long index, unsigned long long n)const {
    return find(Lstring(s, n), index);
}
unsigned long long Lstring::find(const char* s, unsigned long long index)const {
    return find(Lstring(s), index);
}
unsigned long long Lstring::find(const Lstring& s, unsigned long long index)const {
    for (unsigned long long i = index; i < _size; i++) {
        if (s[i] == _data[i]) {
            bool find = true;
            for (unsigned long long j = i; j - i < s._size && j < _size; j++) {
                if (s[j] != _data[j]) {
                    find = false;
                    break;
                }
            }
            if (find) {
                return i;
            }
        }
    }
    return npos;
}
Lstring& Lstring::replace(unsigned long long index, unsigned long long n, unsigned long long cn, char A) {
    return erase(index, n).insert(index, Lstring(cn, A));
}
Lstring& Lstring::replace(unsigned long long index, unsigned long long n, const char* s, unsigned long long sn) {
    return erase(index, n).insert(index, Lstring(s, sn));
}
Lstring& Lstring::replace(unsigned long long index, unsigned long long n, const char* s) {
    return erase(index, n).insert(index, Lstring(s));
}
Lstring& Lstring::replace(unsigned long long index, unsigned long long n, const Lstring& s, unsigned long long begin, unsigned long long sn) {
    return erase(index, n).insert(index, s.substr(begin, sn));
}
Lstring& Lstring::replace(unsigned long long index, unsigned long long n, const Lstring& s) {
    return erase(index, n).insert(index, s);
}
void Lstring::resize(unsigned long long n) {
    if (n <= _size) {
        _size = n;
        return;
    }
    else {
        append(n - _size, 0);
        return;
    }
}
void Lstring::resize(unsigned long long n, char A) {
    if (n <= _size) {
        _size = n;
        return;
    }
    else {
        append(n - _size, A);
        return;
    }
}
unsigned long long Lstring::copy(char* s, unsigned long long n, unsigned long long begin)const {
    for (unsigned long long i = begin; i < (begin + n < _size ? begin + n : _size); ++i) {
        s[i - begin] = _data[i];
    }
    return (begin + n < _size ? begin + n : _size) - begin;
}
Lstring& Lstring::operator+=(char A) {
    return append(1, A);
}
Lstring& Lstring::operator+=(const char* s) {
    return append(s);
}
Lstring& Lstring::operator+=(const Lstring& s) {
    return append(s);
}
Lstring& Lstring::append(unsigned long long n, char A) {
    return append(Lstring(n, A));
}
Lstring& Lstring::append(const char* s, unsigned long long n) {
    return append(Lstring(s, n));
}
Lstring& Lstring::append(const char* s) {
    return append(Lstring(s));
}
Lstring& Lstring::append(const Lstring& s, unsigned long long begin, unsigned long long n) {
    return append(s.substr(begin, n));
}
Lstring& Lstring::append(const Lstring& s) {
    return insert(_size, s);
}
Lstring& Lstring::pop_back() {
    --_size;
    return *this;
}
Lstring& Lstring::push_back(char A) {
    if (_size < _allsize) {
        _data[_size] = A;
        ++_size;
    }
    else {
        _allsize *= 2;
        char* box = new char[_allsize];
        for (unsigned long long i = 0; i != _size; ++i) {
            box[i] = _data[i];
        }
        box[_size] = A;
        delete[] _data;
        _data = box;
        ++_size;
    }
    return *this;
}
Lstring& Lstring::erase(unsigned long long index, unsigned long long n) {
    unsigned long long N = n < _size - index ? n : _size - index;
    for (unsigned long long i = index; i + N != _size; ++i) {
        _data[i] = _data[i + N];
    }
    _size -= N;
    return *this;
}
Lstring& Lstring::insert(unsigned long long index, unsigned long long n, char A) {
    return insert(index, Lstring(n, A));
}
Lstring& Lstring::insert(unsigned long long index, const char* s, unsigned long long n) {
    return insert(index, Lstring(s), 0, n);
}
Lstring& Lstring::insert(unsigned long long index, const Lstring& s, unsigned long long begin, unsigned long long n) {
    return insert(index, s.substr(begin, n));
}
Lstring& Lstring::insert(unsigned long long index, const Lstring& s) {
    if (_allsize < _size + s._size) {
        _allsize = _size + s._size + _Lstring_ADD_SIZE_;
        char* box = new char[_allsize];
        for (unsigned long long i = 0; i != index; i++) {
            box[i] = _data[i];
        }
        for (unsigned long long i = index; i != index + s._size; ++i) {
            box[i] = s._data[i - index];
        }
        for (unsigned long long i = index + s._size; i != _size + s._size; ++i) {
            box[i] = _data[i - s._size];
        }
        delete[] _data;
        _data = box;
        _size += s._size;
    }
    else {
        for (unsigned long long i = _size + s._size - 1; i != index - 1; --i) {
            _data[i] = _data[i - s._size];
        }
        for (unsigned long long i = index; i - index < s._size; ++i) {
            _data[i] = s._data[i - index];
        }
        _size += s._size;
    }
    return *this;
}
Lstring& Lstring::clear() {
    _size = 0;
    return *this;
}
void Lstring::shrink_to_fit() {
    char* box = new char[_size];
    for (unsigned long long i = 0; i != _size; ++i) {
        box[i] = _data[i];
    }
    delete[] _data;
    _data = box;
    _allsize = _size;
}
unsigned long long Lstring::capacity()const {
    return _allsize;
}
bool Lstring::reserve(unsigned long long newAllsize) {
    if (newAllsize >= _size) {
        char* box = new char[newAllsize];
        for (unsigned long long i = 0; i != _size; ++i) {
            box[i] = _data[i];
        }
        delete[] _data;
        _data = box;
        _allsize = newAllsize;
        return true;
    }
    else {
        return false;
    }
}
unsigned long long Lstring::max_size()const {
    return (unsigned long long)(-1);
}
unsigned long long Lstring::size()const {
    return _size;
}
unsigned long long Lstring::length()const {
    return _size;
}
bool Lstring::empty()const {
    return !_size;
}
Lstring Lstring::substr(unsigned long long begin, unsigned long long n)const {
    if (0 <= n + begin && n + begin < _size)//尾不超
        return Lstring(_data, begin, n);
    return Lstring(_data, begin, _size - begin);//尾超
}
const char* Lstring::c_str()const {
    return _data;
}
char* Lstring::data() {
    return _data;
}
const char* Lstring::data()const {
    return _data;
}
char& Lstring::back() {
    return _data[_size - 1];
}
char Lstring::back()const {
    return _data[_size - 1];
}
char& Lstring::front() {
    return *_data;
}
char Lstring::front()const {
    return *_data;
}
char& Lstring::operator[](unsigned long long index) {
    return _data[index];
}
char Lstring::operator[](unsigned long long index)const {
    return _data[index];
}
char& Lstring::at(unsigned long long index) {
    if (0 <= index && index < _size)
        return _data[index];
    if (index < 0)
        return _data[0];
    if (_size <= index)
        return _data[_size - 1];
}
char Lstring::at(unsigned long long index)const {
    if (0 <= index && index < _size)
        return _data[index];
    if (index < 0)
        return _data[0];
    if (_size <= index)
        return _data[_size - 1];
}
Lstring& Lstring::assign(unsigned long long n, char A) {
    Lstring temp(n, A);
    swap(temp);
    return *this;
}
Lstring& Lstring::assign(const char* s, unsigned long long begin, unsigned long long n) {
    Lstring temp(s, begin, n);
    swap(temp);
    return *this;
}
Lstring& Lstring::assign(const Lstring& a) {
    Lstring temp(a);
    swap(temp);
    return *this;
}
Lstring& Lstring::assign(const char* data, unsigned long long n) {
    Lstring temp(data, n);
    swap(temp);
    return *this;
}
Lstring& Lstring::assign(const char* data) {
    Lstring temp(data);
    swap(temp);
    return *this;
}
void Lstring::swap(Lstring& a) {
    ::swap(_data, a._data);
    ::swap(_size, a._size);
    ::swap(_allsize, a._allsize);
}
Lstring::Lstring(const Lstring& a) :_data(nullptr), _size(a._size), _allsize(a._allsize) {
    _data = new char[_allsize];
    for (unsigned long long i = 0; i != a._size; ++i) {
        _data[i] = a._data[i];
    }
}
Lstring& Lstring::operator=(const char* s) {
    Lstring temp(s);
    swap(temp);
    return *this;
}
Lstring& Lstring::operator=(const Lstring& a) {
    Lstring temp(a);
    swap(temp);
    return *this;
}
Lstring::~Lstring() {
    delete[] _data;
}
Lstring::Lstring(const char* data, unsigned long long n) :_data(nullptr), _size(n), _allsize(n + _Lstring_ADD_SIZE_) {
    _data = new char[_allsize];
    for (unsigned long long i = 0; i != n; ++i) {
        _data[i] = data[i];
    }
}
Lstring::Lstring(const char* data, unsigned long long begin, unsigned long long n) :_data(nullptr), _size(n), _allsize(n + _Lstring_ADD_SIZE_) {
    _data = new char[_allsize];
    for (unsigned long long i = begin; i != begin + n; ++i) {
        _data[i - begin] = data[i];
    }
}
Lstring::Lstring(unsigned long long size, char A) :_data(nullptr), _size(size), _allsize(0) {
    _allsize = _size + _Lstring_ADD_SIZE_;
    _data = new char[_allsize];
    for (unsigned long long i = 0; i < size; ++i) {
        _data[i] = A;
    }
}
Lstring::Lstring(const char* a) :_data(nullptr), _size(strlen(a)), _allsize(0) {
    _allsize = _size + _Lstring_ADD_SIZE_;
    _data = new char[_allsize];
    strcpy(_data, a);
}
Lstring::Lstring() : _data(nullptr), _size(0), _allsize(_Lstring_ADD_SIZE_) {
    _data = new char[_allsize];
}