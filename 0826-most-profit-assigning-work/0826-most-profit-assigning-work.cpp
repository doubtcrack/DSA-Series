class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

// -------------- First Approach ------------------- //

        // int max_profit=0;
        // for(int i=0;i<worker.size();i++){
        //     int max_val = 0;
        //     for(int j=0;j<difficulty.size();j++){
        //     if(difficulty[j]<=worker[i]){
        //         max_val = max(max_val,profit[j]);
        //     }
        //     }
        //     max_profit += max_val;
        //     cout<< max_val <<" ";
        // }
        // return max_profit;

// -------------- Second Approach ---------------- // 
// ----- Time Complexity: O(nlogn+mlogm) ------- // 


    int n = difficulty.size();
    int m = worker.size();
    
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; ++i) {
        jobs[i] = {difficulty[i], profit[i]};
    }

    // Sort jobs based on difficulty
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());

    int maxProfit = 0, jobIndex = 0, bestProfit = 0;

    for (int i = 0; i < m; ++i) {
        while (jobIndex < n && jobs[jobIndex].first <= worker[i]) {
            bestProfit = max(bestProfit, jobs[jobIndex].second);
            ++jobIndex;
        }
        maxProfit += bestProfit;
    }
    
    return maxProfit;
    }
};