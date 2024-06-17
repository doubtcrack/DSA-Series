class Solution {
public:
    bool judgeSquareSum(int c) {
        // vector<int> sq;
        // for(int i=0;i<=c/2;i++) sq.push_back(i*i);
        // int n = sq.size();
        // int i=0, j=n-1;
        // while(i<j) {
        //     if(sq[i]+sq[j]==c) return true;
        //     else if (sq[i]+sq[j]> c) j--;
        //     else if (sq[i]+sq[j]<c) i++;
        // }

        for (long a = 0; a * a <= c; ++a) {
        long b2 = c - a * a;
        long b = sqrt(b2);
        if (b * b == b2) {
            return true;
        }
    }
        return false;
    }
};