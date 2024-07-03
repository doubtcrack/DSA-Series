class Solution {
public:
    int minDifference(vector<int>& nums) {
    int n = nums.size();
    if (n <= 4) return 0; 
    
    sort(nums.begin(), nums.end());
    
    for(auto val:nums) cout<<val<<" ";
    cout<<"\n\n";
    int minDiff = INT_MAX;
    for (int i = 0; i <= 3; ++i) {
        minDiff = min(minDiff, nums[n - 4 + i] - nums[i]);
        cout<<minDiff<<" ";
    }
    
    return minDiff;
    }
};