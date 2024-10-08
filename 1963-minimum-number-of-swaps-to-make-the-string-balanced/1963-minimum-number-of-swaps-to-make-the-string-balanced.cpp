class Solution {
public:
    int minSwaps(string s) {
        int imbalance = 0, swaps = 0; 

        for (char c : s) {
            c == '[' ? imbalance++ : imbalance--;
            if (imbalance < 0) {
                swaps++;      // We need a swap to fix this mismatch
                imbalance = 1; // Reset balance to account for the "simulated" fix by swap
            }
        }

        return swaps;
    }
};