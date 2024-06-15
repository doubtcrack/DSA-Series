class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n = profits.size();
    
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; ++i) {
        projects[i] = {capital[i], profits[i]};
    }
    
    sort(projects.begin(), projects.end());
    
    int currentCapital = w;
    for (int i = 0; i < k; ++i) {
        int maxProfit = 0;
        int index = -1;
        
        for (int j = 0; j < n; ++j) {
            if (projects[j].first <= currentCapital) {
                if (projects[j].second > maxProfit) {
                    maxProfit = projects[j].second;
                    index = j;
                }
            } else break;
        }
         if (index == -1) {
            break;
        }
        
        currentCapital += projects[index].second;
        projects[index].second = -1; 
    }
    
    return currentCapital;
    }
};