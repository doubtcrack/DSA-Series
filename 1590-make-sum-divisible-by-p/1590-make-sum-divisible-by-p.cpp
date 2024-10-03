class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;
        
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum % p;
        if (target == 0) return 0; 
        
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1; 
        long long prefixSum = 0;
        int minLength = n;
        
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int mod = prefixSum % p;
            
            int neededMod = (mod - target + p) % p;
            
            if (prefixModMap.find(neededMod) != prefixModMap.end()) {
                minLength = min(minLength, i - prefixModMap[neededMod]);
            }
            
            prefixModMap[mod] = i;
        }
        
        return minLength == n ? -1 : minLength;
    }
};
