class Solution {
public:
 void findCombinations(int index, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>& current) {
        // If the target becomes 0, we've found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i-1]) continue;
            
            // If the current candidate exceeds the target, break
            if (candidates[i] > target) break;
            
            // Include the current candidate in the combination
            current.push_back(candidates[i]);
            
            // Recursively call for the next elements
            findCombinations(i + 1, target - candidates[i], candidates, result, current);
            
            // Backtrack: remove the last added element
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sort the candidates to handle duplicates and to optimize
        sort(candidates.begin(), candidates.end());
        
        // Call the backtracking function
        findCombinations(0, target, candidates, result, current);
        
        return result;
    }
};