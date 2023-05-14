class Solution {
public:
    int max_move = 0;
    
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int c = n - 2; c >= 0; c --) {
            for (int r = 0; r < m; r ++) {
                if(r - 1 >= 0 && grid[r][c] < grid[r-1][c+1])  { 
                    dp[r][c] = max(dp[r][c], 1 + dp[r-1][c+1]); 
                }
                if( grid[r][c] < grid[r][c+1]) { 
                    dp[r][c] = max(dp[r][c], 1 + dp[r][c+1]); 
                }
                if(r + 1 < m && grid[r][c] < grid[r+1][c+1]) { 
                    dp[r][c] = max(dp[r][c], 1 + dp[r+1][c+1]); 
                }
                if(c == 0) { ans = max(ans, dp[r][c]);  }
            }
        }
        return ans;
    }
};
