class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int n = customers.size();
        int baseline_satisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                baseline_satisfied += customers[i];
            }
        }
        int max_additional_satisfied = 0;
        int current_window_satisfied = 0;

        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                current_window_satisfied += customers[i];
            }
        }

        max_additional_satisfied = current_window_satisfied;

        for (int i = minutes; i < n; ++i) {
            if (grumpy[i - minutes] == 1) {
                current_window_satisfied -= customers[i - minutes];
            }
            if (grumpy[i] == 1) {
                current_window_satisfied += customers[i];
            }

            max_additional_satisfied = max(max_additional_satisfied, current_window_satisfied);
        }

        return baseline_satisfied + max_additional_satisfied;
    }
};