class Solution {
public:
    const unsigned int M = 1000000007;

int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<unsigned int> resarr;
    
    // Generate all possible subarray sums using a more efficient approach
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            resarr.push_back(sum);
        }
    }
    
    // Sort the subarray sums
    sort(resarr.begin(), resarr.end());
    
    // Calculate the sum from index left to right (1-based indexing)
    unsigned int result = 0;
    for (int i = left - 1; i < right; ++i) {
        result = (result + resarr[i]) % M;
    }

    return result;
}
};