class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long score = 0;
        for (int i = 0; i < k; ++i) {
            int top = maxHeap.top(); 
            maxHeap.pop();
            
            score += top; 
            int newValue = ceil(top / 3.0);
            
            maxHeap.push(newValue);  
        }

        return score; 
    }
};