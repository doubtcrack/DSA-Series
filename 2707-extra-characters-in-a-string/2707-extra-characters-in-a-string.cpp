class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());  // Store dictionary for O(1) lookup
        vector<int> dp(n + 1, INT_MAX);  // DP array to store the minimum extra characters
        dp[0] = 0;  // No extra characters when the string is empty
        
        // Iterate through all indices of the string
        for (int i = 1; i <= n; ++i) {
            // Assume initially that the entire substring s[0:i] is extra characters
            dp[i] = dp[i - 1] + 1;  
            
            // Try to find a substring that matches any word in the dictionary
            for (int j = i; j > 0; --j) {
                string subStr = s.substr(j - 1, i - (j - 1));  // s[j-1:i]
                if (dict.find(subStr) != dict.end()) {
                    dp[i] = min(dp[i], dp[j - 1]);  // No extra characters if we found a valid substring
                }
            }
        }
        
        return dp[n];  // The result is the minimum extra characters for the entire string
    }
};