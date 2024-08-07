/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        int index = 0;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = current->next;

        while (next != nullptr) {
            if (prev != nullptr) {
                if ((current->val > prev->val && current->val > next->val) ||
                    (current->val < prev->val && current->val < next->val)) {
                    criticalPoints.push_back(index);
                }
            }
            prev = current;
            current = next;
            next = next->next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};
