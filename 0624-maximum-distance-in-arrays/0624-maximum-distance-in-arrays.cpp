class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

    int min_val = arrays[0][0];
    int max_val = arrays[0].back();
    int answer = 0;

    for (int i = 1; i < arrays.size(); i++) {
        answer = max(answer, abs(arrays[i].back() - min_val));
        answer = max(answer, abs(max_val - arrays[i][0]));

        min_val = min(min_val, arrays[i][0]);
        max_val = max(max_val, arrays[i].back());
    }

    return answer;
    }
};