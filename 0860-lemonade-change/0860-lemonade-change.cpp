class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0,  count10=0;
        for(auto bill: bills){
            if (bill==5) count5++;
            else if(bill==10 && count5>0) {
                count5--;
                count10++;
            }
            else if(bill==10 && count5==0) return false;
            else if(bill==20 && (count5>0 || count10>0)) {
                if(count10>0 && count5>0){     
                    count5--;
                    count10--;
                }
                else if(count10==0 && count5>2) count5= count5-3;
                else return false;
            }
            else if(bill==20 && ((count5<3 && count10==0) || (count5==0))) return false;
        }
        return true;
    }
};