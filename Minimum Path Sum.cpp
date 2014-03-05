#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp = new int* [m];
        for (int i = 0; i < m; ++i)
            dp[i] = new int[n];
        dp[m-1][n-1] = grid[m-1][n-1];
        for (int i = m - 1; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                dp[i][j] = dp[i][j+1] + grid[i][j];
        for (int j = n - 1; j >= 0; --j)
            for (int i = m - 2; i >= 0; --i)
                dp[i][j] = dp[i+1][j] + grid[i][j];
        for (int i = m - 2; i >= 0; --i)
            for (int j = n - 2; j >= 0; --j)
                dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
        return dp[0][0];
    }
    
    int **dp;
};