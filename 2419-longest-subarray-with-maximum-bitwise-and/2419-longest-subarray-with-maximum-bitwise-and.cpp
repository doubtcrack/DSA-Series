class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int maxAND = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            maxAND = max(maxAND, nums[i]);
        }
        
        int longest = 0, currentLength = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxAND) {
                currentLength++;
                longest = max(longest, currentLength);
            } else {
                currentLength = 0; 
            }
        }

        return longest;
    }
};