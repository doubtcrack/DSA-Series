class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

 //-------------- Method 1 (O(nlogn))---------------------//

    // int res = 0;
    // sort(nums.begin(), nums.end());
    // for (int i = 1; i < nums.size(); i++) {  
    //     if (nums[i] <= nums[i - 1]) { 
    //         int increment = nums[i - 1] + 1 - nums[i];  
    //         res += increment;  
    //         nums[i] = nums[i - 1] + 1;  
    //     }
    // }
    // return res;


    // -----------------Method 2 (O(n)) ------------------//

    if (nums.empty()) return 0;

    unordered_map<int, int> count;
    int max_val = 0;
    for (int num : nums) {
        count[num]++;
        if (num > max_val) {
            max_val = num;
        }
    }
    // count: {
    // 0:0
    // 1:2
    // 2:2
    // 3:1
    // 4:0
    // 5:0
    // 6:0
    // 7:1
    // }

    int res = 0, remaining_duplicates = 0;
    for (int i = 0; i <= max_val || remaining_duplicates > 0; ++i) {
        if (count[i] > 1) {
            remaining_duplicates += count[i] - 1;
            res -= i * (count[i] - 1);
        } 
        else if (remaining_duplicates > 0 && count[i] == 0) {
            remaining_duplicates--;
            res += i;
        }
    }
    return res;
}   
};