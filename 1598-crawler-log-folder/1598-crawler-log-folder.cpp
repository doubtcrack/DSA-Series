class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count =0 ;
        for(auto val:logs){
            if(val == "../" && count<=0) continue;
            else if(val == "../" && count>0) count--;
            else if(val == "./") continue;
            else count++;

            cout<<count<<" ";
        }
        if(count > 0) return count;
        return 0;
    }
};