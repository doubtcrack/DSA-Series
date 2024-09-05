class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
    int totalSum = mean * (n + m);
    int currentSum = accumulate(rolls.begin(), rolls.end(), 0);
    int missingSum = totalSum - currentSum; 

    // If it's impossible to divide the missingSum among the n missing rolls with valid values (1-6)
    if (missingSum < n || missingSum > 6 * n) {
        return {};  // Return empty array indicating no solution
    }
    
    vector<int> result(n, missingSum / n); 
    int remainder = missingSum % n; 
    
    // Distribute the remainder by incrementing some of the rolls by 1
    for (int i = 0; i < remainder; ++i) {
        result[i]++;
    }
    
    return result;
    }
};