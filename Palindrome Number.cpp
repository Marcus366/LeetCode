class Solution {
public:
    bool isPalindrome(int x) {
        return x >= 0 && x == reverse(x);
    }
    
    long long reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};