class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double sum = 0, time = 0;
        for(auto customer:customers){
            if(customer[0] > time){
                time = customer[0] + customer[1];
            }else if(customer[0] <= time){
                time += customer[1] ;
            }

                sum+=time-customer[0];
        }

        return sum/n;
    }
};