class Solution {
public:
    int maximumGain(string s, int x, int y) {
    int totalPoints = 0;

    auto removeSubstring = [&](char first, char second, int points) -> int {
        int score = 0;
        int j = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            s[j++] = s[i];
            if (j > 1 && s[j - 2] == first && s[j - 1] == second) {
                j -= 2;
                score += points;
            }
        }

        s.resize(j);
        return score;
    };

    if (x >= y) {
        totalPoints += removeSubstring('a', 'b', x);
        totalPoints += removeSubstring('b', 'a', y);
    } else {
        totalPoints += removeSubstring('b', 'a', y);
        totalPoints += removeSubstring('a', 'b', x);
    }


    return totalPoints;
    }
};