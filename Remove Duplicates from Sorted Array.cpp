class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (!count || A[i] != A[i-1])
                A[count++] = A[i];
        return count;
    }
};