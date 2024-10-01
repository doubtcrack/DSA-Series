class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderFreq(k, 0);

        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // Handle negative remainders
            remainderFreq[remainder]++;
        }

        if (remainderFreq[0] % 2 != 0) {
            return false;
        }

        for (int i = 1; i < k; i++) {
            if (remainderFreq[i] != remainderFreq[k - i]) {
                return false;
            }
        }

        return true;
    }
};

// Example:
// Input: arr = [1, 2, 3, 4, 5, 10, 6, 7, 8, 9], k = 5
// Output: true

// Remainders when divided by 5: [1, 2, 3, 4, 0, 0, 1, 2, 3, 4]
// Count of remainders: [2, 2, 2, 2, 2] (there are two 0s, two 1s, two 2s, etc.)
// The pairs are: (0,0), (1,4), (2,3), so the result is true.
