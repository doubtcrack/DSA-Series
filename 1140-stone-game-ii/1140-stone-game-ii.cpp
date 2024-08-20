class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> suffixSum(n + 1, 0);

        // Compute the suffix sums
        for (int i = n - 1; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                    dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                }
            }
        }

        // Result is the maximum stones Alice can collect starting from the first pile with M = 1
        return dp[0][1];
    }
};