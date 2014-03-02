class Solution {
public:
    int reverse(int x) {
        bool isNegative = (x < 0);
        if (isNegative) x = -x;
        int ans = 0;
        while (x) {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return isNegative? -ans : ans;
    }
};