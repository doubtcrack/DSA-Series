class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
         // Step 1: Calculate the total chalk needed for one full round
        long long totalChalk = 0;
        for (int i = 0; i < chalk.size(); i++) {
            totalChalk += chalk[i];
        }

        // Step 2: Reduce k by the total chalk needed for full rounds
        k %= totalChalk;
cout<<k<<" ";
        // Step 3: Identify the student who will need to replace the chalk
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }

        // Just a fallback, although the loop should always return a value
        return -1;
    }
};