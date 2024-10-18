class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
     int maxOr = 0, n = nums.size();
        
        for (int num : nums) {
            maxOr |= num;
        }
        
        int count = 0;
        int totalSubsets = 1 << n; // 2^n possible subsets

        for (int i = 1; i < totalSubsets; ++i) { 
            int currentOr = 0;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentOr |= nums[j];
                }
            }

            if (currentOr == maxOr) {
                count++;
            }
        }
        
        return count;
}
};