#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool canMakeBouquets(const vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        
        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if ((long long)m * k > n) {
            return -1;
        }
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
