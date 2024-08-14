class Solution {
public:
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < nums.size() && nums[j] - nums[i] <= mid) {
                j++;
            }
            count += (j - i - 1);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countPairs(nums, mid);
            cout<<count<<" ";
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }


// ---------------- Brute Force Approach ---------------- //

    // int smallestDistancePair(vector<int>& nums, int k) {
    // sort(nums.begin(), nums.end());  
    // priority_queue<int, vector<int>, greater<int>> minHeap;  

    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         int distance = nums[j] - nums[i];
    //         minHeap.push(distance);
    //     }
    // }

    // for (int i = 0; i < k - 1; i++) {
    //     minHeap.pop();
    // }

    // return minHeap.top();
// }
};