class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        int maxWidth = 0;
        
        // Step 1: Build the monotonic decreasing stack
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);  // Only push when the current value is smaller than the stack's top
            }
        }
        
        // Step 2: Iterate from the end of the array and calculate the maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.top());  // Update the max width ramp
                s.pop();  // Pop the index as we found a valid ramp
            }
        }
        
        return maxWidth;
    }
};