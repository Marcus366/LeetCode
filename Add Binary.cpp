#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length(), len2 = b.length();
        if (len1 < len2) a = string(len2 - len1, '0') + a;
        if (len2 < len1) b = string(len1 - len2, '0') + b;
        int len = max(len1, len2);
        string ans(len, '0');
        int carry = 0;
        for (int i = len - 1; i >= 0; --i) {
            int x = a[i] - '0', y = b[i] - '0';
            int temp = x + y + carry;
            carry = 0;
            if (temp > 1) {
                temp -= 2;
                carry = 1;
            }
            ans[i] = temp + '0';
        }
        if (carry) {
            ans = '1' + ans;
        }
        return ans;
    }
};