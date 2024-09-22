class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;  
        k--;  
        while (k > 0) {
            long long steps = countSteps(n, current, current + 1);
            if (steps <= k) {
                current += 1;
                k -= steps; 
            } else {
                current *= 10; 
                k -= 1; 
            }
        }

        return current;
    }

private:
    long long countSteps(int n, long long prefix, long long nextPrefix) {
        long long steps = 0;
        while (prefix <= n) {
            steps += min((long long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }
};
