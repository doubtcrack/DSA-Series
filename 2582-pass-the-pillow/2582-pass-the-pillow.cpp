class Solution {
public:
    int passThePillow(int n, int time) {
        time = time % ((n-1)*2);
        if(time >= n){
            time = time % (n-1);
            return n - time;
        }
        return time+1;
    }
};