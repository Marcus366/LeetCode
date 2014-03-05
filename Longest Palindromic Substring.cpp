class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxLen = 0;
        string maxStr;
        for (int i = 0; i < len; ++i) {
            int j = 0;
            while (i - j >= 0 && i + j < len && s[i-j] == s[i+j]) ++j;
            if (maxLen < 2 * j - 1) {
                maxLen = 2 * j - 1;
                maxStr = s.substr(i - j + 1, maxLen);
            }
            
            j = 1;
            while (i - j + 1 >= 0 && i + j < len && s[i-j+1] == s[i+j]) ++j;
            if (maxLen < 2 * j - 2) {
                maxLen = 2 * j - 2;
                maxStr = s.substr(i - j + 2, maxLen);
            }
        }
        return maxStr;
    }
};