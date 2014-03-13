class Solution {
public:
    void nextPermutation(vector<int> &num) {
        const int len = num.size();
        int pos = -1;
        for (int i = len - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) {
                pos = i;
                break;
            }
        }
        if (pos != -1)
            for (int i = len - 1; i > pos; --i)
                if (num[i] > num[pos]) {
                    swap(num[i], num[pos]);
                    break;
                }
        reverse(num, pos + 1, len - 1);
    }
    
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void reverse(vector<int> &num, int begin, int end) {
        while (begin < end) {
            swap(num[begin], num[end]);
            ++begin;
            --end;
        }
    }
};