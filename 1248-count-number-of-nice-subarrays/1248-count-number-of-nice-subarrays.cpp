class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1; 
        
        int current_prefix_sum = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                current_prefix_sum++;
            }
            cout<<current_prefix_sum<<" ";
     // If we have seen the current_prefix_sum - k before, it means
    // there exists a subarray ending here with exactly k odd numbers
            if (prefix_counts.find(current_prefix_sum - k) != prefix_counts.end()) {
                result += prefix_counts[current_prefix_sum - k];
            }
            prefix_counts[current_prefix_sum]++;
        }

        return result;
    }
};