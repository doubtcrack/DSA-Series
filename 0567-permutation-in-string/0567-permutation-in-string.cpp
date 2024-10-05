class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false; 

        vector<int> freqS1(26, 0), freqS2(26, 0);

        for (int i = 0; i < n1; ++i) {
            freqS1[s1[i] - 'a']++;
            freqS2[s2[i] - 'a']++;
        }

        if (freqS1 == freqS2) return true;

        for (int i = n1; i < n2; ++i) {
            freqS2[s2[i] - 'a']++;
            freqS2[s2[i - n1] - 'a']--;
            
            if (freqS1 == freqS2) return true;
        }

        return false;
    }
};