class Solution {
public:
    bool judgeSquareSum(int c) {
// ---------------- Approach 1 ------------------- //
        vector<long> sq;
        for(long i=0;i*i<=c;i++) sq.push_back(i*i);
        int n = sq.size();
        int i=0, j=n-1;
        while(i<=j) {
            if(sq[i]+sq[j]==c) return true;
            else if (sq[i]+sq[j]> c) j--;
            else if (sq[i]+sq[j]<c) i++;
        }

// ---------------- Approach 2 ------------------- //

        // for (long a = 0; a * a <= c; ++a) {
        // long b2 = c - a * a;
        // long b = sqrt(b2);
        //     if (b * b == b2) {
        //         return true;
        //     }
        // }
        return false;
    }
};