class Solution {
public:
    int strangePrinter(string s) {
         int n = s.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(n, n));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;  // Base case: printing a single character
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j-1];  // Combine the first and last character into one turn
                } else {
                    for (int k = i; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};