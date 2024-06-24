class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> is_flipped(n, 0);
        int flip_count = 0, flip_effect = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flip_effect ^= is_flipped[i - k];
            }

                cout<<flip_effect<<" ";
            if (flip_effect == nums[i]) {
                if (i + k > n) return -1;
                flip_effect ^= 1;
                is_flipped[i] = 1;
                flip_count++;
            }
        }
        cout<<"\n";
        for (int i = 0; i < n; ++i) {
            cout<<is_flipped[i]<<" ";
        }

        return flip_count;
    }
};