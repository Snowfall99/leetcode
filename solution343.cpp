class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
