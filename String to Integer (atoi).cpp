#include <cstring>
#include <cctype>
#include <climit>
class Solution {
public:
    int atoi(const char *str) {
        int begin = 0;
        bool isNegative = false;
        
        while (str[begin] != '\0' && str[begin] == ' ') ++begin; //ignore the leading whitespaces
        
        if (str[begin] == '\0') return 0; //str is all whitespaces, answer is zero
        if (str[begin] == '+') ++begin;
        if (str[begin] == '-') isNegative = true, ++begin;
        if (!isdigit(str[begin])) return 0; //not a valid number
        
        long long ans = 0, len = strlen(str);
        int end = begin;
        for (int i = begin; i < len; ++i) {
            if (!isdigit(str[i])) break;
            end = i;
        }
        long long mutiply = 1;
        for (int i = end; i >= begin; --i, mutiply *= 10) {
            ans += mutiply * (str[i] - '0');
        }
        if (isNegative) ans = -ans;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
    
};