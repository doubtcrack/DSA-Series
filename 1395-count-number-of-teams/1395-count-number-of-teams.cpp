class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
    int teams = 0;

    for (int j = 0; j < n; ++j) {
        int less_before = 0, greater_before = 0;
        int less_after = 0, greater_after = 0;

        for (int i = 0; i < j; ++i) {
            if (rating[i] < rating[j]) ++less_before;
            if (rating[i] > rating[j]) ++greater_before;
        }

        for (int k = j + 1; k < n; ++k) {
            if (rating[k] > rating[j]) ++greater_after;
            if (rating[k] < rating[j]) ++less_after;
        }

        teams += less_before * greater_after + greater_before * less_after;
    }

    return teams;
    }
};