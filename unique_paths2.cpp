nt uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                if (i == 0 && j == 0)   dp[i + 1][j + 1] = 1;
                dp[i + 1][j + 1] += dp[i][j + 1] + dp[i + 1][j];
            }
        }
        
        return dp[m][n];
    }
