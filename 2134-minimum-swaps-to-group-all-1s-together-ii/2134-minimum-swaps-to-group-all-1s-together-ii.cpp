class Solution {
public:
    int minSwaps(vector<int>& nums) {
    int totalOnes = 0;
    int n = nums.size();

    for (int num : nums) {
        if (num == 1) totalOnes++;
    }

    if (totalOnes == 0) return 0; 

    // Extend the array to handle circular nature
    vector<int> extendedNums = nums;
    extendedNums.insert(extendedNums.end(), nums.begin(), nums.end());

    // Sliding window to find the maximum number of 1's in any window of size totalOnes
    int maxOnesInWindow = 0, currentOnes = 0;

    // Initial window
    for (int i = 0; i < totalOnes; ++i) {
        if (extendedNums[i] == 1) {
            currentOnes++;
        }
    }
    maxOnesInWindow = currentOnes;

    // Slide the window
    for (int i = totalOnes; i < 2 * n; ++i) {
        if (extendedNums[i] == 1) {
            currentOnes++;
        }
        if (extendedNums[i - totalOnes] == 1) {
            currentOnes--;
        }
        maxOnesInWindow = max(maxOnesInWindow, currentOnes);
    }

    // Minimum swaps needed is the window size minus the maximum number of 1's in any window
    return totalOnes - maxOnesInWindow;
    }
};