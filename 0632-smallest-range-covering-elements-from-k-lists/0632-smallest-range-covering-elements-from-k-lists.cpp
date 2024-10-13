class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store the current smallest element from each list
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        
        int currentMax = INT_MIN;  // Track the current maximum value in the heap
        int start = 0, end = INT_MAX;  // Initialize the range [a, b]
        
        // Step 1: Insert the first element of each list into the min-heap
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], {i, 0}});
            currentMax = max(currentMax, nums[i][0]);  // Update currentMax
        }
        
        // Step 2: Process the heap until one of the lists is exhausted
        while (true) {
            auto [minValue, indices] = minHeap.top();
            minHeap.pop();
            
            int listIndex = indices.first;
            int elementIndex = indices.second;
            
            // Update the best range if the current range is smaller
            if (currentMax - minValue < end - start) {
                start = minValue;
                end = currentMax;
            }
            
            // If we have exhausted the current list, break the loop
            if (elementIndex + 1 >= nums[listIndex].size()) {
                break;
            }
            
            // Add the next element from the same list into the heap
            int nextValue = nums[listIndex][elementIndex + 1];
            minHeap.push({nextValue, {listIndex, elementIndex + 1}});
            currentMax = max(currentMax, nextValue);  // Update currentMax
        }
        
        return {start, end};
    }
};
