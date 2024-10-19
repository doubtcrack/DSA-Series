class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> lengths(n + 1);
        lengths[1] = 1; 
        
        for (int i = 2; i <= n; ++i) {
            lengths[i] = 2 * lengths[i - 1] + 1;
        }
        
        return findKthBitHelper(n, k, lengths);
    }
    
private:
    char findKthBitHelper(int n, int k, const vector<int>& lengths) {
        if (n == 1) {
            return '0';
        }

        int mid = lengths[n - 1] + 1;

        if (k == mid) {
            return '1';
        } else if (k < mid) {
            return findKthBitHelper(n - 1, k, lengths);
        } else {
            int newK = lengths[n] - k + 1; 
            char bit = findKthBitHelper(n - 1, newK, lengths);
            return bit == '0' ? '1' : '0';
        }
    }
};
