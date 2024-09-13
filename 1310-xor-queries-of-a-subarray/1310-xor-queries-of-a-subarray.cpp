class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
        for(auto query : queries){
            int res=0;
            for(int i=query[0];i<=query[1];i++){
                res ^= arr[i];
            }
            answer.push_back(res);
        }

        return answer;
    }
};