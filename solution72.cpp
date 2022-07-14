class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < n + 1; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int leftDown = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(dp[i - 1][j] + 1, min(leftDown, dp[i][j - 1] + 1));
            }
        }
        return dp[m][n];
    }
};
