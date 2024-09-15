class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> maskIndex;
        maskIndex[0] = -1; 
        
        int mask = 0;  
        int maxLength = 0;  

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                mask ^= (1 << 0); 
            } else if (s[i] == 'e') {
                mask ^= (1 << 1);  
            } else if (s[i] == 'i') {
                mask ^= (1 << 2); 
            } else if (s[i] == 'o') {
                mask ^= (1 << 3); 
            } else if (s[i] == 'u') {
                mask ^= (1 << 4);  
            }
            cout<<mask<<" ";

            if (maskIndex.find(mask) != maskIndex.end()) {
                maxLength = max(maxLength, i - maskIndex[mask]);
            } else {
                maskIndex[mask] = i;
            }
        }

        return maxLength;
    }
};