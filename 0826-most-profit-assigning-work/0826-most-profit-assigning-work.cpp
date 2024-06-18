class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int max_profit=0;
        for(int i=0;i<worker.size();i++){
            int max_val = 0;
            for(int j=0;j<difficulty.size();j++){
            if(difficulty[j]<=worker[i]){
                max_val = max(max_val,profit[j]);
            }
            }
            max_profit += max_val;
            cout<< max_val <<" ";
        }
        return max_profit;
    }
};