class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end());
    int n = skill.size();
    
    int targetSum = skill[0] + skill[n - 1];
    long long totalChemistry = skill[0] * skill[n - 1];
    
    for (int i = 1; i < n / 2; ++i) {
        int pairedSum = skill[i] + skill[n - i - 1];
        cout<<pairedSum<<" "; 
        if (pairedSum != targetSum) {
            return -1;
        }
        totalChemistry += (long long)skill[i] * skill[n - i - 1];
    }
    
    return totalChemistry;
    }
};