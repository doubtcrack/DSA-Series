class Solution {
public:
bool canPlaceBalls(vector<int>& position, int m, int minForce) {
    cout<<"\n"<< minForce<<" ";
        int count = 1;
        int last_position = position[0];

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last_position >= minForce) {
                count++;
                cout<< count<<" "<<i<<": ";
                last_position = position[i];
                if (count == m) {
                    return true;
                }
            }
        }
        
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int left = 1;
        int right = position.back() - position.front();
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceBalls(position, m, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
};