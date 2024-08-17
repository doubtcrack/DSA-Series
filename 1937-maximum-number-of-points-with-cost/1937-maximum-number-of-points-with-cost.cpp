class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    vector<long long> dp(n, 0);

    // Initialize the first row
    for (int c = 0; c < n; ++c) {
        dp[c] = points[0][c];
    }

    // Process each row
    for (int r = 1; r < m; ++r) {
        vector<long long> new_dp(n, 0);

        // Left-to-right pass
        long long left_max = dp[0];
        for (int c = 0; c < n; ++c) {
            left_max = max(left_max, dp[c] + c);
            new_dp[c] = max(new_dp[c], points[r][c] + left_max - c);
        }

        // Right-to-left pass
        long long right_max = dp[n - 1] - (n - 1);
        for (int c = n - 1; c >= 0; --c) {
            right_max = max(right_max, dp[c] - c);
            new_dp[c] = max(new_dp[c], points[r][c] + right_max + c);
        }

        dp = move(new_dp);
    }

    // The answer is the maximum value in the last row
    return *max_element(dp.begin(), dp.end());
    }
};